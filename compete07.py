N = int(input())
num = list(map(int, input().split(' ')))
num = sorted(num, reverse=True)
store = []
while len(num) > 1:
    if num[0] - num[1] < 10:
        store += num[:2]
        num = num[2:]
    else: num = num[1:]
if len(store) > 0: 
    avg = sum(store) / len(store)
    print("{:.2f}".format(round(avg,2)))
else: print("0.00")