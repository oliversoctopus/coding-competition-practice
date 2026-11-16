import sys

"""
read='''5
8 5
2 1 7 4
4 2
5 4
2 2 5 4
3 3
1 8
0 3 1 6
1 5
8 1
3 0 6 1
5 1
8 10
4 5 7 8
8 5'''
read_s=read.split('\n')[1:]
test_case=[]
cases=[]
for line in read_s:
    row=list(map(int, line.split()))
    test_case.append(row)
    if len(test_case)==3:
        cases.append(test_case)
        test_case=[]
"""

#"""
n=int(input())
test_case=[]
cases=[]
for i in range(3*n):
    row=list(map(int, input().split()))
    test_case.append(row)
    if len(test_case)==3:
        cases.append(test_case)
        test_case=[]
#"""

def test_case(info):
    t2_w, t2_h=info[2]
    t1=info[1]
    w, h=info[0]

    t1_w=t1[2]-t1[0]
    t1_h=t1[3]-t1[1]
    if t1_w+t2_w>w and t1_h+t2_h>h:
        return -1

    dist_move=10**1000
    for i in range(4):
        if i==0:
            x_dist=t2_w-t1[0] if t1_w+t2_w<=w else 10**1000
            y_dist=t2_h-t1[1] if t1_h+t2_h<=h else 10**1000
        elif i==1:
            x_dist=t2_w-t1[0] if t1_w+t2_w<=w else 10**1000
            y_dist=t1[3]-(h-t2_h) if t1_h+t2_h<=h else 10**1000
        elif i==2:
            x_dist=t1[2]-(w-t2_w) if t1_w+t2_w<=w else 10**1000
            y_dist=t1[3]-(h-t2_h) if t1_h+t2_h<=h else 10**1000
        else:
            x_dist=t1[2]-(w-t2_w) if t1_w+t2_w<=w else 10**1000
            y_dist=t2_h-t1[1] if t1_h+t2_h<=h else 10**1000
        dist_move=max(min(dist_move, x_dist, y_dist), 0)
    return dist_move

result=''
for case in cases:
    res=test_case(case)
    result+=str(res)+'\n'
result=result.strip()
print(result)
