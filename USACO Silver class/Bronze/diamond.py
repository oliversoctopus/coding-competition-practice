import sys

sys.stdin=open('diamond.in')
sys.stdout=open('diamond.out', 'w')

n, k=map(int, input().split())
gems=[]
for i in range(n):
    gems.append(int(input()))

max_diamonds=-1
for gem in gems:
    diamonds=1
    temp=gems[:]
    temp.remove(gem)
    for g in temp:
        diff=abs(gem-g)
        if diff<=k and g>=gem:
            diamonds+=1
    max_diamonds=max(diamonds, max_diamonds)

print(max_diamonds)
