
digits = "444947137"
nums = {str(x):0 for x in range(10)}

for d in digits:
    nums[d] += 1

gtr = -1

#consegue o centro
for k,v in nums.items():
    if v == 0:
        continue
    elif v%2!=0 and int(k)>gtr:
        gtr=int(k)



#subtrai 1 de todos os canditatos ao centro
for i in range(10):
    if nums[str(i)]%2!=0:
        nums[str(i)]-=1

res = str(gtr) if gtr!=-1 else ""

for i in range(10):
    pairs = str(i)*(nums[str(i)]//2)
    res = pairs+res+pairs

while res[0]=='0':
    res = res[1:-1]

    if not res:
        res = "0"
        break
print(res)

    