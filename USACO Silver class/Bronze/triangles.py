import sys

sys.stdin=open('triangles.in')
sys.stdout=open('triangles.out', 'w')

n=int(input())
posts=[]
for i in range(n):
    posts.append([int(i) for i in input().split()])

max_area=-1
for p in posts:
    temp=posts[:]
    temp.remove(p)
    max_height=-1
    max_width=-1
    for t in temp:
        if t[1]==p[1]:
            width=abs(t[0]-p[0])
            max_width=max(width, max_width)
        elif t[0]==p[0]:
            height=abs(t[1]-p[1])
            max_height=max(height, max_height)
    if max_height==-1 or max_width==-1:
        continue
    area=max_height*max_width/2
    max_area=max(area, max_area)

max_area*=2
print(int(max_area))
