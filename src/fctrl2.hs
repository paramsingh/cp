fact :: Integer -> String
fact n = show $ product [2..n]

doterms :: Int -> IO ()
doterms 1 = do
            a <- getLine
            putStrLn . fact $ (read a::Integer)
            return ()
doterms x = do
            a <- getLine
            putStrLn . fact $ (read a::Integer)
            doterms (x-1)

main = do
        terms <- getLine
        doterms (read terms:: Int)

