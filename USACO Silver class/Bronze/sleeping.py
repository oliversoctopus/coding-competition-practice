t=int(input())
cur_list=[]
all_cases=[]
for i in range(t*2):
    if len(cur_list)<2:
        cur_list.append([int(j) for j in input().split()])
    else:
        all_cases.append(cur_list)
        cur_list=[]
        cur_list.append([int(j) for j in input().split()])
if len(all_cases)<t:
    all_cases.append(cur_list)

#print(all_cases)
def solve_case(case):
    n=case[0][0]
    case=case[1]
    a=sum(case)
    lowest=10**1000
    if a==0:
        print(0)
        return
    for i in range(a, 0, -1):
        flag=0
        k=0
        if a%i==0:
            for j in case:
                k+=j
                if k==i:
                    k=0
                elif k>i:
                    flag=1
                    break
            if flag==1:
                continue
            lowest=min(lowest, n-a//i)
    print(lowest)

for c in all_cases:
    solve_case(c)
