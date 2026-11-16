"""
ID: oliver.11
LANG: PYTHON3
TASK: milk
"""

fin=open('milk.in', 'r')
fin_read=fin.read().strip()
fin.close()

fin_split=fin_read.strip().split('\n')
line_1=fin_split[0].split(' ')
n=int(line_1[0])
fin_split.pop(0)

prices=[]
units={}

for farmer in fin_split:
    f_split=farmer.strip().split(' ')
    prices.append(int(f_split[0]))
    try:
        units[int(f_split[0])]+=int(f_split[1])
    except KeyError:
        units[int(f_split[0])]=int(f_split[1])

prices=list(set(prices))
result=0

for price in prices:
    unit=units[price]
    if unit>=n:
        result+=n*price
        break
    n-=unit
    result+=price*unit

fout=open('milk.out', 'w')
fout.write(f'{result}\n')
fout.close()
