# Author: Param Singh <paramsingh258@gmail.com>
# Who dares to be a millionaire: https://www.codechef.com/OCT15/problems/WDTBAM

t = int(raw_input())
for _ in range(t):
    n = int(raw_input())
    correct = raw_input()
    chef = raw_input()
    winnings = map(int, raw_input().split())
    ca = 0
    wa = 0
    for c, ch in zip(correct, chef):
        if c == ch:
            ca += 1
        else:
            wa += 1

    if wa != 0:
        print max(winnings[0:ca+1])
    else:
        print winnings[n]
