findNumFours :: String -> Int
findNumFours str = helper 0 str
                    where
                        helper num [] = num
                        helper num (x:xs) = if x == '4'
                                            then helper (num+1) xs
                                            else helper num xs

doterms :: Integer -> IO ()
doterms 1 = do
            str <- getLine
            putStrLn . show $ findNumFours str
            return ()
doterms x = do
            str <- getLine
            putStrLn . show $ findNumFours str
            doterms (x-1)

main = do
        terms <- getLine
        doterms (read terms::Integer)
