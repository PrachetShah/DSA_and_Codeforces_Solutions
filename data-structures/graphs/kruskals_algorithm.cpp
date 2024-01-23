/*
Kruskal’s algorithm is used to find the MST of a given weighted graph. 

Algorithm:
1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

To check Cycle:
 Use Union Find Method
*/