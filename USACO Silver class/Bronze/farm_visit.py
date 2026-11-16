n, q=map(int, input().split())
c=list(map(int, input().split()))
t=list(map(int, input().split()))
times=sorted([c[i]-t[i] for i in range(n)])
for i in range(q):
    v, s=map(int, input().split())
    counter=0
    success=False
    time=times[-v]
    if s<time:
        print('YES')
    else:
        print('NO')
