"""
ID: oliver.11
LANG: PYTHON3
TASK: barn1
"""
# UNCOMMENT THE FIN AND FOUT STRINGS BEFORE SUBMITTING

fin=open('barn1.in', 'r')
fin_read=fin.read().strip()
fin.close()

fin_split=fin_read.split('\n')
cow_stalls=fin_split[1:]
m,s,c=[int(i) for i in fin_split[0].strip().split()]
stalls_int=[int(n) for n in cow_stalls]
stalls_int=sorted(stalls_int)

final_gap=s-stalls_int[-1]
front_gap=stalls_int[0]-1
gaps=[]
for i in range(len(stalls_int)-1):
    stall_1=stalls_int[i]
    stall_2=stalls_int[i+1]
    gaps.append(stall_2-stall_1-1)

total_gap=0
val=m if m<c else c
for i in range(val-1):
    max_gap=max(gaps)
    gaps.remove(max_gap)
    total_gap+=max_gap

result=s-total_gap-final_gap-front_gap

fout=open('barn1.out', 'w')
fout.write(str(result)+'\n')
fout.close()
