from itertools import permutations
import sys

sys.stdin=open('lineup.in')
sys.stdout=open('lineup.out', 'w')

n=int(input())
cow_connections=[]
for i in range(n):
    cow_connections.append(input().split(' must be milked beside '))

cows=['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']
perms=permutations(cows)

def beside(c1, c2, order):
    c1_i=order.index(c1)
    c2_i=order.index(c2)
    if abs(c1_i-c2_i)==1:
        return True
    return False

def valid(order):
    for c in cow_connections:
        if not beside(c[0], c[1], order):
            return False
    return True

result=[]
for p in perms:
    if valid(p):
        result=p
        break

for r in result:
    print(r)
