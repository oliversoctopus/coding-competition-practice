with open('lostcow.in') as file:
    fin_read=file.read().strip()
#fin_read='3 6'

fin_split=list(map(int, fin_read.split()))
x=fin_split[0]
y=fin_split[1]

start=x<y
def not_there(x, y):
    if x==y:
        return False
    if start==True:
        if x>y:
            return False
    elif start==False:
        if x<y:
            return False
    return True
dist=0
travel=1
offset=0
x_old=x
while not_there(x, y):
    x=x_old+travel
    dist+=abs(travel)+offset
    offset=abs(travel)
    travel*=-2
if start==True:
    dist-=max(0, x-y)
elif start==False:
    dist-=max(0, y-x)

with open('lostcow.out', 'w') as file:
    file.write(str(dist))
