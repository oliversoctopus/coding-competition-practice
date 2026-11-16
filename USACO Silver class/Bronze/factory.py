import sys
sys.stdin=open("factory.in")
sys.stdout=open('factory.out', 'w')

n=int(input())

adj={i: [] for i in range(n)}
for i in range(n-1):
    a, b=map(int, input().split())
    adj[a-1].append(b-1)

sink=[]
for i in range(n):
    out=adj[i]
    if len(out)==0:
        sink.append(i)

if len(sink)!=1:
    print(-1)
else:
    print(sink[0]+1)
