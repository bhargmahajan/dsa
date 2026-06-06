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
    int numEnclaves(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = (int)grid.size(), m = (int)grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0}, delcol[] = {0, +1, 0, -1};

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = row + delrow[i], nc = col + delcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    cnt++;
            }
        }

        return cnt;
    }

    /*
        @description: Find the length of the shortest transformation sequence from beginWord to endWord, where only one letter can be changed at a time and each transformed word must exist in the word list
        @param beginWord: The starting word
        @param endWord: The target word
        @param wordList: The list of allowed words for transformation
        @return: The length of the shortest transformation sequence, or 0 if no such sequence exists
        @time complexity: O(N * L*26) where N is the number of words in the word list, L is the length of each word, and 26 is the number of possible character transformations for each letter
        @space complexity: O(N*L) where N is the number of words in the word list and L is the length of each word for the queue and set
    */
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty())
        {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char orig = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = orig;
            }
        }

        return 0;
    }

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
};

int main()
{
    Graph g;
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};

    bool ans = g.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}