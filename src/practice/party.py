def knapsack(cost, fun, w, n):
    dp = [[0 for _ in range(w+1)] for _ in range(n+1)]
    keep  = [[False for _ in range(w+1)] for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(w+1):
            if cost[i-1] <= j and (fun[i-1] + dp[i-1][j-cost[i-1]]) > dp[i-1][j]:
                keep[i][j] = True
                dp[i][j] = fun[i-1] + dp[i-1][j-cost[i-1]]
            else:
                keep[i][j] = False
                dp[i][j] = dp[i-1][j]

    net = 0
    k = w
    for i in range(n, 0, -1):
        if keep[i][k]:
            net += cost[i-1]
            k -= cost[i-1]

    print net, dp[n][w]

while True:
    raw_input()
    w, n = map(int, raw_input().split())
    if w == 0 and n == 0:
        break
    fun = [0 for _ in range(n)]
    cost = [0 for _ in range(n)]
    for i in range(n):
        cost[i], fun[i] = map(int, raw_input().split())
    knapsack(cost, fun, w, n)

