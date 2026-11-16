import sys

sys.stdin=open('circlecross.in')
sys.stdout=open('circlecross.out', 'w')

cow_crosses=list(input())
alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ'

pairs=0
for letter in alphabet:
    occ_1=cow_crosses.index(letter)
    temp=cow_crosses[:]
    temp.remove(letter)
    occ_2=temp.index(letter)+1
    between=cow_crosses[occ_1+1:occ_2]
    only_one=[]
    for i in between:
        if i not in only_one:
            only_one.append(i)
        else:
            only_one.remove(i)
    pairs+=len(only_one)

pairs//=2
print(pairs)
