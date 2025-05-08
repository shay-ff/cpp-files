MOD = 998244353

def count_combinations(A, B, C):
    
    dp = [[[0 for _ in range(C+1)] for _ in range(B)] for _ in range(A+1)]

    for j in range(B):
        dp[1][j][0] = 1
    
    # Build DP table
    for i in range(2, A+1):
        for j in range(B):  # current last number
            for k in range(B):  # previous last number
                for changes in range(C+1):
                    if j == k:
                        # No change in number
                        dp[i][j][changes] += dp[i-1][k][changes]
                    else:
                        # Number changes
                        if changes > 0:
                            dp[i][j][changes] += dp[i-1][k][changes-1]
                    
                    # Take modulo to prevent integer overflow
                    dp[i][j][changes] %= MOD
    
    # Sum all ways to reach length A with exactly C changes
    total_ways = sum(dp[A][j][C] for j in range(B)) % MOD
    
    return total_ways

# Example usage
A = int(input())
B = int(input())
C = int(input())
result = count_combinations(A, B, C)
print(f"Number of valid combinations: {result}")