open System

[<EntryPoint>]
let main argv =
    let n::m::k::xs = (Console.ReadLine().Split(" ") |> List.ofArray |> List.map int)
    let readBookValue 
        = Seq.init n (fun i -> Console.ReadLine().Split("\"")) 
        |> Seq.filter (fun s -> s.[1] < "Jane Eyre")
        |> Seq.sumBy (fun s -> int64 s.[2])
                 
    let afterBooks = 
        Seq.init m (fun i -> Console.ReadLine().Split("\"")) 
        |> Seq.filter (fun s -> s.[1] < "Jane Eyre")
        |> Seq.map (fun s -> ((int64 s.[0]), (int64 s.[2])))
        |> Seq.sortBy fst
        |> List.ofSeq
    

    let rec calc books valueAcc =
        match books with
        | x::xs when (fst x) <= valueAcc -> calc xs (valueAcc + (snd x))
        | _ -> valueAcc

    printfn "%i" ((calc afterBooks readBookValue)+(int64)k)
    0 // return an integer exit code
