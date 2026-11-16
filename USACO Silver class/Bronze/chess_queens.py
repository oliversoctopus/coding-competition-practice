from itertools import permutations

def f(x):
    return 0 if x=='.' else 1
chessboard=[[f(x) for x in list(input())] for i in range(8)]

arrangements=0
for queens in permutations(range(8)):
    good=True
    for c in range(8):
        if chessboard[queens[c]][c]==1:
            good=False
            break
    coord_sum=[]
    for i in range(8):
        a=queens[i]+i
        if a in coord_sum:
            good=False
            break
        coord_sum.append(a)
    if good:
        arrangements+=1

print(arrangements)
