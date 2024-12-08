# Very Imp Question related toi assessment rounds
def solve(tour):
    deficit = 0
    balance = 0
    start = 0

    for i in range(len(tour)):
        balance += tour[i][0] - tour[i][1]
        if balance < 0:
            deficit += balance
            start = i+1
            balance = 0
    
    if deficit + balance >= 0:
        return start
    else:
        # cycle complete not possible
        return -1

# distance, petrol
tour = [[4, 6], [6,5], [7,3], [4,5]]
print(solve(tour))