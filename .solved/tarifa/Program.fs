// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let x = Console.ReadLine() |> int
    let n = Console.ReadLine() |> int
    (fun _ -> Console.ReadLine()) |>
    Seq.initInfinite |>
    Seq.takeWhile ((<>) null) |>
    Seq.sumBy
       (fun (s : string) ->
            let p = s |> int
            x - p
       ) |>
    (fun v -> x + v) |> 
    printfn "%d"

    0 // return an integer exit code
