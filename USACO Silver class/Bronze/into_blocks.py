n=int(input().split()[0])
a=list(map(int, input().split()))

first_occur={}
last_occur={}
count={}

for i in range(n):
    if a[i] not in first_occur:
        first_occur[a[i]]=i
    last_occur[a[i]]=i
    if a[i] not in count:
        count[a[i]]=1
    else:
        count[a[i]]+=1

def overlap(val, inds):
    first=first_occur[val]
    last=last_occur[val]
    if last>=inds[0] and first<=inds[1]:
        return True
    return False

block=0
max_count=0
constants=0
for i in range(n):
    if i==first_occur[a[i]]:
        block+=1
    if i==last_occur[a[i]]:
        block-=1
    max_count=max(max_count, count[a[i]])
    if block==0:
        constants+=max_count
        max_count=0
print(n-constants)

        
    
