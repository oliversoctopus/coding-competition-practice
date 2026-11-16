import sys

sys.stdin=open('backforth.in')
sys.stdout=open('backforth.out', 'w')

first_old=[int(i) for i in input().split()]
second_old=[int(i) for i in input().split()]

first={}
second={}
for i in first_old:
    if i in first.keys():
        first[i]+=1
    else:
        first[i]=1

for i in second_old:
    if i in second.keys():
        second[i]+=1
    else:
        second[i]=1

def gen_perms(first, second, perms, first_change=0, turn=1, times=0):
    if times==4:
        if first_change not in perms:
            perms.append(first_change)
        return perms
    if turn==1:
        for unit in first.keys():
            temp=first.copy()
            if temp[unit]==1:
                del temp[unit]
            else:
                temp[unit]-=1
            temp2=second.copy()
            if unit not in temp2:
                temp2[unit]=1
            else:
                temp2[unit]+=1
            temp3=first_change-unit
            perms=gen_perms(temp, temp2, perms, temp3, 2, times+1)
    else:
        for unit in second.keys():
            temp=second.copy()
            if temp[unit]==1:
                del temp[unit]
            else:
                temp[unit]-=1
            temp2=first.copy()
            if unit not in temp2:
                temp2[unit]=1
            else:
                temp2[unit]+=1
            temp3=first_change+unit
            perms=gen_perms(temp2, temp, perms, temp3, 1, times+1)
    return perms

perms=gen_perms(first, second, [])
print(len(perms))
