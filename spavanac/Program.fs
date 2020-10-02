// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let time = Console.ReadLine().Split([|' '|])
    let hour = (int time.[0])
    let minute = (int time.[1])
    let h2 = 
        if minute < 45 then
            if hour = 0 then 23
            else hour - 1
        else hour
    let m2 = 
        if minute < 45 then 
            //printfn "%d" (minute - 45)
            60 + (minute - 45)
        else minute - 45
    printfn "%d %d" h2 m2
    0 // return an integer exit code
