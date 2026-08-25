from decimal import *
getcontext().rounding = ROUND_HALF_EVEN
getcontext().prec = 100
n = int(input())
a = list(map(Decimal, input().split()))
ans = Decimal(0)
for i in range(n):
    for j in range(i+1, n):
        new_ans = Decimal(0)
        if a[i] > a[j]:
            new_ans += a[j] * (a[j] + 1) / 2
            new_ans += (a[i] - a[j] - 1) * a[j]
        else:
            new_ans += a[i] * (a[i] - 1) / 2
        ans += new_ans / (a[i] * a[j])
round(ans, 6)
print(f"{ans:.6f}")
