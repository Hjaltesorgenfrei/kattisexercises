// Learn more about F# at http://fsharp.org

open System

let compute radiusLo radiusHi sigma = 
    let cLo = -((radiusLo ** 2.0)/(2.0*(sigma ** 2.0)))
    (Math.Exp(cLo)) - Math.Exp(-((radiusHi ** 2.0)/(2.0*(sigma ** 2.0)))) 

[<EntryPoint>]
let main argv =
    let numbers = Console.ReadLine().Split(" ") |> Seq.map float |> List.ofSeq
    let bullsEye = float numbers.[0]
    let bull = float numbers.[1]
    let innerTriple = float numbers.[2]
    let outerTriple = float numbers.[3] 
    let innerDouble = float numbers.[4]
    let outerDouble = float numbers.[5]
    let sigma = Console.ReadLine() |> float
    let result = 
        ((compute 0.0 bullsEye sigma) * 50.0) 
        + ((compute bullsEye bull sigma) * 25.0)
        + ((compute bull innerTriple sigma) * 10.5)
        + ((compute innerTriple outerTriple sigma) * 31.5) 
        + ((compute outerTriple innerDouble sigma) * 10.5)
        + ((compute innerDouble outerDouble sigma) * 21.0)
    printfn "%f" result
    0 // return an integer exit code
