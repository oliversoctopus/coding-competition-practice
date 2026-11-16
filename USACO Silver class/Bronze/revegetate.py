import sys
sys.stdin=open('revegetate.in')
sys.stdout=open('revegetate.out', 'w')

n, m=map(int, input().split())
adj={i:[] for i in range(n)}

for i in range(m):
    a, b=map(int, input().split())
    a, b=a-1, b-1
    adj[a].append(b)
    adj[b].append(a)

vals=[0]*n

for i in range(n):
    a_vals=[vals[j] for j in adj[i]]
    for j in range(1, 5):
        if j not in a_vals:
            vals[i]=j
            break
            

string=''
for v in vals:
    string+=str(v)

print(string)
