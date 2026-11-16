import sys

sys.stdin=open('cownomics.in')
sys.stdout=open('cownomics.out', 'w')

n, m=map(int, input().split())
spotty=[]
plain=[]
for i in range(n):
    spotty.append(input())
for i in range(n):
    plain.append(input())

positions=0
for i in range(len(spotty[0])):
    char_spot=[]
    char_plain=[]
    for spot in spotty:
        char=spot[i]
        if char not in char_spot:
            char_spot.append(char)
    for p in plain:
        char=p[i]
        if char not in char_plain:
            char_plain.append(char)
    char_spot=set(char_spot)
    char_plain=set(char_plain)
    if char_spot&char_plain==set():
        positions+=1

print(positions)
