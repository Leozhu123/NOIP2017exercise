n=int(input())
a = []
b = []
for i in range(0, n):
    a.append(int(input()))
    b.append(i)
for i in range(0, n):
    for j in range(i + 1, n):
        if a[i] < a[j]:
            t = a[i]
            a[i] = a[j]
            a[j] = t
            t = b[i]
            b[i] = b[j]
            b[j] = t
print(b[0])
print(a[0])
