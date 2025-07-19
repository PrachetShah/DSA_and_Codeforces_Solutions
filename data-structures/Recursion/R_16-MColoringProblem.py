# User function Template for python3
from collections import defaultdict
class Solution:
    def graphColoring(self, v, edges, m):
        # code here
        color = [0 for _ in range(v)]
        adList = defaultdict(list)
        for x in edges:
            adList[x[0]].append(x[1])
            adList[x[1]].append(x[0])
        
        def solve(node):
            if(node == v):
                return True
            for col in range(1, m+1):
                if(isSafe(col, node)):
                    color[node] = col
                    if(solve(node+1)):
                        return True
                    color[node] = 0
            return False
        def isSafe(col, node):
            for nbr in adList[node]:
                if color[nbr] == col:
                    return False
            return True
        
        return solve(0)