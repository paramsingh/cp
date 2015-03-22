chef :: [a] -> [a]
chef [] = []
chef [x] = [x]
chef (x:xs) = [x] ++ chef (tail xs)

assistant :: [a] -> [a]
assistant [] = []
assistant [x] = []
assistant (x:xs) = [head xs] ++ assistant (tail xs)

clean = do
        str <- getLine
        let [n, m] = map (\x -> read x :: Int) $ words str
        str_m <- getLine
        let done = map (\x -> read x :: Int) $ words str_m
        let remaining = [x | x <- [1..n], notElem x done]
        putStrLn . unwords $ map show (chef remaining)
        putStrLn . unwords $ map show (assistant remaining)

main = do
        terms <- readLn
        sequence $ replicate terms clean
        return ()
