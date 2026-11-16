import sys
sys.stdin=open('cowtip.in', 'r')
sys.stdout=open('cowtip.out', 'w')

n=int(input())
cows=[]
for i in range(n):
    cows.append(list(map(int, input())))

new_c=[[i for i in j] for j in cows]

def flip(arr, r, c):
    for i in range(r+1):
        for j in range(c+1):
            if arr[i][j]==1:
                arr[i][j]=0
            else:
                arr[i][j]=1
    return arr

counter=0
for i in range(n-1, -1, -1):
    for j in range(n-1, -1, -1):
        if new_c[i][j]==1:
            new_c=flip(new_c, i, j)
            counter+=1

print(counter)
