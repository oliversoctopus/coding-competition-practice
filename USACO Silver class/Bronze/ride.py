"""
ID: oliver.11
LANG: PYTHON3
TASK: ride
"""

fin=open('ride.in', 'r')
fout=open('ride.out', 'w')

num_dict={'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5,
          'F': 6,
          'G': 7,
          'H': 8,
          'I': 9,
          'J': 10,
          'K': 11,
          'L': 12,
          'M': 13,
          'N': 14,
          'O': 15,
          'P': 16,
          'Q': 17,
          'R': 18,
          'S': 19,
          'T': 20,
          'U': 21,
          'V': 22,
          'W': 23,
          'X': 24,
          'Y': 25,
          'Z': 26,
          }

group=fin.readline().strip()
comet=fin.readline().strip()

print(group)
print(comet)

groupc=1
cometc=1

for char in group:
    groupc*=num_dict[char]

for char in comet:
    cometc*=num_dict[char]

groupc=groupc%47
cometc=cometc%47

if groupc==cometc:
    fout.write('GO\n')
else:
    fout.write('STAY\n')

fout.close()
fin.close()
