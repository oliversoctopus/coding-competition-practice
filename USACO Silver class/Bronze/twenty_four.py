from itertools import permutations
n=int(input())
hands=[]
for i in range(n):
    cur=[int(input()) for j in range(4)]
    hands.append(cur)

poss_ops=['*', '-', '+', '/']
def positions(all_pos=[], cur_pos=[]):
    if len(cur_pos)==3:
        all_pos.append(cur_pos)
        return all_pos
    for operation in poss_ops:
        temp=cur_pos[:]
        temp.append(operation)
        all_pos=positions(all_pos[:], temp)
    return all_pos

def calc(mode, op1, op2):
    if mode=='*':
        return op1*op2
    elif mode=='-':
        return op1-op2
    elif mode=='+':
        return op1+op2
    else:
        if op2==0 or op1%op2!=0:
            return False
        return op1/op2

hands=[sorted(hand) for hand in hands]

def solve_hand(hand):
    res=-1
    for p in permutations(hand):
        for i in poss_ops:
            for j in poss_ops:
                for k in poss_ops:
                    a=True
                    t1=calc(i, p[0], p[1])
                    if t1==False:
                        a=False
                    t2=calc(j, t1, p[2])
                    if t2==False:
                        a=False
                    t3=calc(k, t2, p[3])
                    if t3==False:
                        a=False
                    if t3<=24 and a:
                        res=max(res, t3)

                    b=True
                    c1=calc(i, p[0], p[1])
                    if not c1:
                        b=False
                    c2=calc(j, p[2], p[3])
                    if not c2:
                        b=False
                    c3=calc(k, c1, c2)
                    if c3==False:
                        b=False
                    if c3<=24 and b:
                        res=max(res, c3)
    print(int(res))

for hand in hands:
    solve_hand(hand)
