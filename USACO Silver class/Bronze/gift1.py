"""
ID: oliver.11
LANG: PYTHON3
TASK: gift1
"""
fin=open('gift1.in', 'r')
fin_text=fin.read()
fin.close()
fout=open('gift1.out', 'w')
print(fin_text)

fin_split=fin_text.split('\n')
names_dict={}
names=fin_split[1:int(fin_split[0])+1]

for name in names:
    names_dict[name]=0
    
fin_split=fin_split[int(fin_split[0])+1:]
fin_split=fin_split[:-1]

nums_list=['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

counter=0
end=True
person=None
amnt_give=0


for line in fin_split:
    if end:
        person=line
        end=False
    else:
        if line[0] in nums_list:
            if line[0]=='0':
                continue
            split_line=line.split(' ')
            amnt_give=int(split_line[0])//int(split_line[1])
            counter=int(split_line[1])
        elif line in names_dict.keys() and counter!=0:
            names_dict[line]+=amnt_give
            names_dict[person]-=amnt_give
            counter-=1
        else:
            person=line

#for line in fin_split:
    
    #if counter==0:
        #in_group=False
        #give_val=0
        #acct='None'
    #if not in_group:
        #in_group=True
        #acct=line
    #else:
        #if line[0] in nums_list:
            #given=line.split('_')[0]
            #counter=line.split('_')[1]
            #if given==0:
                #in_group=False
                #counter=0
                #give_val=0
            #give_val=floor(given/counter)
            #names_dict[acct]-=given
            #names_dict[acct]+=given%counter
        #else:
            #names_dict[line]+=give_val
            #counter-=1

final_str=''

for key, value in names_dict.items():
    final_str+=f'{key} {value}\n'
        
fout.write(final_str)
fout.close()
