// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let before = Console.ReadLine()
    let after = Console.ReadLine()
    let rec findLength f l i = 
        if (List.isEmpty f) || (List.isEmpty l) then
            i
        else         
            if List.head f <> List.head l then
                i
            else        
                findLength f.Tail l.Tail (i+1)
                
    let start = findLength (List.ofSeq before) (List.ofSeq after) 0
    let beforeStartRemoved = before.Substring(start) |> Seq.rev |> String.Concat
    let afterStartRemoved = after.Substring(start) |> Seq.rev |> String.Concat
    let endIndex = findLength (List.ofSeq beforeStartRemoved) (List.ofSeq afterStartRemoved) 0
    let beforeDone = beforeStartRemoved.Substring(endIndex) |> Seq.rev |> String.Concat
    let afterDone = afterStartRemoved.Substring(endIndex) |> Seq.rev |> String.Concat
    (* 
    printfn "%s" (before)
    printfn "%s" (after)
    printfn "%s" (beforeStartRemoved|> Seq.rev |> String.Concat)
    printfn "%s" (afterStartRemoved|> Seq.rev |> String.Concat)
    printfn "%s" (beforeDone)
    printfn "%s" (afterDone)
    *)
    printfn "%i" (String.length afterDone)
    0 // return an integer exit code
