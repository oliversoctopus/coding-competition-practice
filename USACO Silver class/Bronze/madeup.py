n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
c=list(map(int, input().split()))
def count(ls):
    vals={}
    for thing in ls:
        if thing not in vals:
            vals[thing]=1
        else:
            vals[thing]+=1
    return vals
c_count=count(c)
a_count=count(a)
b_count={}
for i, val in enumerate(b):
    if i+1 in c_count:
        if val in b_count:
            b_count[val]+=c_count[i+1]
        else:
            b_count[val]=c_count[i+1]
total=0
for n, val in a_count.items():
    if n in b_count:
        total+=a_count[n]*b_count[n]
print(total)
    
