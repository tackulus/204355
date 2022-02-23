P = int(input())
N = int(input())

skill = []
for n in range(N):
    skill.append(list(map(int, input().split(' '))))
















# def partition(collection):
#     if len(collection) == 1:
#         yield [ collection ]
#         return
#     first = collection[0]
#     for smaller in partition(collection[1:]):
#         for n, subset in enumerate(smaller):
#             yield smaller[:n] + [[ first ] + subset]  + smaller[n+1:]
#         yield [ [ first ] ] + smaller

# ans = 0
# for p in partition(skill):
#     for p_ in p:
#         power, point = 0, P
#         for s in p_:
#             power += s[0]; point += s[1]
#         if point >= 0: ans = max(ans,power)
# print(ans)