"""
ID: oliver.11
LANG: PYTHON3
TASK: combo
"""

fin=open('combo.in')
fin_read=fin.read()
fin.close()

fin_read=fin_read.strip().split('\n')

n=int(fin_read[0])
comb1=[int(i) for i in fin_read[1].split()]
comb2=[int(i) for i in fin_read[2].split()]
total=250

overlap=1

def dist(n1, n2):
    if n1>n2:
        temp=n2
        n2=n1
        n1=temp
    wrap_n2=n2-n
    wrap_dist=abs(wrap_n2-n1)
    norm_dist=abs(n2-n1)
    return min(wrap_dist, norm_dist)

for i in range(3):
    n1=comb1[i]
    n2=comb2[i]
    distance=dist(n1, n2)
    n_overlap=-distance+5
    overlap*=max(n_overlap, 0)

result=total-overlap
if n<5:
    result=n**3

fout=open('combo.out', 'w')
fout.write(str(result)+'\n')
fout.close()
