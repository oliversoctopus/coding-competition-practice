# CHANGE WRITE NAME FROM RESULT TO ACTUAL OUTPUT VAR WHEN DONE

with open('traffic.in') as file:
    fin_read=file.read().strip()

fin_split=fin_read.split('\n')
segments=fin_split[1:]
seg_new=[]

for seg in segments:
    seg=seg.split()
    seg_new.append([seg[0], int(seg[1]), int(seg[2])])

combined=seg_new

min_range=-1
max_range=100000
for index in range(1, len(combined)+1):
    i=-index
    seg=combined[i]
    indicator=seg[0]
    min_r=seg[1]
    max_r=seg[2]
    if indicator=='none':
        min_range=max(min_r, min_range)
        max_range=min(max_r, max_range)
    elif indicator=='on':
        min_range-=max_r
        max_range-=min_r
        if min_range<0:
            min_range=0
    elif indicator=='off':
        min_range+=min_r
        max_range+=max_r

before=[min_range, max_range]

min_range=-1
max_range=100000
start=True
for i in range(len(combined)):
    seg=combined[i]
    indicator=seg[0]
    min_r=seg[1]
    max_r=seg[2]
    if indicator=='none':
        min_range=max(min_r, min_range)
        max_range=min(max_r, max_range)
    elif indicator=='off' and not start:
        min_range-=max_r
        max_range-=min_r
        if min_range<0:
            min_range=0
    elif indicator=='on' and not start:
        min_range+=min_r
        max_range+=max_r
    start=False

after=[min_range, max_range]
result=f'''{before[0]} {before[1]}
{after[0]} {after[1]}'''
        

with open('traffic.out', 'w') as file:
    file.write(result)
