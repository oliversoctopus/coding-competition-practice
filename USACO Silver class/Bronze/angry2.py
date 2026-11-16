import sys

#sys.stdin=open('angry.in')
#sys.stdout=open('angry.out', 'w')

n, k=map(int, input().split())
bales=[]
for i in range(n):
    bales.append(int(input()))

bales.sort()
dists=[]
for i in range(len(bales)-1):
    b1=bales[i]
    b2=bales[i+1]
    dists.append(b2-b1)
new_dists=sorted([(v, i) for i, v in enumerate(dists)])

max_dists=new_dists[max(len(dists)-k, 0):]
max_is=[d[1] for d in max_dists]
max_dists=[d[0] for d in max_dists]

r=-1
cur_r=0
for i in range(len(bales)-1):
    b_dist=dists[i]
    if i in max_is:
        r=max(r, cur_r)
        cur_r=0
    else:
        cur_r+=b_dist
print(r)
