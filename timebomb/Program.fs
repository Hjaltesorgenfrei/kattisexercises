open System

[<EntryPoint>]
let main argv =
    let numbers = [|
        [|
        "***";
        "* *";
        "* *";
        "* *";
        "***"
        |];
        [|
        "  *";
        "  *";
        "  *";
        "  *";
        "  *"
        |];[|
        "***";
        "  *";
        "***";
        "*  ";
        "***"
        |];[|
        "***";
        "  *";
        "***";
        "  *";
        "***"
        |];[|
        "* *";
        "* *";
        "***";
        "  *";
        "  *"
        |];[|
        "***";
        "*  ";
        "***";
        "  *";
        "***"
        |];[|
        "***";
        "*  ";
        "***";
        "* *";
        "***"
        |];[|
        "***";
        "  *";
        "  *";
        "  *";
        "  *"
        |];[|
        "***";
        "* *";
        "***";
        "* *";
        "***"
        |];[|
        "***";
        "* *";
        "***";
        "  *";
        "***"
        |];
    |]
    
    let s = Array.init 5 (fun x -> Console.ReadLine())
    let digitAmount = (s.[0].Length / 4) + 1
    let a = Array.init digitAmount (fun i -> Array.init 5 (fun i -> ""))
    //printfn "digits: %i" digitAmount
    s |> Array.iteri 
        (fun line s -> 
                    //printf "%i: " line
                    Array.splitInto digitAmount (Array.ofSeq s)
                    |> Array.iteri 
                        (fun ii k -> 
                            let v = k |> String.Concat
                            //printf "%i:%s" ii v
                            a.[ii].[line] <- v.Substring(0, 3)
                        )
                   // printfn ""
                    )                           
    //a.[0] |> Array.iter (fun s -> printfn "%s : %i" s (s.Length))
    let answer = 
        try
            let sq = a |> Array.fold 
                        (fun s l -> 
                            let index = (Array.findIndex (fun k -> k = l) numbers)
                            (s + index) * 10
                        ) 0                    
            if (sq/10) % 6 = 0 then "BEER!!"
            else "BOOM!!"
        with
        | _ -> "BOOM!!"
    printfn "%s" answer
    0
