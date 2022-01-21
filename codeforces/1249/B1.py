def sol():
    n = int(input())
    a = list(map(int,input().split()))
    for i in range(n):
        c = 0
        k = a[i]
        while(k != i + 1):
            c += 1
            k = a[k - 1]
        print(c + 1, end = ' ')
    print()
 
for _ in range(int(input())):
    sol()