import sys

sys.stdin=open('guess.in')
sys.stdout=open('guess.out', 'w')

n=int(input())
animals=[]
for i in range(n):
    animals.append(input().split())

traits=[]
for a in animals:
    traits.append(a[2:])

def find_sim(ls1, ls2):
    s1=set(ls1)
    s2=set(ls2)
    return len(list(s1&s2))

answers=1
for i in range(len(traits)):
    for j in range(i+1, len(traits)):
        new_ans=1+find_sim(traits[i], traits[j])
        answers=max(answers, new_ans)

print(answers)
