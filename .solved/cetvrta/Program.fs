// Learn more about F# at http://fsharp.org

open System

let f l =  l |> List.toSeq |> Seq.countBy id |> Seq.filter (fun n -> snd n = 1) |> Seq.tryPick (fun n -> Some(fst n))

[<EntryPoint>]
let main argv =
    
    let x, y =  
        (fun _ -> Console.ReadLine()) |>
        Seq.initInfinite |>
        Seq.takeWhile ((<>) null) |>
        Seq.map
            (fun (s : string) ->
                let arr = s.Split([|' '|])
                let a = int arr.[0]
                let b = int arr.[1]
                (a, b)
                /// solve test case and output answer
            ) |> 
        Seq.toList |>
        List.unzip
    let x1 = f x    
    printf "%d %d" (f x).Value (f y).Value


    0  
