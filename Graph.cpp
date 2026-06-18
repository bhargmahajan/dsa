#include <bits/stdc++.h>

using namespace std;

/*
    @author: bhargmahajan
    @description: Solve graph problems
*/
class Graph
{
public:
    /*
        @description: Count the number of connected components in a graph
        @param V: Number of vertices
        @param edges: List of edges
        @return: Number of connected components
        @time complexity: O(V + E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V + E) for the adjacency list and visited array
    */
    int countComponents(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(V);
        for (const auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(V, 0);
        int components = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                components++;

                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (auto &nbx : adjList[node])
                    {
                        if (!visited[nbx])
                        {
                            visited[nbx] = 1;
                            q.push(nbx);
                        }
                    }
                }
            }
        }

        return components;
    }

    /*
        @description: Perform depth-first search on the graph
        @param v: Starting vertex
        @param adj: Adjacency list
        @param visited: Array to keep track of visited vertices
        @param result: Vector to store the DFS traversal
        @time complexity: O(V + E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V) for the visited array and result vector
    */
    void dfs(int v, vector<int> adj[], vector<int> &visited, vector<int> &result)
    {
        visited[v] = 1;

        result.push_back(v);

        for (int x : adj[v])
        {
            if (!visited[x])
                dfs(x, adj, visited, result);
        }
    }

    /*
        @description: Find the number of provinces (connected components) in a graph represented as an adjacency matrix
        @param isConnected: The adjacency matrix representing the graph
        @return: The number of provinces
        @time complexity: O(V^2) where V is the number of vertices
        @space complexity: O(V) for the adjacency list and visited array
    */
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();
        vector<int> adjList[v];

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1 and i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(v, 0);
        int components = 0;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                components++;

                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (auto &nbx : adjList[node])
                    {
                        if (!visited[nbx])
                        {
                            visited[nbx] = 1;
                            q.push(nbx);
                        }
                    }
                }
            }
        }

        return components;
    }

    /*
        @description: Find the number of connected components in a graph represented as an adjacency list
        @param V: Number of vertices
        @param edges: List of edges
        @return: The number of connected components
        @time complexity: O(V + E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V) for the adjacency list and visited array
    */
    int cntComponents(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(V);
        for (auto &e : edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        vector<int> visited(V, 0);
        int components = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                components++;

                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (auto &nbx : adjList[node])
                    {
                        if (!visited[nbx])
                        {
                            visited[nbx] = 1;
                            q.push(nbx);
                        }
                    }
                }
            }
        }

        return components;
    }

    /*
        @description: Find the minimum number of minutes to rot all oranges in a grid
        @param grid: The grid representing the state of oranges
        @return: The minimum number of minutes, or -1 if not all oranges can rot
        @time complexity: O(m * n) where m and n are the dimensions of the grid
        @space complexity: O(m * n) for the queue
    */
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        int mins = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] != 0)
                    tot++;

                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        while (!rotten.empty())
        {
            int k = rotten.size();

            cnt += k;

            while (k--)
            {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i], ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }

            if (!rotten.empty())
                mins++;
        }

        return tot == cnt ? mins : -1;
    }

    bool detect(int src, vector<int> adj[], vector<int> vis)
    {
        vis[src] = 1;

        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto nbx : adj[node])
            {
                if (!vis[nbx])
                {
                    vis[nbx] = 1;
                    q.push({nbx, node});
                }
                else if (nbx != par)
                    return true;
            }
        }

        return false;
    }

    /*
        @description: Detect if there is a cycle in an undirected graph
        @param V: Number of vertices
        @param adj: Adjacency list representing the graph
        @return: True if there is a cycle, false otherwise
        @time complexity: O(V + E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V) for the visited array and queue
    */
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detect(i, adj, visited))
                    return true;
            }
        }

        return false;
    }

    /*
        @description: Count the number of enclaves in a grid
        @param grid: The grid representing land and water
        @return: The number of enclaves (land cells that cannot reach the boundary)
        @time complexity: O(m * n) where m and n are the dimensions of the grid
        @space complexity: O(m * n) for the visited array and queue
    */
    // int numEnclaves(vector<vector<int>> &grid)
    // {
    //     if (grid.empty() || grid[0].empty())
    //         return 0;

    //     int n = (int)grid.size(), m = (int)grid[0].size();
    //     vector<vector<int>> vis(n, vector<int>(m, 0));
    //     queue<pair<int, int>> q;

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
    //             {
    //                 if (grid[i][j] == 1)
    //                 {
    //                     vis[i][j] = 1;
    //                     q.push({i, j});
    //                 }
    //             }
    //         }
    //     }

    //     int delrow[] = {-1, 0, +1, 0}, delcol[] = {0, +1, 0, -1};

    //     while (!q.empty())
    //     {
    //         auto [row, col] = q.front();
    //         q.pop();

    //         for (int i = 0; i < 4; i++)
    //         {
    //             int nr = row + delrow[i], nc = col + delcol[i];

    //             if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
    //             {
    //                 vis[nr][nc] = 1;
    //                 q.push({nr, nc});
    //             }
    //         }
    //     }

    //     int cnt = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             if (grid[i][j] == 1 && vis[i][j] == 0)
    //                 cnt++;
    //         }
    //     }

    //     return cnt;
    // }

    // /*
    //     @description: Find the length of the shortest transformation sequence from beginWord to endWord, where only one letter can be changed at a time and each transformed word must exist in the word list
    //     @param beginWord: The starting word
    //     @param endWord: The target word
    //     @param wordList: The list of allowed words for transformation
    //     @return: The length of the shortest transformation sequence, or 0 if no such sequence exists
    //     @time complexity: O(N * L*26) where N is the number of words in the word list, L is the length of each word, and 26 is the number of possible character transformations for each letter
    //     @space complexity: O(N*L) where N is the number of words in the word list and L is the length of each word for the queue and set
    // */
    // int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    // {
    //     queue<pair<string, int>> q;
    //     q.push({beginWord, 1});

    //     unordered_set<string> st(wordList.begin(), wordList.end());
    //     st.erase(beginWord);

    //     while (!q.empty())
    //     {
    //         auto [word, steps] = q.front();
    //         q.pop();

    //         if (word == endWord)
    //             return steps;

    //         for (int i = 0; i < word.size(); i++)
    //         {
    //             char orig = word[i];

    //             for (char ch = 'a'; ch <= 'z'; ch++)
    //             {
    //                 word[i] = ch;

    //                 if (st.find(word) != st.end())
    //                 {
    //                     st.erase(word);
    //                     q.push({word, steps + 1});
    //                 }
    //             }

    //             word[i] = orig;
    //         }
    //     }

    //     return 0;
    // }

    void dfs(int row, int col, int baseRow, int baseCol, vector<vector<char>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &shape)
    {
        vis[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i], ncol = col + dcol[i];

            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                dfs(nrow, ncol, baseRow, baseCol, grid, vis, shape);
        }
    }

    /*
        @description: Count the number of distinct islands in a grid, where two islands are considered distinct if their shapes are different
        @param grid: The grid representing land and water
        @return: The number of distinct islands
        @time complexity: O(m * n) where m and n are the dimensions of the grid
        @space complexity: O(m * n) for the visited array and shape vector
    */
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    vector<pair<int, int>> shape;
                    dfs(i, j, i, j, grid, vis, shape);
                    st.push_back(shape);
                }
            }
        }

        return st.size();
    }

    bool dfs(int node, int col, int c[], vector<vector<int>> graph)
    {
        c[node] = col;

        for (auto it : graph[node])
        {
            if (c[it] == -1)
            {
                if (dfs(it, !col, c, graph) == false)
                    return false;
            }
            else if (c[it] == col)
                return false;
        }

        return true;
    }

    /*
        @description: Determine if a graph is bipartite, meaning its vertices can be colored with two colors such that no two adjacent vertices share the same color
        @param graph: The adjacency list representing the graph
        @return: True if the graph is bipartite, false otherwise
        @time complexity: O(V + 2E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V) for the color array and recursion stack
    */
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();
        int c[v];
        for (int i = 0; i < v; i++)
            c[i] = -1;

        for (int i = 0; i < v; i++)
        {
            if (c[i] == -1)
            {
                if (dfs(i, 0, c, graph) == false)
                    return false;
            }
        }

        return true;
    }

    void sortDfs(int ind, vector<int> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[ind] = 1;

        for (auto it : adj[ind])
        {
            if (!vis[it])
                sortDfs(it, adj, vis, st);
        }

        st.push(ind);
    }

    /*
        @description: Perform topological sort on a directed acyclic graph using depth-first search
        @param v: Number of vertices
        @param adj: Adjacency list representing the graph
        @return: A vector containing the vertices in topologically sorted order
        @time complexity: O(V + E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V + E) for the visited array and stack
    */
    vector<int> topoSortDfs(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        stack<int> st;

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                sortDfs(i, adj, vis, st);
        }

        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }

    /*
        @description: Perform topological sort on a directed acyclic graph using breadth-first search (Kahn's algorithm)
        @param v: Number of vertices
        @param adj: Adjacency list representing the graph
        @return: A vector containing the vertices in topologically sorted order
        @time complexity: O(V + E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V + E) for the visited array and queue
    */
    vector<int> topoSortbfs(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
                vis[it]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
                q.push(i);
        }

        vector<int> res;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();

            res.push_back(n);

            for (auto it : adj[n])
            {
                vis[it]--;

                if (vis[it] == 0)
                    q.push(it);
            }
        }

        return res;
    }

    /*
        @description: Determine if all courses can be finished given their prerequisites
        @param numCourses: Number of courses
        @param prerequisites: List of prerequisite pairs
        @return: True if all courses can be finished, false otherwise
        @time complexity: O(V + E) where V is the number of courses and E is the number of prerequisites
        @space complexity: O(V + E) for the adjacency list and visited array
    */
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);

        for (auto it : prerequisites)
        {
            int a = it[0], b = it[1];
            adj[b].push_back(a);
            vis[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[n])
            {
                vis[it]--;

                if (vis[it] == 0)
                    q.push(it);
            }
        }

        return cnt == numCourses;
    }

    /*
        @description: Find the order of courses to finish given their prerequisites
        @param numCourses: Number of courses
        @param prerequisites: List of prerequisite pairs
        @return: A vector containing the order of courses to finish, or an empty vector if it's not possible to finish all courses
        @time complexity: O(V + E) where V is the number of courses and E is the number of prerequisites
        @space complexity: O(V + E) for the adjacency list and visited array
    */
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);

        for (auto it : prerequisites)
        {
            int a = it[0], b = it[1];
            adj[b].push_back(a);
            vis[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
                q.push(i);
        }

        vector<int> res;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();

            res.push_back(n);

            for (auto it : adj[n])
            {
                vis[it]--;

                if (vis[it] == 0)
                    q.push(it);
            }
        }

        if (res.size() == numCourses)
            return res;

        return {};
    }

    /*
        @description: Find all eventually safe nodes in a directed graph
        @param graph: The adjacency list representation of the graph
        @return: A vector containing all eventually safe nodes
        @time complexity: O(V + E) + O(N log N)`
        @space complexity: O(3N) for the adjacency list, indegree array, and queue
    */
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<vector<int>> adj(v);
        vector<int> indeg(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (int it : graph[i])
            {
                adj[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < v; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for (auto it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }

    /*
        @description: Find the shortest path from a source vertex to all other vertices in an unweighted graph
        @param edges: List of edges in the graph
        @param N: Number of vertices
        @param M: Number of edges
        @param src: The source vertex
        @return: A vector containing the shortest distance from the source vertex to each vertex, or -1 if a vertex is unreachable
        @time complexity: O(N+2M) where N is the number of vertices and M is the number of edges
        @space complexity: O(N+M) for the adjacency list and distance array
    */
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<vector<int>> adj(N);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(N, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);

        for (int i = 0; i < N; i++)
        {
            if (dist[i] != 1e9)
                ans[i] = dist[i];
        }

        return ans;
    }

    void topoSort(int node, vector<vector<pair<int, int>>> adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it.first])
                topoSort(it.first, adj, vis, st);
        }

        st.push(node);
    }

    /*
        @description: Find the shortest path from a source vertex to all other vertices in a weighted graph
        @param N: Number of vertices
        @param M: Number of edges
        @param edges: List of edges in the graph, each edge represented as {source, destination, weight}
        @return: A vector containing the shortest distance from the source vertex to each vertex, or -1 if a vertex is unreachable
        @time complexity: O(N + M)
        @space complexity: O(N + M)
    */
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(N);

        for (int i = 0; i < M; i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});

        vector<int> vis(N, 0), dist(N, 1e9);
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
                topoSort(i, adj, vis, st);
        }

        dist[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }

    /*
        @description: Find the shortest path from a source vertex to all other vertices in a weighted graph using Dijkstra's algorithm
        @param V: Number of vertices
        @param adj: Adjacency list representing the graph, where each edge is represented as {destination, weight}
        @param S: The source vertex
        @return: A vector containing the shortest distance from the source vertex to each vertex, or -1 if a vertex is unreachable
        @time complexity: O(E log V) where V is the number of vertices and E is the number of edges
        @space complexity: O(V + E) for the adjacency list and distance array
    */
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> s;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        s.insert({0, S});

        while (!s.empty())
        {
            auto it = *s.begin();
            int node = it.second, dis = it.first;
            s.erase(it);

            for (auto it : adj[node])
            {
                int aNode = it[0], aEdge = it[1];

                if (dis + aEdge < dist[aNode])
                {
                    if (dist[aNode] != 1e9)
                        s.erase({dist[aNode], aNode});

                    dist[aNode] = dis + aEdge;
                    s.insert({dist[aNode], aNode});
                }
            }
        }

        return dist;
    }

    /*
        @description: Find the shortest path from the top-left corner to the bottom-right corner in a binary matrix, where you can only move to adjacent cells that are 0 (open) and cannot move through cells that are 1 (blocked)
        @param grid: The binary matrix representing the grid
        @return: The length of the shortest path, or -1 if no such path exists
        @time complexity: O(4*m * n) where m and n are the dimensions of the grid
        @space complexity: O(m * n) for the distance array and queue
    */
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        if (n == 1 && m == 1)
            return 1;

        pair<int, int> dest = {n - 1, m - 1};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 0;
        q.push({0, {0, 0}});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!q.empty())
        {
            int distance = q.front().first, r = q.front().second.first,
                c = q.front().second.second;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 0 && distance + 1 < dist[nr][nc])
                {
                    dist[nr][nc] = distance + 1;

                    if (nr == dest.first && nc == dest.second)
                        return distance + 2;

                    q.push({distance + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }

    /*
        @description: Find the minimum effort path from the top-left corner to the bottom-right corner in a grid of heights
        @param heights: The grid of heights
        @return: The minimum effort required to reach the destination
        @time complexity: O(4 * m * n * log(m * n)) where m and n are the dimensions of the grid
        @space complexity: O(m * n) for the distance array and priority queue
    */
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        q.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int diff = q.top().first, r = q.top().second.first, c = q.top().second.second;
            q.pop();

            if (r == n - 1 && c == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int nr = dr[i] + r, nc = dc[i] + c;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int eff = max(abs(heights[r][c] - heights[nr][nc]), diff);

                    if (eff < dist[nr][nc])
                    {
                        dist[nr][nc] = eff;
                        q.push({eff, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }

    /*
        @description: Find the cheapest price to reach the destination within k stops
        @param n: Number of cities
        @param flights: List of flights with their prices
        @param src: Source city
        @param dst: Destination city
        @param k: Maximum number of stops allowed
        @return: The cheapest price to reach the destination, or -1 if not possible
        @time complexity: O(k * N)
        @space complexity: O(E+V) for the adjacency list and distance array
    */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty())
        {
            int steps = q.front().first, node = q.front().second.first, cost = q.front().second.second;
            q.pop();

            if (steps > k)
                continue;

            for (auto no : adj[node])
            {
                if (cost + no.second < dist[no.first] && steps <= k)
                {
                    dist[no.first] = cost + no.second;
                    q.push({steps + 1, {no.first, cost + no.second}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }

    /*
        @description: Find the network delay time for a given source node
        @param times: List of travel times between nodes
        @param n: Number of nodes
        @param k: Source node
        @return: The network delay time, or -1 if not possible
        @time complexity: O((E+V) * log V) where E is the number of edges and V is the number of nodes
        @space complexity: O(V + E) for the adjacency list and distance array
    */
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times)
        {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, k});

        while (!q.empty())
        {
            int w = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (it.second + w < dist[it.first])
                {
                    dist[it.first] = it.second + w;
                    q.push({dist[it.first], it.first});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());

        return ans == INT_MAX ? -1 : ans;
    }

    /*
        @description: Count the number of paths from source to destination with minimum cost
        @param n: Number of nodes
        @param roads: List of roads with their weights
        @return: The number of paths with minimum cost
        @time complexity: O(E * log V) where E is the number of edges and V is the number of nodes
        @space complexity: O(N) for the adjacency list and distance array
    */
    // int countPaths(int n, vector<vector<int>> &roads)
    // {
    //     vector<vector<pair<int, long long>>> adj(n);
    //     for (auto it : roads)
    //     {
    //         adj[it[0]].push_back({it[1], it[2]});
    //         adj[it[1]].push_back({it[0], it[2]});
    //     }

    //     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;

    //     vector<long long> dist(n, LLONG_MAX);
    //     vector<int> ways(n, 0);
    //     int mod = 1e9 + 7;

    //     dist[0] = 0;
    //     ways[0] = 1;
    //     h.push({0, 0});

    //     while (!h.empty())
    //     {
    //         auto [dis, node] = h.top();
    //         h.pop();

    //         if (dis > dist[node])
    //             continue;

    //         for (auto [dest, time] : adj[node])
    //         {
    //             if (dis + time < dist[dest])
    //             {
    //                 dist[dest] = dis + time;
    //                 h.push({dist[dest], dest});
    //                 ways[dest] = ways[node];
    //             }
    //             else if (dis + time == dist[dest])
    //             {
    //                 ways[dest] = (ways[dest] + ways[node]) % mod;
    //             }
    //         }
    //     }

    //     return ways[n - 1] % mod;
    // }

    /*
        @description: Find the shortest path from a source vertex to all other vertices in a weighted graph using Bellman-Ford algorithm, which can handle negative weight edges
        @param V: Number of vertices
        @param edges: List of edges in the graph, each edge represented as {source, destination, weight}
        @param S: The source vertex
        @return: A vector containing the shortest distance from the source vertex to each vertex, or -1 if a negative weight cycle is detected
        @time complexity: O(V * E) where V is the number of vertices and E is the number of edges
        @space complexity: O(V) for the distance array
    */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0], v = it[1], w = it[2];

                if (dist[u] != 1e9 && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }

        for (auto it : edges)
        {
            int u = it[0], v = it[1], w = it[2];

            if (dist[u] != 1e9 && dist[u] + w < dist[v])
                return {-1};
        }

        return dist;
    }

    /*
        @description: Find the shortest distance between all pairs of vertices in a graph using Floyd-Warshall algorithm
        @param matrix: The adjacency matrix representing the graph, where matrix[i][j] is the weight of the edge from vertex i to vertex j, or -1 if there is no edge
        @return: The modified adjacency matrix where matrix[i][j] is the shortest distance from vertex i to vertex j, or -1 if vertex j is unreachable from vertex i
        @time complexity: O(n^3) where n is the number of vertices
        @space complexity: O(V^2) for in-place modification of the input matrix
    */
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][k] == -1 || matrix[k][j] == -1)
                        continue;

                    if (matrix[i][j] == -1)
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    else
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    /*
        @description: Find the city with the smallest number of cities that are reachable within a given distance threshold
        @param n: Number of cities
        @param edges: List of edges in the graph, each edge represented as {source, destination, weight}
        @param distanceThreshold: The maximum distance allowed for a city to be considered reachable
        @return: The city number with the smallest number of reachable cities within the threshold, or the largest city number if there's a tie
        @time complexity: O(n^3) where n is the number of cities
        @space complexity: O(n^2) for the distance matrix
    */
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntCity = n, cityNo = -1;
        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= cntCity)
            {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }

    /*
        @description: Find the sum of all edge weights in the minimum spanning tree of a graph using Prim's algorithm
        @param V: Number of vertices
        @param adj: Adjacency list representing the graph, where each edge is represented as {destination, weight}
        @return: The sum of all edge weights in the minimum spanning tree
        @time complexity: O(E log E) where E is the number of edges and V is the number of vertices
        @space complexity: O(V + E) for the adjacency list and visited array
    */
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it[0], edgeWt = it[1];

                if (!vis[adjNode])
                    pq.push({edgeWt, adjNode});
            }
        }

        return sum;
    }
};

/*
    @description: Disjoint Set Union (DSU) or Union-Find data structure implementation with union by rank and union by size optimizations
    @author: Bharg Mahajan
*/
class DSU
{
    vector<int> rank, parent, size;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    /*
        @description: Find the ultimate parent of a node with path compression optimization
        @param node: The node for which to find the ultimate parent
        @return: The ultimate parent of the node
        @time complexity: O(log N) amortized, where N is the number of nodes
        @space complexity: O(1) for the recursive stack in path compression
    */
    int find(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    /*
        @description: Union two sets by rank
        @param u: First node
        @param v: Second node
        @return: None
        @time complexity: O(log N) amortized, where N is the number of nodes
        @space complexity: O(1) for the recursive stack in path compression
    */
    void unionByRank(int u, int v)
    {
        int up = find(u);
        int vp = find(v);

        if (up == vp)
            return;

        if (rank[up] > rank[vp])
            parent[vp] = up;
        else if (rank[up] < rank[vp])
            parent[up] = vp;
        else
        {
            parent[vp] = up;
            rank[up]++;
        }
    }

    /*
        @description: Union two sets by size
        @param u: First node
        @param v: Second node
        @return: None
        @time complexity: O(log N) amortized, where N is the number of nodes
        @space complexity: O(1) for the recursive stack in path compression
    */
    void unionBySize(int u, int v)
    {
        int up = find(u);
        int vp = find(v);

        if (up == vp)
            return;

        if (size[up] < size[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
        else
        {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }

    /*
        @description: Make all computers connected with minimum number of operations
        @param n: Number of computers
        @param connections: List of existing connections
        @return: Minimum number of operations required or -1 if not possible
        @time complexity: O(N + M × α(N)) where N is the number of computers and M is the number of connections
        @space complexity: O(N) for the parent and size arrays
    */
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        DSU dsu(n);
        for (auto edge : connections)
            dsu.unionByRank(edge[0], edge[1]);

        unordered_set<int> components;
        for (int i = 0; i < n; i++)
            components.insert(dsu.find(i));

        return components.size() - 1;
    }

    class DSUB
    {
    public:
        unordered_map<int, int> parent;

        int find(int x)
        {
            if (parent.find(x) == parent.end())
                parent[x] = x;

            if (x != parent[x])
                parent[x] = find(parent[x]);

            return parent[x];
        }

        void unite(int x, int y) { parent[find(x)] = find(y); }
    };

    /*
        @description: Remove maximum number of stones such that each remaining stone is isolated
        @param stones: List of stone positions
        @return: Maximum number of stones that can be removed
        @time complexity: O(N × α(N)) where N is the number of stones
        @space complexity: O(N) for the parent map
    */
    int removeStones(vector<vector<int>> &stones)
    {
        DSUB dsu;

        for (auto it : stones)
            dsu.unite(it[0], it[1] + 10001);

        unordered_set<int> components;
        for (auto stone : stones)
            components.insert(dsu.find(stone[0]));

        return stones.size() - components.size();
    }
};

class DSU
{
    vector<int> size, parent;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;

        return find(parent[node]);
    }

    void unite(int u, int v)
    {
        int up = find(u), vp = find(v);

        if (up == vp)
            return;

        if (size[up] < size[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
        else
        {
            parent[vp] = up;
            size[up] = size[vp];
        }
    }
};

class Solution
{
public:
    /*
        @description: Merge accounts with overlapping emails
        @param accounts: List of accounts with names and emails
        @return: Merged accounts with sorted emails
        @time complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N is the number of accounts and E is the total number of emails
        @space complexity: O(N) for the mail map and merged emails
    */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> mailMap;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];

                if (mailMap.find(mail) == mailMap.end())
                    mailMap[mail] = i;
                else
                    ds.unite(i, mailMap[mail]);
            }
        }

        vector<string> mailMerge[n];
        for (auto it : mailMap)
        {
            string mail = it.first;
            int node = ds.find(it.second);
            mailMerge[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mailMerge[i].empty())
                continue;

            sort(mailMerge[i].begin(), mailMerge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto mail : mailMerge[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    return 0;
}