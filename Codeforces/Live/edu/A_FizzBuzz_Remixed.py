def count_numbers(n):
    M = n // 15
    extra = n - 15 * M + 1 
    extra = min(3, extra)
    return 3 * M + extra

for _ in range(int(input())):
    n = int(input())
    print(count_numbers(n))
