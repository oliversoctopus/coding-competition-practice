import sys
sys.stdin=open('cowqueue.in')
sys.stdout=open('cowqueue.out', 'w')
n=int(input())
cows=[[int(i) for i in input().split()] for j in range(n)]
cows=sorted(cows)
cur_t=cows[0][0]
for c in cows:
    if c[0]<=cur_t:
        cur_t+=c[1]
    else:
        cur_t=c[0]+c[1]
print(cur_t)
    
