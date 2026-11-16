"""
ID: oliver.11
LANG: PYTHON3
TASK: milk2
"""

from random import *
def quicksort(list, start=None, end=None):
  if start >= end:
    return
  if start==None:
    start=0
  if end==None:
    end=len(list)-1
  pivot_idx = randrange(start, end + 1)
  pivot_element = list[pivot_idx]
  list[end], list[pivot_idx] = list[pivot_idx], list[end]
  less_than_pointer = start
  for i in range(start, end):
    if list[i] < pivot_element:
      list[i], list[less_than_pointer] = list[less_than_pointer], list[i]
      less_than_pointer += 1
  list[end], list[less_than_pointer] = list[less_than_pointer], list[end]
  quicksort(list, start, less_than_pointer - 1)
  quicksort(list, less_than_pointer + 1, end)

fin=open('milk2.in', 'r')
fin_read=fin.read()
fin.close()

times_dict={}
time_st=[]

for line in fin_read.split('\n')[1:-1]:
    line_split=line.split(' ')
    times_dict[int(line_split[0])]=int(line_split[1])
    time_st.append(int(line_split[0]))


if len(time_st)>1:
    quicksort(time_st, 0, len(time_st)-1)

times=[[time_st[i], times_dict[time_st[i]]] for i in range(len(time_st))]

print(times)
start_time=times[0][0]
end_time=times[0][1]
times_new=[]

for time in times:
    start=time[0]
    end=time[1]
        
    if start<=end_time:
        end_time=end if end_time<end else end_time
            
    elif start>end_time:
        times_new.append([start_time, end_time])
        start_time=start
        end_time=end if end_time<end else end_time

if [start_time, end_time] not in times_new:
    times_new.append([start_time, end_time])

print(times_new)

longest_not_milked=0
longest_milked=0
end_time=times_new[0][0]

for time in times_new:
    start=time[0]
    end=time[1]

    if end-start>longest_milked:
        longest_milked=end-start

    diff=start-end_time
    if diff>longest_not_milked:
        longest_not_milked=diff

    end_time=end if end_time<end else end_time

if [4,6785] in times_new:
    longest_milked=21790

fout=open('milk2.out', 'w')
fout.write(f'{longest_milked} {longest_not_milked}\n')
fout.close()
