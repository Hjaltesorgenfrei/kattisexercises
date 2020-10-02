// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let nm = Console.ReadLine().Split(" ")
                |> Seq.map int
                |> Seq.toList
    let n = nm.[0]
    let m = nm.[1]              
    let fish = Console.ReadLine().Split(" ")
                |> Seq.map int64
                |> Seq.sortDescending
    let mongers = Seq.init m (fun _ -> 
                                let s = Console.ReadLine().Split(" ")
                                        |> Seq.map int64
                                        |> Seq.toList
                                Seq.replicate (int s.[0]) s.[1]
                              ) 
                  |> Seq.concat
                  |> Seq.sortDescending
    let sum = Seq.zip fish mongers
              |> Seq.sumBy (fun s -> fst s * snd s)
    printfn "%d" sum        
    0 // return an integer exit code

// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let nm = Console.ReadLine().Split(" ")
                |> Seq.map int
                |> Seq.toList
    let n = nm.[0]
    let m = nm.[1]              
    let fish = Console.ReadLine().Split(" ")
                |> Seq.map int64
                |> Seq.sortDescending
    let fishcount = fish |> Seq.length            
    let mongers = Seq.init m (fun _ -> 
                                let s = Console.ReadLine().Split(" ")
                                        |> Seq.map int64
                                        |> Seq.toList
                                (s.[0], s.[1])                          
                              ) 
                  |> Seq.sortByDescending snd
    let sum = Seq.zip fish (mongers |> Seq.collect (fun s -> Seq.replicate (int (fst s)) (snd s)))
              |> Seq.sumBy (fun s -> fst s * snd s)
    printfn "%d" sum        
    0 // return an integer exit code
