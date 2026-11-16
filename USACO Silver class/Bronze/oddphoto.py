n=int(input())
ids=list(map(int, input().split()))

new_ids={0: [], 1: []}
for i in ids:
    if i%2==0:
        new_ids[0].append(i)
    else:
        new_ids[1].append(i)

cur_state='e'
groups=0
while True:
    if cur_state=='e':
        if len(new_ids[0])>0:
            new_ids[0].pop(0)
        elif len(new_ids[1])>0:
            new_ids[1].pop(0)
            if len(new_ids[1])>0:
                new_ids[1].pop(0)
            else:
                groups-=1
                break
        else:
            break
        groups+=1
        cur_state='o'
    elif cur_state=='o':
        if len(new_ids[1])>0:
            new_ids[1].pop(0)
            groups+=1
            cur_state='e'
        else:
            break

print(groups)
