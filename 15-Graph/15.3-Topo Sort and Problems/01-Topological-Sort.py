class dfsSolution:
    # Function to return list containing vertices in Topological order.
    def dfs(self, i, adj, vis, stack):
        vis[i] = 1

        for x in adj[i]:
            if vis[x] == False:
                self.dfs(x, adj, vis, stack)
        stack.append(i)

    def topoSort(self, V, adj):
        # Code here
        vis = [0] * V

        stack = []

        for i in range(V):
            if vis[i] == False:
                self.dfs(i, adj, vis, stack)

        return stack[::-1]


from collections import deque


class kahnSolution:
    # Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        indegree = [0] * V
        queue = deque()

        for i in range(V):
            for node in adj[i]:
                indegree[node] += 1

        for i in range(V):
            if indegree[i] == 0:
                queue.append(i)
        ans = []
        while len(queue) != 0:
            node = queue.popleft()
            ans.append(node)

            for next in adj[node]:
                indegree[next] -= 1

                if indegree[next] == 0:
                    queue.append(next)

        return ans
