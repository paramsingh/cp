-- http://codechef.com/problems/PLZLYKME

numLikes s c = s : (s*c + s) : map (\x -> x*c + x) (tail $ numLikes s c)

-- f(1) = s
-- f(x) = f(1) * (c+1)**(d-1)

alive ::(Floating a, Ord a) => a -> a -> a -> a -> Bool
alive l d s c = log s + (d-1) * log (c + 1) >= log l

checkIfAlive = do
                str <- getLine
                let [l, d, s, c] = map (\x -> read x :: Float) $ words str
                if alive l d s c
                    then putStrLn "ALIVE AND KICKING"
                    else putStrLn "DEAD AND ROTTING"


main = do
        terms <- readLn
        sequence $ replicate terms checkIfAlive
        return ()
