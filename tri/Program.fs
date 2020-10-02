// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let lines = Console.ReadLine().Split(" ")
                |> Seq.map int
                |> Seq.toList
    match lines with
    | a::b::c::xs when a+b=c -> printfn "%d+%d=%d" a b c
    | a::b::c::xs when a-b=c -> printfn "%d-%d=%d" a b c
    | a::b::c::xs when a/b=c -> printfn "%d/%d=%d" a b c
    | a::b::c::xs when a*b=c -> printfn "%d*%d=%d" a b c
    | a::b::c::xs when a=b+c -> printfn "%d=%d+%d" a b c
    | a::b::c::xs when a=b-c -> printfn "%d=%d-%d" a b c
    | a::b::c::xs when a=b/c -> printfn "%d=%d/%d" a b c
    | a::b::c::xs when a=b*c -> printfn "%d=%d*%d" a b c
    | _ -> failwith "bigwonk"
    0
