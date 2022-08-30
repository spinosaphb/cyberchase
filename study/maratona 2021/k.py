
n = int(input())
words = []
initials = set()
for i in range(n):
    w = input()
    words.append(w)
    initials.add(w[0])

for word in words:
    for letter in word:
        if not(letter in initials):
            break
    else:
        print('Y')
        break
else:
     print('N')


