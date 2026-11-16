with open('square.in') as file:
    fin_read=file.read().strip()
#fin_read='''6 6 8 8
#1 8 4 9'''

fin_split=fin_read.split('\n')
pasture1=fin_split[0]
pasture2=fin_split[1]
p1=[pasture1.split()[0:2], pasture1.split()[2:]]
p2=[pasture2.split()[0:2], pasture2.split()[2:]]

p1=[list(map(int, i)) for i in p1]
p2=[list(map(int, i)) for i in p2]

x=[]
y=[]
for p in [p1, p2]:
    for coord in p:
        x.append(coord[0])
        y.append(coord[1])

width=max(x)-min(x)
length=max(y)-min(y)
side=max(width, length)
area=side**2

with open('square.out', 'w') as file:
    file.write(str(area))
