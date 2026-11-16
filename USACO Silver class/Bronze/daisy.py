import sys

n=int(input())
petals=list(map(int, input().split()))

def avg(ls):
    return sum(ls)/len(ls)

avg_flower=0
for i in range(len(petals)):
    for j in range(i, len(petals)):
        photo=petals[i:j+1]
        average=avg(photo)
        if average in photo:
            avg_flower+=1

print(avg_flower)
