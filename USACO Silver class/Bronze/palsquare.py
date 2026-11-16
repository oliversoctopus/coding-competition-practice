"""
ID: oliver.11
LANG: PYTHON3
TASK: palsquare
"""
import math

#fin=open('palsquare.in', 'r')
#fin_read=fin.read().strip()
#fin.close()
fin_read=20

b=int(fin_read)
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

result=''

for i in range(1, 301):
    b_i=base_b(i, b)
    b_sqr=base_b(i**2, b)
    if is_palindrome(b_sqr):
        result+=f'{b_i} {b_sqr}\n'

print(result)

#fout=open('palsquare.out', 'w')
#fout.write(result)
#fout.close()
