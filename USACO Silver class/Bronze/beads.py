"""
ID: oliver.11
LANG: PYTHON3
TASK: beads
"""

fin=open('beads.in', 'r')
fin_read=fin.read()
fin.close()

string=fin_read.split('\n')[1]

def left(string, cut_point):
    copied=string+string
    start_index=len(string)+cut_point
    stop=False
    start_color=copied[start_index]
    white=False
    beads=1
    beads2=-1
    start_index-=1

    if start_color=='w':
        white=True
        start_color='r'
    
    
    while not stop:
        bead=copied[start_index]
        if bead==start_color or bead=='w':
            beads+=1
            start_index-=1
        else:
            stop=True
        if start_index<0:
            break
        
    if white:
        stop=False
        start_index=len(string)+cut_point-1
        start_color='b'
        beads2=1
        while not stop:
            bead=copied[start_index]
            if bead==start_color or bead=='w':
                beads2+=1
                start_index-=1
            else:
                stop=True
            if start_index<0:
                break

    return max(beads, beads2)

def right(string, cut_point):
    copied=string+string
    start_index=cut_point+1
    stop=False
    start_color=copied[start_index]
    white=False
    beads=1
    beads2=-1
    start_index+=1

    if start_color=='w':
        white=True
        start_color='r'
    
    
    while not stop:
        bead=copied[start_index]
        if bead==start_color or bead=='w':
            beads+=1
            start_index+=1
        else:
            stop=True
        if start_index>=len(copied):
            break
        
    if white:
        stop=False
        start_index=cut_point+2
        start_color='b'
        beads2=1
        while not stop:
            bead=copied[start_index]
            if bead==start_color or bead=='w':
                beads2+=1
                start_index+=1
            else:
                stop=True
            if start_index>=len(copied):
                break

    return max(beads, beads2)

def collect(string, cut_point):
    left_result=left(string, cut_point)
    right_result=right(string, cut_point)
    if left_result+right_result>len(string):
        result=len(string)
    else:
        result=left_result+right_result
    return result

def test(string):
    result=-1
    for i in range(len(string)):
        temp=collect(string, i)
        if temp>result:
            result=temp
    return result

result=str(test(string))+'\n'

fout=open('beads.out', 'w')
fout.write(result)
fout.close()
