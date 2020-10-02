open System

type PQ<'a when 'a :> System.IComparable> =
    | Node of PQ<'a> * 'a * PQ<'a> * Comparison<'a> * int
    | Leaf of Comparison<'a>

let empty (comp : Comparison<'a>) =
    Leaf comp

let size (pq : PQ<'a>) =
    match pq with
    | Leaf _ -> 0
    | Node (_, _, _, _, size) -> size

let rec push (v : 'a) (pq : PQ<'a>) =
    match pq with 
    | Leaf comp -> Node ((Leaf comp), v, (empty comp), comp, 1)
    | Node(left, value, right, comp, sz) when v < value -> 
        push value (Node(left, v, right, comp, sz))
    | Node(left, value, right, comp, sz) -> 
        let sides = 
            if (size right) < (size left) then
                (left, (push v right))
            else
                ((push v left), right)
        Node(fst sides, value, snd sides, comp, sz+1)    

let peek (pq : PQ<'a>) : 'a option =
    match pq with
    | Leaf comp -> None
    | Node (_, v, _, _, _) -> Some(v)

let rec sink (pq : PQ<'a>) =
    match pq with 
    | Leaf _ -> Leaf
    | Node(left, value, right, comp, sz) when value < peek left && value < peek right


let pop (pq : PQ<'a>) :  =
    _pop 


[<EntryPoint>]
let main argv =

    printfn "Hello World from F#!"
    0 // return an integer exit code
