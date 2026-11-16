"""
ID: oliver.11
LANG: PYTHON3
TASK: dualpal
"""
import math

fin=open('dualpal.in', 'r')
fin_read=fin.read().strip()
fin.close()
fin_split=fin_read.strip().split(' ')
n=int(fin_split[0])
s=int(fin_split[1])


alphabet_map={10:'A',11:'B',12:'C', 13:'D', 14:'E', 15:'F', 16:'G',
              17:'H', 18:'I', 19:'J', 20:'K'}

def base_b(num, b, result='', power=None):
    if power==None:
        power=math.floor(math.log(num, b))
    if power==0:
        return result+str(num) if num<10 else result+alphabet_map[num]
    res=num//b**power
    rem=num%b**power
    if res>9:
        res=alphabet_map[res]
    result+=str(res)
    return base_b(rem, b, result, power-1)

def is_palindrome(num):
    for i in range(math.ceil(len(num)/2)):
        right=-i-1
        if num[i]!=num[right]:
            return False
    return True

def check_dualpal(num):
    palindromic=0
    for i in range(2, 11):
        if is_palindrome(base_b(num, i)):
            palindromic+=1
        if palindromic>=2:
            return True
    return False

counter=0
result=''

while counter<n:
    s+=1
    if check_dualpal(s):
        counter+=1
        result+=f'{s}\n'

fout=open('dualpal.out', 'w')
fout.write(result)
fout.close()
