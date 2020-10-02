// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let n::m::_ = Console.ReadLine().Split(" ")
                |> Seq.map int
                |> Seq.toList
    let index = Console.ReadLine().Split(" ")
                |> Seq.map int
                |> Seq.sortDescending
    printf "%d" (fst index)       
    0 // return an integer exit code
