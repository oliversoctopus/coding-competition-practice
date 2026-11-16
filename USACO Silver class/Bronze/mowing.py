with open('mowing.in') as file:
    fin=file.read().strip()
#fin='''6
#N 10
#E 2
#S 3
#W 4
#S 5
#E 8'''

fin_split=fin.split('\n')
directions=fin_split[1:]
coords=[[0, 0]]

distances=[]

for direction in directions:
    d=direction.split()[0]
    s=int(direction.split()[1])
    for i in range(s):
        cur_coord=coords[0]
        new_coord=[cur_coord[0], cur_coord[1]]
        if d=='N':
            new_coord[1]+=1
        elif d=='S':
            new_coord[1]-=1
        elif d=='E':
            new_coord[0]+=1
        else:
            new_coord[0]-=1
        try:
            index=coords.index(new_coord)
            dist=index+1
            distances.append(dist)
        except ValueError:
            pass
        coords.insert(0, new_coord)

if len(distances)!=0:
    result=min(distances)
else:
    result=-1

#print(result)

with open('mowing.out', 'w') as file:
    file.write(str(result))
