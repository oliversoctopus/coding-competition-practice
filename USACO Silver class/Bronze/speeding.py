with open('speeding.in') as file:
    fin_read=file.read().strip()

fin_split=fin_read.split('\n')
first_line=[int(i) for i in fin_split[0].strip().split()]
segments=fin_split[1:]
print(fin_split)

road_seg=segments[:first_line[0]]
cow_seg=segments[first_line[0]:]
over_limit=0

road_seg=[seg.split() for seg in road_seg]
road_seg=[[int(i) for i in seg] for seg in road_seg]
cow_seg=[seg.split() for seg in cow_seg]
cow_seg=[[int(i) for i in seg] for seg in cow_seg]

road_ns=[]
cow_ns=[]
for r in road_seg:
    road_ns.extend([r[1]]*r[0])

for c in cow_seg:
    cow_ns.extend([c[1]]*c[0])

over_limit=0
for i in range(100):
    diff=cow_ns[i]-road_ns[i]
    over_limit=max(diff, over_limit)

with open('speeding.out', 'w') as file:
    file.write(str(over_limit))

