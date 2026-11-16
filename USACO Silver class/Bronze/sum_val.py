n, x=map(int, input().split())
a=list(map(int, input().split()))
a_dict={}

for i, val in enumerate(a):
    complement=x-val
    if complement in a_dict:
        complement_index=a_dict[complement]
        if complement_index!=i:
            print(complement_index+1, i+1)
            break
    a_dict[val]=i
else:
    print('IMPOSSIBLE')

'''
for i, val in enumerate(a):
    complement=x-val
    if complement in a_set:
        index=a.index(complement)
        if index!=i:
            print(i+1, complement+1)
            break
else:
    print('IMPOSSIBLE')
'''
