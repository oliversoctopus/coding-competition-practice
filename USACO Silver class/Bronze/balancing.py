import sys
sys.stdin = open("balancing.in", "r")
sys.stdout = open("balancing.out", "w")
N = int(input())

coordinates = []
for _ in range(N):
    coordinates.append(list(map(int, input().split())))

coordinates.sort(key=lambda x: x[0])

M_max = float("inf")
for i in range(N):
    above = []
    below = []
    for x, y in coordinates:
        if y <= coordinates[i][1]:
            below.append([x, y])
        else:
            above.append([x, y])
    below_index = 0
    above_index = 0
    while below_index < len(below) or above_index < len(above):
        x_border = float('inf')

        if below_index < len(below):
            x_border = min(x_border, below[below_index][0])
        if above_index < len(above):
            x_border = min(x_border, above[above_index][0])
        while below_index < len(below) and below[below_index][0] == x_border:
            below_index += 1

        while above_index < len(above) and above[above_index][0] == x_border:
            above_index += 1
        M_max = min(max(below_index, len(below) - below_index, above_index, len(above) - above_index), M_max)
print(M_max)
