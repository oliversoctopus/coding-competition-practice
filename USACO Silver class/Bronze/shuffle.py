with open('shuffle.in') as file:
    fin_read=file.read().strip()
#fin_read='''5
#3 5 2 9 1 6 7 4 8
#1 2 3 4 5 6 7 8 9 '''

fin_split=fin_read.split('\n')
cow_ids=fin_split[2].split()
shuffle=list(map(int, fin_split[1].split()))
rev_shuffle={}

for i in range(len(shuffle)):
    element=shuffle[i]
    rev_shuffle[element]=i+1

for i in range(3):
    new_cow=[0 for _ in cow_ids]
    for i in range(len(cow_ids)):
        cow=cow_ids[i]
        new_spot=rev_shuffle[i+1]
        new_cow[new_spot-1]=cow
    cow_ids=new_cow
    
#print(cow_ids)
result=''
for cow in cow_ids:
    result+=cow+'\n'

result=result.strip()
#print(result)

with open('shuffle.out', 'w') as file:
    file.write(str(result))
