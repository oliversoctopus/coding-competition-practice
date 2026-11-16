given = open("race.in", "r")
result = open("race.out", "w")

"""
 1. Start off with track where X = inifnity (ex: K = 20; 1, 2, 3, 4, 5, 6)
 2. Adjust track to the value of X (ex: K = 20, X = 4;   1, 2, 3, 4, 5, 4)
 3. Add lost distance by more time at peak speed (ex: 1, 2, 3, 4, 5, 5, 4)
    ^- Don't have to account for reaching finish too fast; Bessie can run more time when slower

	note: if X does not restrict anything, then skip steps 2 and 3

Fastest (case 2): 69ms :|
Slowest (case 5): 467ms :(
"""

K, N = map(int, given.readline().split())

def aas(start, end): #simply add arithmetic series
	return (start + end)*(end - start + 1)//2

def edit_track(length, end_num): #get necessary values
	#e_sum = sum of terms in step 2 in order to see how much to add
	#length = how long list in step 1 is so I can calculate hgihest value and add it
	#q_max_seq = how many of the maximum number is there

	#account for the beginning part when the speed is < X
	e_sum = aas(1, end_num - 1)
	length -= (end_num - 1)

	#account for the ending part when speed is >= X
	if length%2 == 0:
		e_sum += aas(end_num, length//2 + end_num - 1)*2 #ex: sum([3, 4, 5, 5, 4, 3]) if X = 3
		max_seq = length//2 + end_num - 1 #ex: 5 in previous example
		q_max_seq = True #there will be two of the biggest number
	else:
		e_sum += aas(end_num, length//2 + end_num - 1)*2 + (length//2 + end_num)
		max_seq = length//2 + end_num
		q_max_seq = False

	return max_seq, q_max_seq, K - e_sum

def calc_add(h, q, leftover): #return how many more seconds to add
	result = 0
	while leftover > 0:
		#if two secs of max, then Bessie can go 1m/s faster; ex: 3, 4, 5, 5, 4, 3 -> can go 6
		if q:
			h += 1
			leftover -= h
			q = False
		#if one sec of max, then Bessie cannot go 1m/s faster; ex: 3, 4, 5, 4, 3 -> cannot go 6
		else:
			leftover -= h
			q = True
		result += 1
	return result

for _ in range(N):
	X = int(given.readline())

	end_r = int((-1 + (1+8*K)**0.5)//2) #get smallest last term
										#1 + 2 + 3 + ... + N >= X
										#(N + 1)*N = X
										#apply quadratic formula, round down

	if aas(1, end_r) != K: #correct end_r since rounding down
		end_r += 1

	if X >= end_r: #check the case where X doe not restrict anything
		result.write(str(end_r) + "\n")
		continue

	increment, increment_q, s = edit_track(end_r, X) #functionality explained in functions
	end_r += calc_add(increment, increment_q, s)     # :)

	result.write(str(end_r) + "\n")
