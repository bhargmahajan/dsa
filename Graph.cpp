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
        while(!st.empty()) {
            int node=st.top();
            st.pop();

            for(auto it:adj[node]) {
                if (dist[node] + it.second < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
            }
        }

        for(int i=0; i<N; i++) {
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
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        set<pair<int, int>> s;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        s.insert({0, S});

        while(!s.empty()) {
            auto it = *s.begin();
            int node=it.second, dis=it.first;
            s.erase(it);

            for(auto it: adj[node]) {
                int aNode=it[0], aEdge=it[1];

                if(dis+aEdge < dist[aNode]) {
                    if(dist[aNode]!=1e9)
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
};

int main()
{
    Graph g;
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];

    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res = g.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}