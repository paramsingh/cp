-- so the amount of memory deallocated should be easy enough to do

--  INPUT
import Control.Monad
import Data.List

b2ints :: B.ByteString -> [Int]
b2ints = unfoldr (B.readInt . B.dropWhile (== ' '))


main :: IO ()
main = readLn >>= flip replicateM_ secondIO


secondIO :: IO ()
secondIO = do
            B.getLine
            str <- B.getLine
            let list = b2ints str
            print . fst $ ans list


-- Computation
ans list = foldr (\x y -> if x > (snd y) then ((fst y) + x - (snd y), x) else (fst y, x)) (0, 0) list
