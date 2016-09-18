import Control.Monad
import Data.List
import qualified Data.ByteString.Char8 as B

f lst = if (1 `elem` lst)
        then Nothing
        else Just ((sum lst) - (minimum lst) + 2)

main = readLn >>= flip replicateM_ secondIO

secondIO = do
            B.getLine
            str <- B.getLine
            case (f $ b2ints str) of 
                Nothing -> putStrLn "-1"
                Just x -> print x

b2ints :: B.ByteString -> [Int]
b2ints = unfoldr (B.readInt . B.dropWhile (==' '))
