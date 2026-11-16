# CHANGE RESULT TO OUTPUT VAR WHEN DONE
with open('cbarn.in') as file:
    fin=file.read().strip()

fin_split=fin.split('\n')
r=list(map(int, fin_split[1:]))
r_circle=r*2

min_dist=1000000000000000000
for i in range(len(r)):
    dist=0
    for j in range(len(r)):
        index=j+i
        elem=r_circle[index]
        dist+=elem*j
    min_dist=min(min_dist, dist)

with open('cbarn.out', 'w') as file:
    file.write(str(min_dist))
