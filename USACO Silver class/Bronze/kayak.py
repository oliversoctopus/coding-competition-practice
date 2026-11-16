n=int(input())
weights=sorted(list(map(int, input().split())))
minimum=10000000000000
def find_instability(ls):
    diff=0
    for i in range(0, len(ls), 2):
        diff+=ls[i+1]-ls[i]
    return diff
for i in range(len(weights)):
    for j in range(i+1, len(weights)):
        new=weights[:]
        new.pop(i)
        new.pop(j-1)
        instability=find_instability(new)
        minimum=min(minimum, instability)
print(minimum)
'''
front_remove=weights[2:]
back_remove=weights[:-2]
mid=weights[1:-1]
f_diff=0
b_diff=0
m_diff=0
for i in range(0, len(front_remove), 2):
    f_diff+=abs(front_remove[i+1]-front_remove[i])
    b_diff+=abs(back_remove[i+1]-back_remove[i])
    m_diff+=abs(mid[i+1]-mid[i])
print(min(f_diff, b_diff, m_diff))
'''
