import sys

def main():
    n = int(input())
    loc = []
    loc_x = []
    loc_y = []
    for i in range(n):
        x, y = list(map(int, input().strip().split(" ")))
        loc_x.append(x)
        loc_y.append(y)
        loc.append([x,y])
    x_min, x_max = min(loc_x), max(loc_x)
    y_min, y_max = min(loc_y), max(loc_y)
    m = max(y_max-y_min, x_max-x_min)
    print(m*m)
    
    
if __name__ == "__main__":
    main()