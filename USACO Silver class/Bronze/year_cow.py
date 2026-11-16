n=int(input())
years=["Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", \
       "Monkey", "Rooster", "Dog", "Pig", "Rat"]
cows={'Bessie': 0}
for i in range(n):
    c=input().split()
    c1, direction, animal, c2=[c[i] for i in [0, 3, 4, -1]]
    if direction=='previous':
        year=cows[c2]-1
        while years[year%12]!=animal:
            year-=1
    else:
        year=cows[c2]+1
        while years[year%12]!=animal:
            year+=1
    cows[c1]=year
print(abs(cows['Elsie']))
