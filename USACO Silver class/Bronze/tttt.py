with open('tttt.in') as file:
    fin=file.read().strip()

def column(index, arr):
    col=[]
    for row in arr:
        col.append(row[index])
    return col

def letters_in_list(list):
    letters=[]
    for i in list:
        if i not in letters:
            letters.append(i)
    return letters

fin_split=fin.split('\n')
ttt_arr=[list(row) for row in fin_split]
lines=[ttt_arr[0],
ttt_arr[1],
ttt_arr[2],
column(0, ttt_arr),
column(1, ttt_arr),
column(2, ttt_arr),
[ttt_arr[0][0], ttt_arr[1][1], ttt_arr[2][2]],
[ttt_arr[0][2], ttt_arr[1][1], ttt_arr[2][0]]
       ]

lines=list(map(sorted, map(letters_in_list, lines)))
individual=[]
team=[]
for line in lines:
    if len(line)==1:
        if line not in individual:
            individual.append(line)
    elif len(line)==2:
        if line not in team:
            team.append(line)

result=f'''{len(individual)}
{len(team)}'''

with open('tttt.out', 'w') as file:
    file.write(result)
