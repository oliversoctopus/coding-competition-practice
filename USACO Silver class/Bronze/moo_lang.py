# other user solution
def solution():
    N, C, P = map(int, input().split())
    noun, vt, vi, conj = [], [], [], []
    noun_count = vt_count = vi_count = conj_count = 0
    for _ in range(N):
        word, part_of_speech = input().split()
        if part_of_speech == "noun":
            noun.append(word)
            noun_count += 1
        elif part_of_speech == "transitive-verb":
            vt.append(word)
            vt_count += 1
        elif part_of_speech == "intransitive-verb":
            vi.append(word)
            vi_count += 1
        else:
            conj.append(word)
            conj_count += 1
    max_words = 0
    t1 = t2 = extra_noun_num = conj_num = 0
    for i in range(vi_count + 1):
        j = min(vt_count, (noun_count - i) // 2)
        found = False
        while j >= 0:
            conj_used = min(conj_count, (i + j) // 2)
            if i + j - conj_used <= P:
                found = True
                break
            j -= 1
        if found:
            extra_noun = min(noun_count - i - 2 * j, C)
            if not j:
                extra_noun = 0
            total = 2 * i + 3 * j + conj_used + extra_noun
            if total > max_words:
                max_words = total
                t1, t2, extra_noun_num, conj_num = i, j, extra_noun, conj_used
    print(max_words)
    simple = []
    for _ in range(t1):
        simple.append(noun.pop() + " " + vi.pop())
    for _ in range(t2):
        simple.append(noun.pop() + " " + vt.pop() + " " + noun.pop())
    for _ in range(extra_noun_num):
        simple[-1] += ", " + noun.pop()
    compound = []
    for _ in range(conj_num):
        compound.append(simple.pop() + " " + conj.pop() + " " + simple.pop())
    sentences = [s + "." for s in simple + compound]
    print(" ".join(sentences))


T = int(input())
for _ in range(T):
    solution()
