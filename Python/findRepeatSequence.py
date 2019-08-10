def InputFunc():
    data = []
    n = int(input())
    for i in range(n):
        num_data = int(input())
        list_data = list(map(int, input().split()))
        data.append(list_data)
    return data

def IsSame(list1, list2):
    if (len(list1) != len(list2)):
        return False
    for i,j in zip(list1, list2):
        if (i != j):
            return False
    return True

def main():
    data = InputFunc()
    record_list = []
    remove_list = []
    for i in range(len(data)):
        if i in remove_list:
            continue
        remove_list = []
        for j in range(i + 1, len(data)):
            if IsSame(data[i], data[j]):
                remove_list.append(j)
        if len(remove_list) != 0:
            record_list.append([i, len(data[i])])
    for record in record_list:
        print(record[0],record[1])
        
if __name__ == "__main__":
    main()