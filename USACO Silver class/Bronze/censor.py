with open('censor.in') as file:
    fin=file.read().strip()
#fin='''moomoomoomooo
#moo'''

fin_split=fin.split('\n')
T=fin_split[1]
S=fin_split[0]
o=''

for i in range(len(S)):
    o += S[i]
    if len(o) >= len(T):
        if o[-len(T):] == T:
            o = o[:-len(T)]

#print(o)

with open('censor.out', 'w') as file:
    file.write(o)
