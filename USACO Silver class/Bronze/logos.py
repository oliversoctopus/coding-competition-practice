def mult(ls):
    return ls[0]*ls[1]

def psum(ls):
    new=[]
    for thing in ls:
        if new==[]:
            new.append(thing)
        else:
            new.append(new[-1]+thing)
    return new
def chk_shapes(side, c1, c2, c3):
    for i in range(2):
        for j in range(2):
            for k in range(2):
                total_len=c1[i]+c2[j]+c3[k]
                if total_len==side:
                    return [[c1[i], c2[j], c3[k]], None], [i, j, k]
                elif c1[i]+c2[j]==side and c3[k]==side:
                    return [[c1[i], c2[j], 0], 2], [i, j, k]
                elif c1[i]==side and c2[j]+c3[k]==side:
                    return [[0, c2[j], c3[k]], 0], [i, j, k]
                elif c2[j]==side and c1[i]+c3[k]==side:
                    return [[c1[i], 0, c3[k]], 1], [i, j, k]
    return [-1, -1]

def main():
    things=list(map(int, input().split()))
    c1=things[0:2]
    c2=things[2:4]
    c3=things[4:]
    c1_a=mult(c1)
    c2_a=mult(c2)
    c3_a=mult(c3)
    total=c1_a+c2_a+c3_a
    side=total**0.5
    companies=[c1, c2, c3]
    if round(side, 5)!=int(side):
        print(-1)
        return
    if max(things)>side:
        print(-1)
        return
    side=int(side)
    shapes, indexes=chk_shapes(side, c1, c2, c3)
    if shapes==-1:
        print(-1)
        return
    for i in range(len(indexes)):
        companies[i].pop(indexes[i])
    top=psum(shapes[0])
    letters=['A', 'B', 'C']
    bottom=shapes[1]
    board=''''''
    for i in range(side):
        for j in range(side):
            new=None
            if j<top[0]:
                new=0
            elif top[0]<=j<top[1]:
                new=1
            else:
                new=2
            length=companies[new][0]
            if i<length:
                board+=letters[new]
            else:
                board+=letters[bottom]
        board+='\n'
    print(side)
    print(board.strip())

main()
