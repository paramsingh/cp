import Control.Monad
import Data.List
import qualified Data.ByteString.Char8 as B

-- Brute force method
ans :: Int -> Integer -> Integer -> Integer
ans n l r = (sum . concat . (take n) $ requiredlst l r) `mod` (10^6 + 3)

requiredlst l r = [r - l + 1] : iterate generate [1 .. (r-l+1)]
                  where generate lst = 1 : zipWith (+) (tail lst) (generate lst)


-- Slightly more optimised
facts = 1 : 1 : 2 : zipWith (*) (drop 2 facts) [3..]

n `c` r = (facts !! n) `div` ((facts !! (n-r)) * (facts !! r))

anotherList l r = map (`mod` (10^6+3)) $ zipWith (c) [(r-l+1) .. ] [1..]

ans' n l r = (sum . (take n) $ anotherList l r) `mod` (10^6 + 3)

main = readLn >>= flip replicateM_ secondIO

secondIO = do
            str <- getLine
            let n = read . head $ words str
            let [l,r] = (map read) . tail $ words str
            print $ ans n l r
