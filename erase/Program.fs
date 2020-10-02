// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let n = Console.ReadLine() |> int
    let firstLine = Console.ReadLine()
    let secondLine = Console.ReadLine()
    let answer = 
        if n % 2 = 0 then
            if firstLine = secondLine then
                "Deletion succeeded"
            else 
                "Deletion failed"            
        else 
            let flipped = firstLine |> Seq.map (fun c -> if c = '0' then '1' else '0') |> String.Concat
            if flipped = secondLine then
                "Deletion succeeded"
            else 
                "Deletion failed"  
    printfn "%s" answer
    0 // return an integer exit code
