import Control.Monad
import Data.List
import qualified Data.ByteString.Char8 as B

ans :: Int -> Integer -> Integer -> Integer
ans n l r = (sum . concat . (take n) $ requiredlst l r) `mod` (10^6 + 3)

requiredlst l r = [r - l + 1] : iterate generate [1 .. (r-l+1)]
                  where generate lst = 1 : zipWith (+) (tail lst) (generate lst)
{-
(\x -> 1 : zipWith (+) ta)
reqList l r = [r-l+1] : iterate (\x -> (map sum) . init $ tails x) [(r-l+1), (r-l) .. 1]
--}

main = readLn >>= flip replicateM_ secondIO

secondIO = do
            str <- getLine
            let n = read . head $ words str
            let [l,r] = (map read) . tail $ words str
            print $ ans n l r
