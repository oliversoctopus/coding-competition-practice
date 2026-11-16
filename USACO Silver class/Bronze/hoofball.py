import sys
sys.stdin=open('hoofball.in')
sys.stdout=open('hoofball.out', 'w')

n=int(input())
cows=list(map(int, input().split()))
cows.sort()

passto=[]
for i in range(len(cows)):
    c=cows[i]
    if i==0:
        passto.append('r')
    elif i==len(cows)-1:
        passto.append('l')
    else:
        dr=cows[i+1]-cows[i]
        dl=cows[i]-cows[i-1]
        if dr<dl:
            passto.append('r')
        else:
            passto.append('l')
#print(passto)

blocks=[]
prev_c=None
cur_block=[]
for i in range(len(cows)):
    if prev_c==None:
        prev_c=passto[i]
        cur_block=[passto[i]]
    else:
        cur=passto[i]
        if prev_c=='l' and cur=='r':
            blocks.append(cur_block)
            cur_block=[cur]
        else:
            cur_block.append(passto[i])
        prev_c=cur
if cur_block!=[]:
    blocks.append(cur_block)

counter=0
for block in blocks:
    if block.count('l')>1 and block.count('r')>1:
        counter+=2
    else:
        counter+=1
print(counter)
