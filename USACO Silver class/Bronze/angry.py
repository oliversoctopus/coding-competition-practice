import sys

sys.stdin=open('angry.in')
sys.stdout=open('angry.out', 'w')

n=int(input())
bales=[]
for i in range(n):
    bales.append(int(input()))

bales.sort()
bale_exp=[[b, 0] for b in bales]

def affected(b_i, r, orig_i, b_exp):
    b=bales[b_i]
    exploded=[]
    if b_i<=orig_i:
        for i in range(b_i-1, -1, -1):
            if b-bales[i]<=r:
                if b_exp[i][1]==0:
                    exploded.append(i)
                    b_exp[i][1]=1
            else:
                break
    if b_i>=orig_i:
        for i in range(b_i+1, len(bales)):
            if bales[i]-b<=r:
                if b_exp[i][1]==0:
                    exploded.append(i)
                    b_exp[i][1]=1
            else:
                break
    return exploded

def try_bale(b_i):
    b=bales[b_i]
    b_exp=[[b[0], b[1]] for b in bale_exp]
    r=1
    a=affected(b_i, r, b_i, b_exp)
    total=len(a)
    while a!=[]:
        r+=1
        a_new=[]
        for i in a:
            exploded=affected(i, r, b_i, b_exp)
            a_new.extend(exploded)
            a_new=list(set(a_new))
        a=a_new[:]
        total+=len(a_new)
    return total+1

maximum=-1
for i in range(len(bales)):
    result=try_bale(i)
    maximum=max(maximum, result)
    if maximum==len(bales):
        break
print(maximum)
