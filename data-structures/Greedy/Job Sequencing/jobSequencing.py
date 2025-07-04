import heapq

class Solution:
    def jobSequencing(self, deadline, profit):
        # code here
        totalProfit = 0
        cnt = 0
        jobs = [[deadline[i], profit[i]] for i in range(len(deadline))]
        
        minHeap = []
        
        jobs.sort()
        
        for job in jobs:
            if job[0] > len(minHeap):
                heapq.heappush(minHeap, job[1])
            elif len(minHeap)>0 and job[1] > minHeap[0]:
                heapq.heappushpop(minHeap, job[1])
        
        
        while len(minHeap) > 0:
            totalProfit += heapq.heappop(minHeap)
            cnt += 1
        
        return cnt, totalProfit