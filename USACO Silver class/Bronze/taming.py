import sys
sys.stdin=open('taming.in')
sys.stdout=open('taming.out', 'w')

n=int(input())
log=[int(i) for i in input().split()]
if log[0]!=-1 and log[0]!=0:
    print(-1)
    exit()

determined=False
counter=-1
for i in range(n-1, 0, -1):
    if log[i]!=-1:
        if determined:
            if log[i]!=counter-1 and counter!=0:
                print(-1)
                exit()
        counter=log[i]
        determined=True
    elif determined and counter!=0:
        counter-=1
        if log[i]!=counter and log[i]!=-1:
            print(-1)
            exit()
        log[i]=counter
    else:
        determined=False

log[0]=0

maximum=0
minimum=0
for l in log:
    if l==0:
        minimum+=1
        maximum+=1
    elif l==-1:
        maximum+=1

print(minimum, maximum)
