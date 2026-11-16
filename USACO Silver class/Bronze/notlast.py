import sys
sys.stdin=open('notlast.in')
sys.stdout=open('notlast.out', 'w')
n=int(input())
cows={}
for i in range(n):
    p=input().split()
    if p[0] in cows:
        cows[p[0]]+=int(p[1])
    else:
        cows[p[0]]=int(p[1])
s=sorted(set(cows.values()))
if len(s)==1:
    print('Tie')
else:
    second_last=[]
    for name in cows.keys():
        if cows[name]==s[1]:
            second_last.append(name)
    if len(second_last)==1:
        print(second_last[0])
    else:
        print('Tie')
