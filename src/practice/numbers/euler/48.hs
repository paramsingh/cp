-- One way is using exponentiation by squaring
big = 10^10
power :: Integer -> Integer -> Integer
power a b   | b == 0       = 1
        | b == 1       = mod a big
        | mod b 2 == 0 = power (mod ((mod a big)*(mod a big)) big) (div b 2)
        | mod b 2 /= 0 = mod ((mod (power (mod ((mod a big) * (mod a big)) big) (div b 2)) big) * (mod a big)) big

lst = [power x x | x <- [1..1000]]

ans = foldr (\x y -> mod (x + y) big) 0 lst

-- Another way
ans2 = sum ([x^x | x <-[1..1000]]) `mod` big

main = print ans
