import sys

sys.stdin=open('sleepy.in', 'r')
sys.stdout=open('sleepy.out', 'w')

n=int(input())
cows=[int(x) for x in input().split()]

ans=0
for i in range(n-1, 0, -1):
    if cows[i]<cows[i-1]:
        ans=i
        break
print(ans)
