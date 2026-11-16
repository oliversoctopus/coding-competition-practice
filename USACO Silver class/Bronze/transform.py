"""
ID: oliver.11
LANG: PYTHON3
TASK: transform
"""

fin=open('transform.in', 'r')
fin_read=fin.read()
fin.close()

fin_list=fin_read.split('\n')
n=int(fin_list[0])
start_design=fin_list[1:n+1]
end_design=fin_list[n+1:-1]

def conv_arr(design):
    list_arr=[]
    for i in range(len(design)):
        row=[]
        for j in design[i]:
            if j=='@':
                row.append(1)
            else:
                row.append(0)
        list_arr.append(row)
    return list_arr

start=conv_arr(start_design)
end=conv_arr(end_design)

def rot_90(design):
    length=len(design)
    arr_new=[[0 for i in range(length)] for i in range(length)]
    def rot(x, y):
        return (y, -x)
    center=length/2-0.5
    for i in range(length):
        for j in range(length):
            new_coords=rot(i-center, j-center)
            destination=[int(i+center) for i in new_coords]
            arr_new[destination[0]][destination[1]]=design[i][j]
    return arr_new
    
def rot_180(design):
    for i in range(2):
        design=rot_90(design)
    return design

def rot_270(design):
    for i in range(3):
        design=rot_90(design)
    return design

def flip_row(row):
    new_row=[0 for i in range(len(row))]
    for i in range(len(row)):
        new_row[-i-1]=row[i]
    return new_row

def reflect(design):
    length=len(design)
    arr_new=[[0 for i in range(length)] for i in range(length)]
    for i in range(length):
        row=design[i]
        flipped=flip_row(row)
        arr_new[i]=flipped
    return arr_new

rot_funcs=[rot_90, rot_180, rot_270]
reflected=reflect(start)
result=None
simpler=False

for i in range(len(rot_funcs)):
    func=rot_funcs[i]
    if func(reflected)==end:
        result=5 if (result==None or result>5) else result
    if func(start)==end:
        result=i+1 if (result==None or result>i+1) else result

if reflected==end:
    result=4 if (result==None or result>4) else result

elif start==end:
    result=6 if (result==None or result>6) else result

elif result==None:
    result=7 if (result==None or result>7) else result

result=str(result)+'\n'

fout=open('transform.out', 'w')
fout.write(result)
fout.close()
