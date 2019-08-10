import sys

def InputFunc():
    a = list(map(int, input().strip().split()))
    num_ball = []
    for i in range(a[0]):
        num_ball.append(int(input()))
    return a[1], num_ball

def solution(num_select, num_ball, layer, list_select, list_result):
    if layer == len(num_ball) and sum(list_select) == num_select:
        list_result.append(list_select.copy())
        return
    if layer > len(num_ball)-1:
        return
    if (sum(list_select) > num_select):
        return
    for i in range(num_ball[layer] + 1):
        list_select.append(i)
        solution(num_select, num_ball, layer + 1, list_select, list_result)
        list_select.pop()


def main():
    num_select, num_ball = InputFunc()
    list_select = []
    list_result = []
    solution(num_select, num_ball, 0, list_select, list_result)
    print(list_result)

if __name__ == "__main__":
    main()
