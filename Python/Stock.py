"""
股票类型题目：
"""

'''1. 只能进行一次交易，即k=1'''
def BuyAndSellStock1(prices):
    n = len(prices)
    dp = [[0]*2 for _ in range(n)]
    for i in range(n):
        if i == 0:
            dp[i][0] =  0
            dp[i][1] = -prices[i]
        else:
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], -prices[i])
    return dp[n-1][0]

'''2. 能进行无穷次交易，即k=inf'''
def BuyAndSellStock2(prices):
    n = len(prices)
    dp = [[0]*2 for _ in range(n)]
    for i in range(n):
        if i == 0:
            dp[i][0] = 0
            dp[i][1] = -prices[i]
        else:
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
    return dp[n-1][0]

'''3. 能进行无穷次交易，即k=inf,但是存在一个冷却期，每次sell之后要等上一天'''
# 意味着选择买的时候 要从i-2的状态转移，而不是i-1
def BuyAndSellStock3(prices):
    n = len(prices)
    dp = [[0]*2 for _ in range(n)]
    for i in range(n):
        if i == 0:
            dp[i][0] = 0
            dp[i][1] = -prices[i]
        elif i == 1:
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], -prices[i])
        else:
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
    return dp[n-1][0]

'''4. 进行无穷次交易，k=inf 但是需要交手续费'''
# 只需把手续从利润中减去
def BuyAndSellStock4(prices, fee):
    n = len(prices)
    dp = [[0]*2 for _ in range(n)]
    for i in range(n):
        if i == 0:
            dp[i][0] = 0
            dp[i][1] = -prices[i] - fee
        else:
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
    return dp[n-1][0]


'''5. 只能进行2次交易，k=2, 此时k无法简化，因此要进行穷举出来'''
def BuyAndSellStock5(prices):
    n = len(prices)
    max_k = 2
    dp = [[[0]*2 for _ in range(max_k+1)] for _ in range(n)]

    for i in range(n):
        for k in range(max_k, 0 , -1): 
            if i == 0:
                dp[i][k][0] = 0
                dp[i][k][1] = -prices[i]
            else:
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
    return dp[n-1][max_k][0]

'''6. 能进行任意次交易，k=任意, 此时k也无法简化，因此要进行穷举出来'''
# 如果k很大的话，会出现超内存现象，一次交易由买入和卖出构成，因此可以限制k不超过n/2 ，就相当于k=无穷，就为第二种问题了
def BuyAndSellStock6(prices, max_k):
    n = len(prices)
    if (max_k > n/2):
        return BuyAndSellStock2(prices)
    dp = [[[0]*2 for _ in range(max_k+1)] for _ in range(n)]

    for i in range(n):
        for k in range(max_k, 0 , -1): 
            if i == 0:
                dp[i][k][0] = 0
                dp[i][k][1] = -prices[i]
            else:
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
    return dp[n-1][max_k][0]

def Test1():
    prices = [7, 1, 5, 3, 6, 4]
    # prices = [7, 6, 4, 3, 1]
    result = BuyAndSellStock1(prices)
    return result

def Test2():
    prices = [7, 1, 5, 3, 6, 4]
    # prices = [7, 6, 4, 3, 1]
    result = BuyAndSellStock2(prices)
    return result

def Test3():
    # prices = [7, 1, 5, 3, 6, 4]
    prices = [1, 2, 3, 0, 2]
    result = BuyAndSellStock3(prices)
    return result

def Test4():
    prices = [1, 3, 2, 8, 4, 9]
    # prices = [1, 2, 3, 0, 2]
    fee = 2
    result = BuyAndSellStock4(prices, fee)
    return result

def Test5():
    prices = [3, 3, 5, 0, 0, 3, 1, 4]
    # prices = [1, 2, 3, 4, 5]
    # prices = [7,6, 4,3,1]

    result = BuyAndSellStock5(prices)
    return result

def Test6():
    # prices = [3, 3, 5, 0, 0, 3, 1, 4]
    prices = [3, 2, 6, 5, 0, 3]
    # prices = [7,6, 4,3,1]

    result = BuyAndSellStock6(prices, 2)
    return result

def main():
    print("Test1: ", Test1())
    print("Test2: ", Test2())
    print("Test3: ", Test3())
    print("Test4: ", Test4())
    print("Test5: ", Test5())
    print("Test6: ", Test6())

if __name__ == "__main__":
    main()