with open('blocks.in') as file:
    fin=file.read().strip()
#fin='''3
#fox box
#dog cat
#car bus'''

def add_list(list1, list2):
    sum_list=[0]*len(list1)
    for i in range(len(list1)):
        sum_list[i]+=list1[i]+list2[i]
    return sum_list

fin_split=fin.split('\n')
blocks=fin_split[1:]
blocks=[b.split() for b in blocks]
alphabet_list=[0]*26
alphabet='abcdefghijklmnopqrstuvwxyz'

for block in blocks:
    word_letter=[0]*26
    for word in block:
        word_list=[0]*26
        for char in word:
            index=alphabet.index(char)
            word_list[index]+=1
        for i in range(len(word_list)):
            if word_list[i]>word_letter[i]:
                word_letter[i]=word_list[i]
    alphabet_list=add_list(alphabet_list, word_letter)

#print(alphabet_list)
result=''
for a in alphabet_list:
    result+=str(a)+'\n'
#print(result)

with open('blocks.out', 'w') as file:
    file.write(str(result))
