from maxSumNotAdjacentElements import maxSumSpaceOptimised

def houseRobber(arr):
    if len(arr) == 1:
        return arr[0]
    return max(maxSumSpaceOptimised(arr[1:]), maxSumSpaceOptimised(arr[:-1]))

if __name__ == "__main__":
    arrs = [[4,2,3,9], [3,3,3,3,3,3], [2,3,2]]

    for arr in arrs:
        print("Ans to house Robber Problem for", arr, "is", houseRobber(arr))
        print()