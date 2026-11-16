n=int(input())
values=list(map(int, input().split()))

things=[]
for v in values:
    if v not in things:
        things.append(v)
print(len(things))
