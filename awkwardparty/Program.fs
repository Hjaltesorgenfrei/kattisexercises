// Learn more about F# at http://fsharp.org

open System
open System.Collections.Generic

[<EntryPoint>]
let main argv =
    let di = new Dictionary<int, int>()
    let n = Console.ReadLine() |> int      
    let party = Console.ReadLine().Split(" ")
                |> Seq.map int
                |> Seq.indexed
                |> Seq.map (fun k -> 
                    if di.ContainsKey(snd k) then 
                        let r = fst k - di.[snd k]
                        di.[snd k] <- fst k
                        r
                    else 
                        di.Add(snd k, fst k)   
                        2147483647      
                   
                )
    let partymin = party |> Seq.min            
    
    printfn "%d" (min partymin (party |> Seq.length))
    0 // return an integer exit code
