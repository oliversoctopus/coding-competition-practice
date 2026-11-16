n, s=map(int, input().split())
locs=[]
for i in range(n):
    a=list(map(int, input().split()))
    a.append(0)
    locs.append(a)

broken=0
bessie=[s, 1, 1] # coord, power, direction (1=right, -1=left)
poss_vals=[]
while True:
    c=bessie[0]
    if not 1<=c<=n:
        break
    under=locs[c-1]
    if under[0]==0:
        if under[1]==0:
            if under[2]==0:
                under[2]=[bessie[1:]]
            elif bessie[1:] in under[2]:
                break
            else:
                under[2].append(bessie[1:])
            bessie[2]*=-1
        else:
            bessie[1]+=under[1]
            bessie[2]*=-1
    else:
        if bessie[1]>=under[1] and under[2]==0:
            broken+=1
            under[2]=1
    bessie[0]+=bessie[1]*bessie[2]

print(broken)
