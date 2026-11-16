"""
ID: oliver.11
LANG: PYTHON3
TASK: wormhole
"""
import math

#fin=open('wormhole.in')
#fin_read=fin.read().strip()
#fin.close()
fin_read='''6
1 11 
20 11
17 11 
22 11 
25 11
26 11'''

fin_split=fin_read.split('\n')
wormholes=fin_split[1:]
wormhole_split=[w.split() for w in wormholes]
hole_coords=[[int(i) for i in w] for w in wormhole_split]

def copyList(newList, oldList):
    for i in oldList:
        newList.append(i)

def copyPairs(newPair, oldPair):
    for i in range(len(oldPair)):
        a1=oldPair[i][0]
        a2=oldPair[i][1]
        newPair.append([a1,a2])

pairs=[]
def createPairs(aList, oldPairs=[]):
    if len(aList)==2:
        temp=[]
        copyPairs(temp,oldPairs)
        temp.append(aList)
        pairs.append(temp)
        return
    for i in range(len(aList)-1):
        shorterList=[]
        copyList(shorterList,aList)
        currentPairs=[]
        copyPairs(currentPairs,oldPairs)
        currentPairs.append([aList[0],aList[i+1]])
        shorterList.pop(i+1)
        shorterList.pop(0)
        createPairs(shorterList,currentPairs)
a = range(len(hole_coords))
createPairs(a)

def fac(x):
    prod=1
    for i in range(1, x+1):
        prod*=i
    return prod

def comb(n, r):
    return fac(n)/fac(r)/fac(n-r)

def find_pairs(n):
    n_old=n
    result=1
    while n>1:
        result*=comb(n, 2)
        n-=2
    return result/fac(math.ceil(n_old/2))



#fout=open('wormhole.out', 'w')
#fout.write(str(result)+'\n')
#fout.close()
