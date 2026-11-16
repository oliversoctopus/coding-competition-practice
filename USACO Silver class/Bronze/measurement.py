with open('measurement.in') as file:
    fin=file.read().strip()
#fin='''4
#7 Mildred +3
#4 Elsie -1
#9 Mildred -1
#1 Bessie +2'''

fin_split=fin.split('\n')
entries=fin_split[1:]
new_entries=[]
cows={'Bessie': 7, 'Mildred': 7, 'Elsie': 7}

for entry in entries:
    entry=entry.split()
    new_entries.append([int(entry[0]), entry[1], int(entry[2])])

entries=sorted(new_entries)
leaders=[]
previous_leader=[]
max_production=-1
change=0

for entry in entries:
    cows[entry[1]]+=entry[2]
    max_production=max(cows.values())
    leaders=[]
    for key in cows.keys():
        if (cows[key]==max_production):
            leaders.append(key)

    leaders.sort()

    if leaders!=previous_leader:
        change+=1

    previous_leader=leaders[:]

#print(change)

with open('measurement.out', 'w') as file:
    file.write(str(change))
