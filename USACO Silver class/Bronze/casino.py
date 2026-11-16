t=int(input())
cases=[]
def intify():
    return list(map(int, input().split()))
for i in range(t):
    n, m=intify()
    cards=[]
    for i in range(n):
        card=intify()
        cards.append(card)
    cases.append([[n, m], cards])

def card_add(c1, c2):
    summ=0
    for i in range(len(c1)):
        summ+=abs(c1[i]-c2[i])
    return summ

for c in cases:
    n, m=c[0]
    cards=c[1]
    total=0
    for i in range(m):
        column=[]
        for j in range(n):
            column.append(cards[j][i])
        column.sort()
        for j in range(n):
            total+=column[j]*j
            total-=column[j]*(n-j-1)
    print(total)
