import sys

sys.stdin=open('gymnastics.in')
sys.stdout=open('gymnastics.out', 'w')

k, n=map(int, input().split())
rankings=[]
for i in range(k):
    rankings.append(list(map(int, input().split())))

pairs=0
for i in range(1, n+1):
    for j in range(1, n+1):
        consistent=True
        for rank in rankings:
            c1_i=rank.index(i)
            c2_i=rank.index(j)
            f_b=c1_i<c2_i
            if f_b!=True:
                consistent=False
                break
        if consistent:
            pairs+=1

print(pairs)
