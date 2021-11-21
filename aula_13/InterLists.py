

def bacp(lst, operations, n):
    sent = 1
    first = 0
    last = n-1

    for op in operations:
        if op == "R":
            if sent == 1:
                sent = -1
            else:
                sent = 1
        else:
            if n == 0:
                print("error")
                return
            else:
                if sent == 1:
                    first += 1
                else:
                    last -= 1
                n -= 1
    if sent == 1:
        print("[", end="")
        for i in range(first, last):
            print(lst[i], end=",")
        print(str(lst[last]) + "]")
    else:
        print("[", end="")
        for i in range(last, first, -1):
            print(lst[i], end=",")
        print(str(lst[first]) + "]")


tc = int(input())
for i in range(tc):
    operations = input()
    
    n = int(input())
    lst = input()
    
    lst = lst.split(",")
    if lst[0] == "[]":
        lst = []
    else:
        lst[0] = lst[0][1:]
        lst[-1] = lst[-1][:-1]

        for i in range(len(lst)):
            lst[i] = int(lst[i])
    
    bacp(lst, operations, n)
        
        

