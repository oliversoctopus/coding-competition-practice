fin=open('cowsignal.in')
fin_read=fin.read().strip()
fin.close()

fin_split=fin_read.split('\n')
first_line=fin_split[0].strip().split()
K=int(first_line[2])

lines=fin_split[1:]

def line_mult(line, k):
    enlarged=''
    for char in line:
        enlarged+=char*k
    enlarged+='\n'
    return enlarged*k

result=''

for line in lines:
    new=line_mult(line, K)
    result+=new

fout=open('cowsignal.out', 'w')
fout.write(result)
fout.close()
