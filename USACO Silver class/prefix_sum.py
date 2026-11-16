n = int(input())
a = list(map(int, input().split()))
q = int(input())
psum = [0]
for k in range(n):
    psum.append(psum[-1] + a[k])
for i in range(q):
    i, j = map(int, input().split())
    print(psum[j+1] - psum[i])
