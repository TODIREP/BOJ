answer = 0
N = int(input())
data = []
for _ in range(N):
    count, score = map(int, input().split())
    data.append(count)
data.sort(reverse = True)

for value in range(5, N):
    if data[value] == data[4]:
        answer += 1
        
print(answer)