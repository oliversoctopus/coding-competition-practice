import sys

#white=map(int, input().split())
#b1=map(int, input().split())
#b2=map(int, input().split())
white=[2, 2, 4, 4]
b1=[1, 1, 3, 5]
b2=[3, 1, 5, 5]

def inter_area(s1, s2):
    bl_a_x, bl_a_y, tr_a_x, tr_a_y = s1[0], s1[1], s1[2], s1[3]
    bl_b_x, bl_b_y, tr_b_x, tr_b_y = s2[0], s2[1], s2[2], s2[3]
    width=min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)
    length=min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)
    if width<=0 or length<=0:
        return 0

    return width*length

b1[0]=max(b1[0], white[0])
b1[1]=max(b1[1], white[1])
b1[2]=min(b1[2], white[2])
b1[3]=min(b1[3], white[3])
covered=inter_area(white, b1)+inter_area(white, b2)-inter_area(b1, b2)
area=(white[2]-white[0])*(white[3]-white[1])

if area-covered>0:
    print('YES')
else:
    print('NO')
