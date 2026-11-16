import sys
sys.stdin=open('milkorder.in')
sys.stdout=open('milkorder.out', 'w')

n, m, k=map(int, input().split())
hierarchy=list(map(int, input().split()))
pos={}
order=[-1]*n
for i in range(k):
    a=list(map(int, input().split()))
    pos[a[0]]=a[1]
    order[a[1]-1]=a[0]-1
    if a[0]==1:
        print(a[1])
        exit()

def check():
    new_order=order.copy()
    cow_to_pos=[-1]*n
    for i in range(n):
        if order[i]!=-1:
            cow_to_pos[order[i]]=i

    h_idx=0
    i=0
    while i<n and h_idx<m:
        if cow_to_pos[hierarchy[h_idx]]!=-1:
            if i>cow_to_pos[hierarchy[h_idx]]:
                return False

            i=cow_to_pos[hierarchy[h_idx]]
            h_idx+=1
        else:
            while i<n and new_order[i]!=-1:
                i+=1

            if i==n:
                return False

            new_order[i]=hierarchy[h_idx]
            cow_to_pos[hierarchy[h_idx]]=i
            h_idx+=1
        i+=1

    return True

for i in range(n):
    if order[i]==-1:
        order[i]=0

        if check():
            print(i+1)
            break
    order[i]=-1
