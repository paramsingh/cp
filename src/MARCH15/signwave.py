terms = int(raw_input())
for term in range(terms):
    s, c, k = map(int, raw_input().split())
    if k == 1:
        if c >= s:
            count = 0
            a = 2
            for i in range(c):
                count += a
                a *= 2
            if s == 0:
                print count
            else:
                print (count+3)
        else:
            count = 3
            a = 2
            for i in range(s-1):
                count += a
                a *= 2
            print count
    elif c == 0:
        if k>s:
            print "0"
        else:
            count = 0
            # s - 3
            # s-1 - 2
            # s-2 - 4
            # s-3 - 8
            count = 3
            var = s-k
            a = 2
            while var > 0:
                count += a
                a *= 2
                var -= 1
            print count
    else:
        if k > s:
            print "0"
        else:
            max_cos_depth = c
            current_depth = 0
            current_k = s
            while current_k != k-1:
                current_depth += 1
                current_k -= 1
            if current_depth > max_cos_depth:
                var = s - k
            else:
                var = s - k + 1
            count = 3
            a = 2
            while var > 0:
                count += a
                a *= 2
                var -= 1
            print count
