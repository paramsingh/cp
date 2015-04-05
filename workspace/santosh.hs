import Control.Monad

infList n = iterate (\lst -> zipWith (+) lst (tail lst)) [1..n]

ans n =  head . head . dropWhile (\x -> length x /= 1) $ infList n

main = readLn >>= flip replicateM_ secondIO

secondIO = do
            n <- readLn
            print $ ((ans n) `mod` 1000000007)
