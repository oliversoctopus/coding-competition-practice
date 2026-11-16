import sys
sys.stdin = open("tracing.in", "r")
sys.stdout = open("tracing.out", "w")

n,t = [int(i) for i in input().split()]
cows = input()
contacts = []
for _ in range(t):
	contacts.append([int(i) for i in input().split()])
contacts.sort() #sort by first element, t, to get all contacts in chronological order

def simulate(pz,k,contacts): #knowing the patient 0, k, and the log of contacts, output a string of 0's and 1's of the cow infections as a result
	infected = [pz] #numbers of infected cows
	cowks = dict((cow,0) for cow in range(1,n+1)) #stores the number of hooveshakes done by each cow
	for contact in contacts:
		time,x,y = contact
		if x in infected and y in infected:
			cowks[x]+=1 #if both are infected, just increase their shake count
			cowks[y]+=1
		elif x in infected and cowks[x]<k:
			infected.append(y)
			cowks[x]+=1
		elif y in infected and cowks[y]<k:
			infected.append(x)
			cowks[y]+=1
		#otherwise (if neither are infected or if the infected cow reached k), nothing changes
	res = ['0' for _ in range(n)]
	for cow in infected:
		res[cow-1]='1'
	return ''.join(res)

ks = [] #possible values of k
pzs = [] #possible patient zeroes
for pz in range(1,n+1): #trying out every patient 0 candidate
	for k in range(n+2):
		if k in ks and pz in pzs: #no reason to check if both k and pz are already recorded - saves time. In python, case 13 barely fits within the time limit - 39998 ms. TLE if we didn't check
			continue
		if simulate(pz,k,contacts)==cows: #if the simulation with these values matches the actual result
			ks.append(k)
			if pz not in pzs: #now that we know this patient zero could work with at least one value of k, we can add it as a possiblity
				pzs.append(pz)


x = len(pzs)
y = min(ks)
z = max(ks)
if z>n: #k is infinity if when it is n+1, the result is the same as cows. Means it could increase further with no bound
	z = 'Infinity'
print(x,y,z)
