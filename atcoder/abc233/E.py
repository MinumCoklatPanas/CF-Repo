s = input()

sum = 0
for i in range(len(s)):
    sum = sum + int(s[i])

s = s[::-1]
ans = ""
carry = 0
for i in range(len(s) - 1):
    # print(sum,carry)
    cur = (sum + carry) % 10
    ans = ans + str(cur)
    carry = (sum + carry) // 10
    sum = sum - int(s[i])

ans = ans[::-1]
ans = str(sum + carry) + ans
print(ans)