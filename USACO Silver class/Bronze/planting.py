import sys
sys.stdin=open("planting.in")
sys.stdout=open("planting.out", "w")

n=int(input())
conn=[0]*n
for i in range(n-1):
    c1, c2=list(map(int, input().split()))
    conn[c1-1]+=1
    conn[c2-1]+=1

print(max(conn)+1)
