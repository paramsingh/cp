terms = int(raw_input())
bg = "BG"*50000
gb = "GB"*50000

for term in range(terms):
    var_type = int(raw_input())
    string = raw_input()
    # print string
    bgb = []
    bgg = []
    gbb = []
    gbg = []
    for index, ch in enumerate(string):
        if index%2 == 0:
            if ch != 'G':
                gbg.append(index)
            else:
                bgb.append(index)
        else:
            if ch != 'B':
                gbb.append(index)
            else:
                bgg.append(index)
    # print bgb, bgg
    # print gbb, gbg
    lbgg = len(bgg)
    lbgb = len(bgb)
    lgbb = len(gbb)
    lgbg = len(gbg)
    costb = 0
    costg = 0

    bgflag =  lbgg == lbgb
    gbflag =  lgbg == lgbb


    if bgflag:
        for index, i in enumerate(bgg):
            costb += (abs(bgb[index] - i)) ** var_type
    if gbflag:
        for index, i in enumerate(gbb):
            costg += abs(gbg[index] - i) ** var_type
    if bgflag and gbflag:
        cost = costb if costb < costg else costg
        print cost
    elif bgflag:
        print costb
    elif gbflag:
        print costg
    else:
        print "-1"
