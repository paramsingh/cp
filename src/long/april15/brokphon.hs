import Data.List
import Control.Monad
import qualified Data.ByteString.Char8 as B

numWrongs :: (Eq a) => [a] -> Int
numWrongs [] = 0
numWrongs lst = let groups = map length $ group lst
                    x = foldl' (\x y -> if y == 1 then (x+1) else (x+2)) 0 groups
                in if length groups == 1
                   then 0
                   else if last groups /= 1
                        then if head groups /= 1 then (x-2) else (x-1)
                        else if head groups /= 1 then (x-1) else x


secondIO :: IO ()
secondIO = do
            B.getLine
            str <- B.getLine
            print $ numWrongs (b2ints str)
            return ()

main :: IO ()
main = readLn >>= flip replicateM_ secondIO

b2ints :: B.ByteString -> [Int]
b2ints = unfoldr (B.readInt . B.dropWhile (==' '))
