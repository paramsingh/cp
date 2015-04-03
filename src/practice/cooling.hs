import Data.List

getnum pies racks = helper 0 pies racks
                    where helper acc p r | p == [] || r == [] = acc
                          helper acc p r = if racks_aval /= []
                                           then helper (acc+1) (tail p) (init r)
                                           else helper acc (tail p) r
                                           where racks_aval = filter (>=(head p)) r
cool = do
       getLine
       pie_str <- getLine
       let pies = reverse . sort $ map (\x -> read x :: Int) $ words pie_str
       rack_str <- getLine
       let racks = sort $ map (\x -> read x :: Int) $ words rack_str
       print $ getnum pies racks

main = do
       terms <- readLn
       sequence $ replicate terms cool
       return ()
