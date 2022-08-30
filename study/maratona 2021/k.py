
n = int(input())
words = []
for i in range(n):
    words.append(input())

initials = [w[0] for w in words]

res = words.copy()

for word in words:
    print(word)
    for letter in word:
        if not(letter in initials):
            res.remove(word)
            break

if len(res)>0:
    print('Y')
else:
    print('N')

