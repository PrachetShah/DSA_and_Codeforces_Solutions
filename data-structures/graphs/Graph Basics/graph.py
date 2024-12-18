from collections import defaultdict

def createAdMatrixUndir(nodes):
    matrix = [[0  for _ in range(nodes)] for _ in range(nodes)]
    for i in range(nodes):
        for j in range(i, nodes):
            if i == j:
                continue
            edge = int(input(f"Enter edge between {i} -> {j}: "))
            matrix[i][j] = edge
            matrix[j][i] = edge
    return matrix

def printAdMatrix(matrix):
    for i in range(len(matrix)):
        print(matrix[i])

def createAdList(edges):
    adList = defaultdict(list)
    for _ in range(edges):
        node1, node2 = map(int, input("Enter Node between Edges: ").split())
        adList[node1].append(node2)
        adList[node2].append(node1)
    return adList

def printAdList(adList: dict):
    for key, val in adList.items():
        print(key,"->", val)

def BFS(adList:dict, start:int=0):
    q = []
    visited = {}
    q.append(start)
    visited[start] = True

    print(f"BFS Traversal of Grapgh from {start}: ", end=" ")

    while len(q) > 0:
        front = q.pop(0)
        print(front, end=" ")
        for node in adList[front]:
            if node not in visited:
                q.append(node)
                visited[node] = True
    print()

def DFS(adList, start:int=1):
    print(f"DFS Traversal of Graph from {start}", end =" ")
    visited = {}
    def DFSSolver(adList, start):
        visited[start] = True

        for node in adList[start]:
            if node not in visited:
                visited[node] = True
                print(node, end=" ")
                DFSSolver(adList, node)
    DFSSolver(adList, start)
    print()

if __name__ == "__main__":
    nodes, edges = map(int, input("Enter Nodes and Edges: ").split())

    # adjancency matrix
    adjacencyMatrix = createAdMatrixUndir(nodes)
    printAdMatrix(adjacencyMatrix)

    # Adjacency List
    adjacencyList = createAdList(edges)
    printAdList(adjacencyList)

    # BFS Traversal
    BFS(adjacencyList, 0)

    # DFS Traveral
    DFS(adjacencyList, 0)
