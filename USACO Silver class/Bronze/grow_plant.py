t=int(input())
import math

def find_rank(ls):
    ls=[(val, i) for i, val in enumerate(ls)]
    ls=sorted(ls, reverse=True)
    t=[-1]*len(ls)
    for i in range(len(ls)):
        val=ls[i]
        if ls[i-1][0]!=val[0] or i==0:
            t[val[1]]=i
    return t

def intersect(p1, g1, p2, g2):
    return math.ceil((p2-p1)/(g1-g2)) if g1!=g2 else None
    
for i in range(t):
    n=int(input())
    h=list(map(int, input().split()))
    a=list(map(int, input().split()))
    t=list(map(int, input().split()))
    rel_grow=[]
    for i in a:
        rel_grow.append(i-a[0])
    poss_vals=[]
    for i in range(len(h)):
        for j in range(i, len(h)):
            inter=intersect(h[i], a[i], h[j], a[j])
            if inter==None:
                continue
            h_new=[h[i]+inter*a[i] for i in range(len(h))]
            if find_rank(h_new)==t:
                poss_vals.append(inter)
    if poss_vals==[]:
        print(-1)
        continue
    print(min(poss_vals))
    
'''
    day=0
    found=False
    for i in range(100):
        t1=find_rank(h)
        if t1==t:
            print(day)
            found=True
            break
        h=[i[0]+i[1] for i in zip(h, a)]
        day+=1
    if not found:
        print(-1)
'''
