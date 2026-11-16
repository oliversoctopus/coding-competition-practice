import sys
sys.stdin=open('whereami.in')
sys.stdout=open('whereami.out', 'w')
n=int(input())
m=input()
thing=True
for k in range(1, n):
    k_l=[]
    for i in range(len(m)-k+1):
        k_l.append(m[i:i+k])
    if len(list(set(k_l)))==len(k_l):
        print(k)
        thing=False
        break
if thing:
    print(n)
