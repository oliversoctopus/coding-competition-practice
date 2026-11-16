with open('blist.in') as file:
    fin_read=file.read().strip()

fin_split=fin_read.split('\n')
cows=fin_split[1:]
cows=[list(map(int, i.split())) for i in cows]
cows=sorted(cows)

b_n=0
def within_bounds(cow, n):
    start=cow[0]
    end=cow[1]
    if start<=n and end>=n:
        return True
    return False

latest_time=-1
for c in cows:
    if c[1]>latest_time:
        latest_time=c[1]

for i in range(1, latest_time+1):
    b_needed=0
    for c in cows:
        if within_bounds(c, i):
            b_needed+=c[2]
    if b_needed>b_n:
        b_n=b_needed

with open('blist.out', 'w') as file:
    file.write(str(b_n))
