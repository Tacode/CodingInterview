import sys
  
def InputFunc():
    n = int(input().strip())
    xyz = list(map(int, input().strip().split(" ")))
    return n, xyz

def main():
    n, xyz = InputFunc()
    x, y, z = xyz

    dp = [[int(0)] * 400] * 200
    
    dp[1][x] = 1
    dp[1][y] = 1
    dp[1][z] = 1
    # print(dp[4][299])
    for i in range(2,200):
        for j in range(0, 200):
            dp[i][j+x] += dp[i-1][j]
            dp[i][j+y] += dp[i-1][j]
            dp[i][j+z] += dp[i-1][j]
    sums = 0
    for i in range(1, 200):
        sums += dp[i][n]
    print(sums)
    
if __name__ == "__main__":
    main()