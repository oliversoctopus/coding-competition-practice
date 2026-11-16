import sys

sys.stdin=open('bcs.in')
sys.stdout=open('bcs.out', 'w')

n, k=map(int, input().split())
fig=[]
for i in range(n):
    fig.append(input().strip())
pieces=[]
for i in range(k):
    piece=[]
    for j in range(n):
        piece.append(input().strip())
    pieces.append(piece)

def limits(piece):
    top=0
    bottom=0
    left=0
    right=0
    rows=[]
    cols=[]
    no_top=False
    no_bottom=False
    no_left=False
    no_right=False
    for i in range(n):
        row=piece[i]
        if '#' not in row:
            rows.append(0)
        else:
            rows.append(1)
        col=[piece[j][i] for j in range(n)]
        if '#' not in col:
            cols.append(0)
        else:
            cols.append(1)
    for i in range(len(rows)):
        if rows[i]==0 and not no_top:
            top+=1
        else:
            no_top=True
        if rows[-i-1]==0 and not no_bottom:
            bottom+=1
        else:
            no_bottom=True
    for i in range(len(cols)):
        if cols[i]==0 and not no_left:
            left+=1
        else:
            no_left=True
        if cols[-i-1]==0 and not no_right:
            right+=1
        else:
            no_right=True
    return top, bottom, left, right

def superimpose(piece1, piece2, p1_i, p2_i):
    p1=piece1[0]
    p1_lim=piece1[1]
    p2=piece2[0]
    p2_lim=piece2[1]
    p1_n=piece1[2]
    p2_n=piece2[2]
    if p1_n+p2_n!=fig_n:
        return False
    for horz_1 in range(-p1_lim[2], p1_lim[3]+1):
        for vert_1 in range(-p1_lim[1], p1_lim[0]+1):
            for horz_2 in range(-p2_lim[2], p2_lim[3]+1):
                for vert_2 in range(-p2_lim[1], p2_lim[0]+1):
                    good=True
                    for i in range(n):
                        for j in range(n):
                            p1_state=None
                            p2_state=None
                            if 0<=i+vert_1<n and 0<=j-horz_1<n:
                                p1_state=p1[i+vert_1][j-horz_1]
                            else:
                                p1_state='.'
                            if 0<=i+vert_2<n and 0<=j-horz_2<n:
                                p2_state=p2[i+vert_2][j-horz_2]
                            else:
                                p2_state='.'
                            if p1_state==p2_state and p1_state=='#':
                                good=False
                                break
                            overlapped='.'
                            if p1_state=='#' or p2_state=='#':
                                overlapped='#'
                            if overlapped!=fig[i][j]:
                                good=False
                                break
                        if not good:
                            break
                    if good:
                        print(p1_i, p2_i)
                        return True
    return False

pieces=[[p, limits(p), sum([i.count('#') for i in p])] for p in pieces]
fig_n=sum([i.count('#') for i in fig])

for i in range(len(pieces)):
    success=False
    for j in range(i+1, len(pieces)):
        result=superimpose(pieces[i], pieces[j], i+1, j+1)
        if result:
            success=True
            break
    if success:
        break
    
