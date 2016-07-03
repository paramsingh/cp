import Data.List
order n = elemIndex True $ map (\x -> mod x n == 1) [10^x | x <- [1..1000]]
main = print . snd . maximum $ map (\x -> (order x, x)) [1..1001]
