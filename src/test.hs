main = do
        x <- getLine
        if x == "42"
        then return ()
        else do
            putStrLn x
            main
