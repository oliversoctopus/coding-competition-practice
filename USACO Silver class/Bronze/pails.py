import sys

sys.stdin=open('pails.in')
sys.stdout=open('pails.out', 'w')

x, y, m=map(int, input().split())

max_x=m//x
max_milk=-1
for i in range(max_x+1):
    remaining=m-x*i
    rem=remaining%y
    milk=m-rem
    max_milk=max(max_milk, milk)

print(max_milk)
