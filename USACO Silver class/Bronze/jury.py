k, n=map(int, input().split())
a=list(map(int, input().split()))
b=list(map(int, input().split()))

pre=[a[0]]
for i in range(1, k):
    pre.append(pre[i-1]+a[i])

poss=set()
for i in pre:
    x=b[0]-i
    poss.add(x)

ans=0
for i in poss:
    scores=set()
    for j in pre:
        scores.add(i+j)
    if scores&set(b)==set(b):
        ans+=1
print(ans)
