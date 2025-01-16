class Solution:

    def __init__(self):
        self.adj = [[]]
        self.vis = []

    def dfs(self, v):
        self.vis[v] = True
        for u in self.adj[v]:
            if not self.vis[u]:
                print(u, end='\n')
                self.dfs(u)

    def solve(self):
        n, k = map(int, input().split())
        self.adj = [[] for _ in range(n+1)]
        self.vis = [False] * (n+1)
        for _ in range(k):
            x, y = map(int, input().split())
            self.adj[x].append(y)
            self.adj[y].append(x)
        self.dfs(1)

solution = Solution()
solution.solve()