import sys
sys.stdin=open('art.in')
sys.stdout=open('art.out', 'w')

n=int(input())
canvas=[]
for i in range(n):
    canvas.append(input())

max_mins={}
for i in range(n):
    for j in range(n):
        color=canvas[j][i]
        if color=='0':
            continue
        if color not in max_mins:
            max_mins[color]=[i, j, i, j] # min x, min y, max x, max y
        else:
            cur=max_mins[color]
            max_mins[color]=[min(cur[0], i), min(cur[1], j), \
                 max(cur[2], i), max(cur[3], j)]
#print(max_mins)
            
def covers(c, bounds):
    covered=[]
    for i in range(bounds[0], bounds[2]+1):
        for j in range(bounds[1], bounds[3]+1):
            color=canvas[j][i]
            if color!=c:
                if color not in covered:
                    covered.append(color)
    return covered

poss_colors=list(max_mins.keys())
for c, bounds in max_mins.items():
    covered=covers(c, bounds)
    new_c=[]
    for c in poss_colors:
        if c not in covered:
            new_c.append(c)
    poss_colors=new_c
print(len(poss_colors))
