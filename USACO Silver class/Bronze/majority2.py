t=int(input())
def add_vals(hays_dist, val, i_s):
    length=len(i_s)
    if val in hays_dist:
        dists=hays_dist[val]
        for d in dists:
            interval=d[0]
            new_dist=i_s[-1]-i_s[-1-interval+1]
            limit=interval/2
            if new_dist<d[1]:
                d[1]=new_dist
                if d[1]<limit:
                    return hays_dist, True
        dists.append([len(i_s), i_s[-1]-i_s[0]])
        return hays_dist, False
    else:
        hays_dist[val]=[[2, i_s[1]-i_s[0]]]
        if i_s[1]-i_s[0]<3:
            return hays_dist, True
        else:
            return hays_dist, False
            
for i in range(t):
    n=int(input())
    hays=list(map(int, input().split()))
    hays_dict={}
    hays_dist={}
    result=[]
    for i in range(len(hays)):
        h=hays[i]
        if h not in hays_dict:
            hays_dict[h]=[i]
        elif h not in result:
            hays_dict[h].append(i)
            hays_dist, success=add_vals(hays_dist, h, hays_dict[h])
            if success:
                result.append(h)
        
    if len(result)!=0:
        string=''
        result.sort()
        for r in result:
            string+=str(r)+' '
        print(string[:-1])
    else:
        print(-1)
