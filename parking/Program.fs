// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let a = Console.ReadLine() |> (fun s -> s.Split(" ")) |> Array.map (fun s -> int(s))
    let cars = Array.init 99 (fun _ -> 0)
    let v = Seq.init 3 (fun _ -> Console.ReadLine() |> (fun s -> s.Split(" ")) |> Array.map (fun s -> int(s)))
            |> Seq.map (fun a -> for i in (a.[0]-1)..(a.[1]-1) do cars.[i] <- cars.[i]+1)
    cars
    |> Array.sumBy (
        function
        | 0 -> 0
        | x -> a.[x-1]
    )
    |> printf "%i"
    0 // return an integer exit code
