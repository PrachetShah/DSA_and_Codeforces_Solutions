from collections import Counter

def calculate_max_probability(N, dice):
    max_prob = 0
    
    for i in range(N):
        for j in range(i + 1, N):
            count_i = Counter(dice[i])
            count_j = Counter(dice[j])

            prob_i = {k: v / len(dice[i]) for k, v in count_i.items()}
            prob_j = {k: v / len(dice[j]) for k, v in count_j.items()}

            common_prob = sum(prob_i[k] * prob_j[k] for k in prob_i if k in prob_j)
            
            max_prob = max(max_prob, common_prob)
    
    return max_prob

N = int(input().strip())
dice = []
for _ in range(N):
    line = list(map(int, input().split()))
    dice.append(line[1:]) 

result = calculate_max_probability(N, dice)
print(result)
