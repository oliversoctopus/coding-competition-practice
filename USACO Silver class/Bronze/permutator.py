#from itertools import permutations
n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))

def permutations(ls, answer=0.1, cur=[]):
    if ls==[]:
        result=find_sum(a, cur)
        if answer==0.1:
            return result
        else:
            return min(answer, result)
    for i in range(len(ls)):
        temp=cur[:]
        temp.append(ls[i])
        new=ls[:]
        new.pop(i)
        answer=permutations(new, answer, temp)
    return answer

def find_sum(a, b):
    products=[]
    for i in range(n):
        products.append(a[i]*b[i])
    psum=[0]
    for i in range(len(products)):
        psum.append(psum[-1]+products[i])
    #print(psum)
    summ=0
    for i in range(n+1):
        for j in range(i+1, n+1):
            summ+=psum[j]-psum[i]
    return summ

answer=permutations(b)
print(answer)

