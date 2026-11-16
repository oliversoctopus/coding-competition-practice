import sys

sys.stdin=open('lifeguards.in')
sys.stdout=open('lifeguards.out', 'w')

n=int(input())
lifeguards=[]
for i in range(n):
    lifeguards.append([int(i) for i in input().split()])

def find_time(guards):
    intervals=[0]*1000
    for g in guards:
        intervals[g[0]:g[1]]=[1]*(g[1]-g[0])
    total=sum(intervals)
    return total

max_time=-1
for l in lifeguards:
    temp=lifeguards[:]
    temp.remove(l)
    time=find_time(temp)
    max_time=max(time, max_time)

print(max_time)
