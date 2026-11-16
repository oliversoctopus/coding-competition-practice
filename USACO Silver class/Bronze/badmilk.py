import sys

sys.stdin=open('badmilk.in')
sys.stdout=open('badmilk.out', 'w')

n, m, d, s=[int(i) for i in input().split()]
people={}
sick_times=[]
for _ in range(d):
    event=[int(j) for j in input().split()]
    if event[0] not in people.keys():
        people[event[0]]={event[1]: [event[2]]}
    else:
        person=people[event[0]]
        if event[1] not in person.keys():
            person[event[1]]=[event[2]]
        else:
            person[event[1]].append(event[2])
#print(people)

possible_milks=None
people_new=people
doses=0
for _ in range(s):
    t=[int(j) for j in input().split()]
    p=t[0]
    time=t[1]
    person=people[p]
    poss_milk=[]
    people_new.pop(p)
    doses+=1
    for key, value in person.items():
        if min(value)<time:
            poss_milk.append(key)
    if possible_milks==None:
        possible_milks=set(poss_milk)
    else:
        possible_milks=possible_milks&set(poss_milk)
#print(possible_milks)

original=doses
for m in possible_milks:
    dose_m=original
    for p, event in people_new.items():
        if m in event.keys():
            dose_m+=1
    doses=max(dose_m, doses)

print(doses)
