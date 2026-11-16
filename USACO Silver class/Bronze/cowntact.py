import math
n=int(input())
cows=input()

if '1' not in cows:
    print(0)
elif '0' not in cows:
    print(1)
else:
    batches=cows.split('0')
    start_b=batches[0]
    end_b=batches[-1]
    cur_state=False
    begin_sizes=[]
    nights=[]
    sizes=[]
    for i in range(1, len(batches)-1):
        b=batches[i]
        if b=='':
            continue
        size=len(b)
        if size==1 or size==2:
            cur_state=True
            break
        else:
            if size%2==0:
                begin_sizes.append(2)
                nights.append(-(size-2)/2)
                sizes.append(size)
            else:
                begin_sizes.append(1)
                nights.append(-(size-1)/2)
                sizes.append(size)
    if cur_state or len(start_b)==1 or len(end_b)==1:
        summ=0
        for b in batches:
            summ+=len(b)
        print(summ)
    else:
        night=-100000000
        if nights!=[]:
            night=max(nights)
        summ=0
        if start_b!='':
            lower=-night
            upper=-night*2
            size=len(start_b)
            if lower>=size:
                night=-size+1
                summ+=1
            elif size<=upper+1:
                summ+=1
            else:
                night_val=-night*2+1
                summ+=math.ceil(size/night_val)
        if end_b!='':
            lower=-night
            upper=-night*2
            size=len(end_b)
            if lower>=size:
                night=-size+1
                summ+=1
            elif size<=upper+1:
                summ+=1
            else:
                night_val=-night*2+1
                summ+=math.ceil(size/night_val)
        night_val=-night*2+1
        for i in range(len(begin_sizes)):
            size_i=begin_sizes[i]
            night_i=nights[i]
            size_n=sizes[i]
            amnt_split=math.ceil(size_n/night_val)
            summ+=amnt_split
        print(int(summ))
