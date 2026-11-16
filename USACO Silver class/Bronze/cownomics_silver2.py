import sys
import math

def main():
    sys.stdin=open('cownomics.in')
    sys.stdout=open('cownomics.out', 'w')

    n, m=map(int, input().split())
    spot=[]
    plain=[]
    for i in range(n):
        spot.append(input().strip())
    for i in range(n):
        plain.append(input().strip())

    different=[False]*m
    unique=0
    for i in range(m):
        temp=set()
        flag=0
        for j in range(n):
            temp.add(spot[j][i])
        for j in range(n):
            if plain[j][i] in temp:
                flag=1
                break
        if flag:
            continue
        different[i]=True
        unique+=1
    counter=0
    for i in range(unique):
        counter+=(((m-2-i)*(m-1-i))//2)

    for i in range(m-2):
        if different[i]:
            continue
        for j in range(i+1, m-1):
            if different[j]:
                continue
            for k in range(j+1, m):
                if different[k]:
                    continue
                flag=False
                for l in range(n):
                    for o in range(n):
                        if spot[l][i]==plain[o][i] and spot[l][j]==plain[o][j] and spot[l][k]==plain[o][k]:
                            flag=True
                            break
                    if flag:
                        break
                if not flag:
                    counter+=1
    print(counter)
main()
