n=int(input())
weights=list(map(int, input().split()))

def add(list, element):
    new=list[:]
    new.append(element)
    return new

def apple_combs(remaining, left=0, right=0):
    if remaining==[]:
        return abs(left-right)
    temp=remaining[:]
    a=temp.pop()
    return min(apple_combs(temp, left+a, right), \
               apple_combs(temp, left, right+a))

print(apple_combs(weights))
