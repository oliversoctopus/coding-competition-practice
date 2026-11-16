import math
n=int(input())
s=input()
orig_count=0
prev=None
for i in s:
    if prev!=None:
        if i==prev and i!='F':
            orig_count+=1
    prev=i


blocks=[]
cur=['', '', 0]
for char in s:
    if char=='F':
        cur[2]+=1
    elif (char=='B' or char=='E') and cur[2]!=0:
        cur[1]=char
        blocks.append(cur)
        cur=[char, '', 0]
    else:
        cur[0]=char
if cur[1]=='' and cur[2]!=0:
    blocks.append(cur)

amnts=[]
for b in blocks:
    if (b[0]=='' or b[1]=='') and not (b[0]=='' and b[1]==''):
        amnts.append([0, 1, b[2]])
    elif b[1]=='' and b[0]=='':
        amnts.append([0, 1, b[2]-1])
    else:
        if b[0]!=b[1]:
            length=b[2]
            val=length%2
            amnts.append([val, 2, length])
        else:
            length=b[2]
            val=1 if length%2==0 else 0
            amnts.append([val, 2, length+1])

nogap=False
extra=0
for a in amnts:
    if a[1]==1:
        nogap=True
    else:
        orig_count+=a[0]
    extra+=a[2]-a[0]

step=2 if nogap==False else 1
amnt=math.floor(extra/step)+1
print(amnt)
for i in range(orig_count, extra+orig_count+1, step):
    print(i)
