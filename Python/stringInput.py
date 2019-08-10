import sys
'''
3
5, 5, 7
6, 7, 8
2, 2, 4

19
'''
def InputFunc():
    i, n = 0, 0;
    matrix = []
    for line in sys.stdin:
        tmp = []
        if (i == 0):
            n = int(line)
            i += 1
            continue
        s = line.strip().split(",")
        for num in s:
            tmp.append(int(num))
        matrix.append(tmp)
        if (i == n):
            break
        i += 1
    return n,matrix

def Dfs(matrix, i, j, n, min_value, sum_value):
    if (i == (n - 1) and j == (n - 1)):
        sum_value += matrix[i][j]
        if (sum_value < min_value[0]):
            min_value[0] = sum_value
        print(sum_value, min_value[0])
        return
    if (i > (n-1) or j > (n-1)):
        return
    sum_value += matrix[i][j]
    Dfs(matrix,  i + 1, j, n, min_value, sum_value)
    Dfs(matrix,  i, j + 1, n, min_value, sum_value)        

def main():
    # n, matrix = InputFunc()
    n = 0
    matrix = []
    if (n == 0):
        print(0)
        return 
    min_value = [float("inf")]
    Dfs(matrix, 0, 0, n, min_value, 0)
    print(min_value[0])
    return 
    

if __name__ == "__main__":
    main()