n, k=map(int, input().split())
d=[[int(i), int(i), k+1] for i in input().split()]

def edit_d(d):
    if len(d)==1:
        return d, True
    new_d=[]
    all_separate=True
    prev_merge=False
    for i in range(0, len(d)-1):
        if not prev_merge:
            d1=d[i]
            d2=d[i+1]
            separate=d1[2]+d2[2]
            dist=d2[1]-d1[0]+1
            together=dist+k
            if together<separate:
                if len(new_d)>0 and new_d[-1]==d1:
                    new_d.pop()
                all_separate=False
                prev_merge=True
                new_d.append([d1[0], d2[1], together])
            else:
                prev_merge=False
                new_d.extend([d1, d2])
        else:
            prev_merge=False
    if not prev_merge:
        new_d.append(d[-1])
    d=new_d
    new_d=[]
    prev=[]
    for day in d:
        if day!=prev:
            new_d.append(day)
        prev=day[:]
    return new_d, all_separate

all_separate=False
while not all_separate:
    d, all_separate=edit_d(d)

total_cost=sum([i[2] for i in d])
print(total_cost)
