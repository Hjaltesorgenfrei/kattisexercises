// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    Console.ReadLine().Split([|' '|]).[1]
    |> printfn "%s"
    0