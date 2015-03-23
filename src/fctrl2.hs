fact :: Integer -> Integer
fact n = product [2..n]

findfact = do
            n <- readLn
            print $ fact n

main = do
        terms <- readLn
        sequence $ replicate terms findfact
        return ()
