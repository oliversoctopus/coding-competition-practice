import math
n, m=map(int, input().split())
s=input()
a=list(map(int, input().split()))
orig=sum(a)

loss=0
net=[-1]*n
spill=[]
if s[-1]=='R':
    net[0]+=1
if s[1]=='L':
    net[0]+=1
if net[0]==1:
    spill.append(0)
if s[-2]=='R':
    net[-1]+=1
if s[0]=='L':
    net[-1]+=1
if net[-1]==1:
    spill.append(-1)
    
for i in range(1, n-1):
    if s[i-1]=='R':
        net[i]+=1
    if s[i+1]=='L':
        net[i]+=1
    if net[i]==1:
        spill.append(i)

for i in spill:
    left=False
    right=False
    l_amnt=0
    r_amnt=0
    if s[i-1]=='R' and s[i]=='L':
        left=True
        l_amnt=10**100
    elif s[i+1]=='L' and s[i]=='R':
        right=True
        r_amnt=10**100
        
    for j in range(1, n):
        if left and right:
            break
        
        if not left:
            if net[i-j]==-1:
                left=True
                l_amnt+=a[i-j]
            else:
                l_amnt+=a[i-j]
                
        if not right:
            val=(i+j)%n
            if net[val]==-1:
                right=True
                r_amnt+=a[val]
            else:
                r_amnt+=a[val]
                
    loss+=min(m, l_amnt, r_amnt)

print(orig-loss)

