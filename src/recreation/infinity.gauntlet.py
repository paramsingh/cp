color = {
    'purple': 'Power',
    'green': 'Time',
    'blue': 'Space',
    'orange': 'Soul',
    'red': 'Reality',
    'yellow': 'Mind',
}

if __name__ == '__main__':
    n = int(input())
    gems = []
    for _ in range(n):
        gems.append(input())
    cnt = 0
    ans = []
    for gem in color:
        if gem not in gems:
            cnt += 1
            ans.append(color[gem])
    print(cnt)
    for line in ans:
        print(line)
