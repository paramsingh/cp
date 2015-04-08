import Control.Monad
import Data.List
import qualified Data.ByteString.Char8 as B

big = 10^6 + 3

-- Brute force method
ans :: Int -> Integer -> Integer -> Integer
ans n l r = (sum . concat . (take n) $ requiredlst l r) `mod` big

requiredlst l r = [r - l + 1] : iterate generate [1 .. (r-l+1)]
                  where generate lst = 1 : zipWith (+) (tail lst) (generate lst)


-- Slightly more optimised
-- or maybe not
facts' = 1 : 1 : 2 : zipWith (\x y -> ((x `mod` big) * (y `mod` big)) `mod` big) (drop 2 facts) [3..]

facts = 1 : 1 : 2 : zipWith (*) (drop 2 facts) [3..]

-- inverse x % p = (x ^ p - 2) % p

fact n = foldl (*) 1 [2..n]

-- ib = inverse' big
mb = (\x -> x `mod` big)

n `c` r = (fact n) `div` ((fact (n-r)) * (fact r))

anotherList l r = zipWith (c) [(r-l+1) .. ] [1..]

ans' n l r = (sum . (take n) $ anotherList l r) `mod` big

main = readLn >>= flip replicateM_ secondIO

secondIO = do
            str <- getLine
            let n = read . head $ words str
            let [l,r] = (map read) . tail $ words str
            print $ ans' n l r
