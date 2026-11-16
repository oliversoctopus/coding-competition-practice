n=int(input())
bacteria=list(map(int, input().split()))

counter=0
length=len(bacteria)
for i in range(length):
    n=bacteria[i]
    val=sum([-bacteria[j]*(i-j+1) for j in range(i)])
    bacteria[i]+=val
    counter+=abs(val+n)

print(counter)
