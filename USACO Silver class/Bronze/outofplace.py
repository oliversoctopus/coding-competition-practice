import sys
sys.stdin=open('outofplace.in')
sys.stdout=open('outofplace.out', 'w')

def is_sorted(ls):
    for i in range(len(ls)-1):
        if not ls[i]<=ls[i+1]:
            return False
    return True

n=int(input())
cows=[]
for i in range(n):
    val=int(input())
    cows.append(val)

bessies=[]
for i in range(len(cows)):
    new=cows.copy()
    new.pop(i)
    if is_sorted(new):
        bessies.append(i)

def find_swaps(bessie):
    b_val=cows[bessie]
    b_right=None
    c_new=cows.copy()
    c_new.pop(bessie)
    
    for i in range(len(c_new)-1):
        if c_new[i]<=b_val<=c_new[i+1]:
            """
            if bessie<=i:
                b_right=i+1
            elif bessie>i:
                b_right=i+1
            """
            b_right=i+1
            break
        
    if b_right==None:
        if b_val>c_new[-1]:
            b_right=len(cows)-1
        elif b_val<c_new[0]:
            b_right=0

    prev=None
    swaps=0
    if b_right>bessie:
        for i in range(bessie+1, b_right+1):
            if cows[i]==b_val:
                break
            if prev!=cows[i]:
                swaps+=1
            prev=cows[i]
    else:
        for i in range(bessie-1, b_right-1, -1):
            if cows[i]==b_val:
                break
            if prev!=cows[i]:
                swaps+=1
            prev=cows[i]
    #if swaps==0:
        #print('0 Swaps')
        #swaps=1
    return swaps

minimum=100000000000
for bessie in bessies:
    a=find_swaps(bessie)
    if a<minimum:
        minimum=a
print(minimum)
