// Learn more about F# at http://fsharp.org

open System

let maxFirst a b =
    if (fst a) > (fst b) then
        a
    else 
        b

let mutable m = Map.empty

let rec numMoves n s  =
    let dyn l =
        match Map.tryFind l m with
        | Some k -> k
        | None -> 
            let temp = (numMoves (n+1) l)
            m <- Map.add l temp m
            temp 
    let rec mapper s xs = 
        match s with
        | true::true::false::rest -> 
            let k1 = dyn (List.rev xs @ false::false::true::rest)
            let k2 = (mapper (true::false::rest) (true::xs))
            maxFirst k1 k2
        | false::true::true::rest -> 
            let k1 = dyn (List.rev xs @ true::false::false::rest)
            let k2 = (mapper (true::true::rest) (false::xs))
            maxFirst k1 k2
        | x::rest -> mapper rest (x::xs)
        | [] -> (n, xs)
    mapper s []

let count s =
    Seq.fold (fun st v -> if v then st + 1 else st) 0 (snd s)

[<EntryPoint>]
let main argv =
    let n = int(Console.ReadLine())
    Seq.init n (fun _ -> Console.ReadLine()) 
    |> Seq.map(fun s -> (Seq.map (fun c -> c = 'o' ) >> List.ofSeq >> numMoves 0) s)
    |> Seq.iter (fun i -> printfn "%i" (count i))
    0

    //