n=int(input())
c=sorted(list(map(int, input().split())))

t=[-1, 0]
for i in range(n):
    t_new=(n-i)*c[i]
    if t_new>t[0]:
        t=[t_new, c[i]]
print(t[0], t[1])
