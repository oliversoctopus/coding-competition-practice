t=int(input())
for i in range(t):
    n, x1=map(int, input().split())
    right_up=[]
    right_down=[]
    left_up=[]
    left_down=[]
    coord=0
    for j in range(n):
        y1, y2, x2=map(int, input().split())
        right_up.append([x2, y2])
        right_down.append([x2, y1])
        left_up.append([x1, y2])
        left_down.append([x1, y1])
        coord+=1
    slopes=list(map(int, input().split()))
    down=[]
    up=[]
    flat=[]
    for s in slopes:
        if s<0:
            down.append(s)
        elif s>0:
            up.append(s)
        else:
            flat.append(s)
    down.sort()
    up.sort()
    flat.sort()
    if len(down)<coord or len(up)<coord:
        print(-1)
        continue
    right_up=sorted(right_up, key=lambda x: x[1])
    allocated=down[-len(right_up):]
    def check(allocated, opt, cur):
        if allocated==[]:
            most=-10**1000
            for i in range(len(cur)):
                val=-right_up[i][0]*cur[0]+right_up[i][1]
                most=max(most, val)
            opt=min(most, opt)
            return opt
        for i in range(len(allocated)):
            temp=cur[:]
            temp.append(allocated[i])
            temp2=allocated[:]
            temp2.pop(i)
            opt=check(temp2, opt, temp)
        return opt
    right_down=sorted(right_down, key=lambda x: x[1])
    allocated2=up[-len(right_down):]
    def check2(allocated, opt, cur):
        if allocated==[]:
            most=10**1000
            for i in range(len(cur)):
                val=-right_down[i][0]*cur[0]+right_down[i][1]
                most=min(most, val)
            opt=max(most, opt)
            return opt
        for i in range(len(allocated)):
            temp=cur[:]
            temp.append(allocated[i])
            temp2=allocated[:]
            temp2.pop(i)
            opt=check(temp2, opt, temp)
        return opt
    print(abs(check(allocated, 0, [])-check2(allocated, 0, [])))
