import Control.Monad

sumN n = (n * (n+1)) `div` 2

numberOfCombinations step num = foldl (+) 0 $ map (sumN . rep) [1..step]
                                where rep x = (num - x) `div` step

findStep str = foldl (\acc ch -> if ch == 'T' then (acc+2) else (acc+1)) 0 str

ans str octaves = numberOfCombinations (findStep str) (octaves * 12)

main = readLn >>= flip replicateM_ secondIO

secondIO = do
            str <- getLine
            octaves <- readLn
            print $ ans str octaves
