"""
ID: oliver.11
LANG: PYTHON3
TASK: crypt1
"""

fin=open('crypt1.in')
fin_read=fin.read().strip()
fin.close()

fin_split=fin_read.split('\n')
n=5
num_str=fin_split[1].split()
nums=[int(i) for i in num_str]

def in_n(num):
    for n in num:
        if n not in num_str:
            return False
    return True

def valid(nums):
    n1=nums[0]*100+nums[1]*10+nums[2]
    n2=nums[3]*10+nums[4]
    prod_str=str(n1*n2)
    p1_s=str(n1*nums[4])
    p2_s=str(n1*nums[3])
    total=list(set(prod_str))
    p1=list(set(p1_s))
    p2=list(set(p2_s))
    if len(prod_str)==4 and len(p1_s)==3 and len(p2_s)==3:
        if in_n(total) and in_n(p1) and in_n(p2):
            return True
    return False

def test_nums(nums, cur_num=[], valid_nums=0):
    if len(cur_num)==n:
        if valid(cur_num):
            valid_nums+=1
        return valid_nums
    for num in nums:
        temp=cur_num+[int(i) for i in list(str(num))]
        valid_nums=test_nums(nums, temp, valid_nums)
    return valid_nums

result=test_nums(nums)

fout=open('crypt1.out', 'w')
fout.write(str(result)+'\n')
fout.close()
