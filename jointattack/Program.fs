// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let n = Console.ReadLine() |> int
    let lines = Console.ReadLine().Split(" ")
                |> Seq.map int64
                |> Seq.toList
                |> List.rev
    let (a,b) = lines 
                |> List.skip 1
                |> List.fold
                    (fun (a,b) x  -> 
                        //printfn "%d (%d, %d)" x a b
                        (x * a + b, a)
                    ) (lines.Head,1L)
    printfn "%d/%d" a b
    0 // return an integer exit code
