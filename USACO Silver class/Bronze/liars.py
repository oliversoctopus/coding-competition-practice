n=int(input())
c_g=[]
c_l=[]
for i in range(n):
    cow=input().split()
    if cow[0]=='G':
        c_g.append(int(cow[1]))
    elif cow[0]=='L':
        c_l.append(int(cow[1]))

c_g.sort()
c_l.sort()

lower_b=-1 if c_g==[] else max(c_g)
upper_b=10**1000 if c_l==[] else min(c_l)

result=0
try:
    while lower_b>upper_b:
        result+=1
        if result>min(len(c_g), len(c_l)):
            result-=1
            raise FileNotFoundError
        for g_remove in range(result+1):
            l_remove=result-g_remove
            t_g=c_g[:-g_remove] if g_remove!=0 else c_g[:]
            t_l=c_l[l_remove:] if l_remove!=0 else c_l[:]
            if t_g==[]:
                t_g=[-1]
            if t_l==[]:
                t_l=[10**1000]
            t_greatest=max(t_g)
            t_least=min(t_l)
            if t_greatest<=t_least:
                raise FileNotFoundError
except FileNotFoundError:
    pass

print(result)
