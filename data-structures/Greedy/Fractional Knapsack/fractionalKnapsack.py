class Solution:
    def fractionalknapsack(self, val, wt, capacity):
        #code here
        arr = [[val[i]/wt[i], val[i], wt[i]] for i in range(len(wt))]
        arr.sort(key=lambda x: x[0], reverse=True)
        
        bag = capacity
        ans = 0.0
        
        for item in arr:
            if item[2] <= bag:
                bag -= item[2]
                ans += item[1]
            else:
                ans += (item[0])*bag
                break
        return ans