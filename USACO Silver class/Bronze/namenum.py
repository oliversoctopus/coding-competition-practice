"""
ID: oliver.11
LANG: PYTHON3
TASK: namenum
"""

fin=open('namenum.in', 'r')
fin_read=fin.read()
fin.close()
possible_names=open('dict.txt', 'r')
p_n=possible_names.read()
names_list=p_n.split('\n')
#names_list=['GREG']

num=fin_read.strip()
#num='4734'

map_dict={2: ['A', 'B', 'C'],
          3: ['D', 'E', 'F'],
          4: ['G', 'H', 'I'],
          5: ['J', 'K', 'L'],
          6: ['M', 'N', 'O'],
          7: ['P', 'R', 'S'],
          8: ['T', 'U', 'V'],
          9: ['W', 'X', 'Y']}

names_list_dict={0: ['']}
for i in range(len(num)):
    names_list_dict[i]=[name[:i] for name in names_list]

def generate_names(num, name_list, start=''):
    if len(num)==0:
        if start in names_list:
            name_list.append(start)
        return name_list
    if start not in names_list_dict[len(start)]:
        return name_list
    n=num[0]
    possible_letters=map_dict[int(n)]
    for letter in possible_letters:
        temp=start+letter
        name_list=generate_names(num[1:], name_list, temp)
    return name_list

names=generate_names(num, [])
valid_names=''

for name in names:
    valid_names+=f'{name}\n'

if valid_names=='':
    valid_names='NONE\n'

fout=open('namenum.out', 'w')
fout.write(valid_names)
fout.close()
