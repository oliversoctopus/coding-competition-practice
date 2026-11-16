import sys
sys.stdin=open('herding.in')
sys.stdout=open('herding.out', 'w')

locs=sorted(list(map(int, input().split())))

def consecutive(ls):
    if ls[1]==ls[0]+1 and ls[2]==ls[1]+1:
        return True
    return False

minimum=2
if consecutive(locs):
    minimum=0
elif locs[2]==locs[1]+2 or locs[1]==locs[0]+2:
    minimum=1

maximum=-1
if consecutive(locs):
    maximum=0
else:
    d1=locs[2]-locs[1]
    d2=locs[1]-locs[0]
    max_d=max(d1, d2)
    maximum=max_d-1

print(minimum)
print(maximum)
