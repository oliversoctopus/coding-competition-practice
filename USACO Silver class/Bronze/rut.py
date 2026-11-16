# PRINT OUTPUT TO TERMINAL WHEN DONE
import sys
from math import inf

# TEST DATA MANIPULATION
#"""
fin='''6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1'''
fin_split=fin.split('\n')[1:]
data=[[i.split()[0], int(i.split()[1]), int(i.split()[2]), False] for i in fin_split]
result=[0]*len(data)
#"""

# SUBMISSION DATA MANIPULATION
'''
n=int(input())
data=[]
result=[0]*n

for i in range(n):
    a=input().split()
    data.append([a[0], int(a[1]), int(a[2]), False])
'''
grass_eaten=[]
prev_eaten=[]
old_cow=data[:]

def can_intersect(c1, c2):
    if c1[0]=='N' and c2[0]=='N':
        if c1[1]==c2[1]:
            ip=[c1[1], max(c1[2], c2[2])]
            return ip if dist(c1[1:], ip)>dist(c2[1:], ip) else False
        return False
    elif c1[0]=='N' and c2[0]=='E':
        if c2[1]<=c1[1] and c2[2]>=c1[2]:
            ip=[c1[1], c2[2]]
            return ip if dist(c1[1:], ip)>dist(c2[1:], ip) else False
        return False
    elif c1[0]=='E' and c2[0]=='N':
        if c1[1]<=c2[1] and c1[2]>=c2[2]:
            ip=[c2[1], c1[2]]
            return ip if dist(c1[1:], ip)>dist(c2[1:], ip) else False
        return False
    else:
        if c1[2]==c2[2]:
            ip=[max(c1[1], c2[1]), c1[2]]
            return ip if dist(c1[1:], ip)>dist(c2[1:], ip) else False
        return False

def dist(p1, p2):
    p1=list(map(int, p1))
    p2=list(map(int, p2))
    return int(((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)**0.5)

def is_complete(cows):
    new_cow=[]
    for cow in cows:
        if cow[3]==False:
            new_cow.append(cow[:-1])
    for i in range(len(new_cow)):
        cow=new_cow[i]
        temp=old_cow[:]
        temp.pop(i)
        for c in temp:
            if can_intersect(cow, c):
                return False
    return True

def simulate():
    prev_eaten=[]
    grass_eaten=[]
    while 1:
        for i in range(len(data)):
            cow=data[i]
            if cow[3]==True:
                break
            if cow[0]=='N':
                cow[2]+=1
            else:
                cow[1]+=1
            result[i]+=1
            data[i]=cow
            grass_eaten.append(cow[1:3])
        for i in range(len(data)):
            cow=data[i]
            coords=cow[1:3]
            if coords in prev_eaten:
                cow[3]=True
            data[i]=cow
        if is_complete(data):
            return
        prev_eaten=grass_eaten

simulate()
