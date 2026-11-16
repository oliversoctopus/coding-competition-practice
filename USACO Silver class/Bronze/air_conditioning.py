n, m=map(int, input().split())
cows=[]
for i in range(n):
    cows.append([int(i) for i in input().split()])
acs=[]
for i in range(m):
    acs.append([int(i) for i in input().split()])

def ac_combs(combs, cur):
    if len(cur)==m:
        combs.append(cur)
        return combs
    for i in range(2):
        temp=cur[:]
        temp.append(i)
        combs=ac_combs(combs, temp)
    return combs

combs=ac_combs([], [])
smallest=10**1000
def calc_vals(ac_comb):
    act_acs=[acs[i] for i in range(m) if ac_comb[i]==1]
    stalls=[0]*100
    new=[]
    cost=sum([a[3] for a in act_acs])
    if cost>=smallest:
        return False, None
    for c in cows:
        cooldown=[]
        for i in range(c[0], c[1]+1):
            cur_cool=0
            for ac in act_acs:
                if ac[0]<=i<=ac[1]:
                    cur_cool+=ac[2]
            cooldown.append(cur_cool)
        if min(cooldown)<c[2]:
            return False, None
    return True, cost

for c in combs:
    valid, cost=calc_vals(c)
    if valid:
        smallest=cost

print(smallest)
