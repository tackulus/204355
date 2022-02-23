s1 = input()
s2 = input()
threshold = max([len(s1), len(s2)]) / 3
diff = abs(len(s1) - len(s2))

for i in range(min([len(s1), len(s2)])):
    if s1[i] != s2[i]: diff += 1

print(diff)
if diff < threshold: print('yes')
else: print('no')