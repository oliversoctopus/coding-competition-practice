n, m=list(map(int, input().split()))
cows=list(map(int, input().split()))
canes=list(map(int, input().split()))

final_cow=[0]*n
def cow_list(cows):
    max_c=0
    new_cow=[]
    for i in range(len(cows)):
        c=cows[i]
        if c>max_c:
            new_cow.append([i, c, c-max_c])
            max_c=c
        else:
            final_cow[i]=c
    return new_cow

cows=cow_list(cows)
for c in canes:
    counter=0
    max_c=0
    new_cow=[]
    for i in range(len(cows)):
        c1=cows[i]
        grow=c1[2]
        cur=c1[1]
        if counter+grow<=c:
            cur+=grow
            counter+=grow
        elif counter<c<=counter+grow:
            cur+=c-counter
            counter=c
            
        if c1[1]>max_c:
            grow=cur-max_c
            max_c=cur
            new_cow.append([c1[0], cur, grow])
        else:
            final_cow[c1[0]]=cur
    cows=new_cow

for c in cows:
    final_cow[c[0]]=c[1]

for c in final_cow:
    print(c)
