import sys

sys.stdin = open("citystate.in", "r")
sys.stdout = open("citystate.out", "w")

n = int(input())
count = dict() #string and its count

for i in range(n):
    inp = input().split()
    city = inp[0]
    state = inp[1]
    if city[:2] != state:
        key = city[:2] + state
        if key not in count:
            count[key]=0
        count[key]+=1

ret = 0
for key in count:
    otherKey = key[2:] + key[:2] #swap city letters and state
    if otherKey in count:
        ret += count[key] * count[otherKey]

#note that we have double-counted each pair
print(ret//2)

#in python, barely fits within the time limits
