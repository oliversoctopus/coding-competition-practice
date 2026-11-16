# Sum of Two Values
def do_thing():
    n, x = map(int, input().split())
    a = [int(i) for i in input().split()]
    a = sorted((a[i], i + 1) for i in range(n))
    i, j = 0, n - 1
    while i < j:
        s = a[i][0] + a[j][0]
        if s == x:
            a1=sorted([a[i][1], a[j][1]])
            print(a1[0], a1[1])
            return
        i += s < x
        j -= s > x
    print("IMPOSSIBLE")
do_thing()
