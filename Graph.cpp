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
    int countComponents(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        for (const auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(V, 0);
        int components = 0;

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                components++;
                
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while(!q.empty()) {
                    int node=q.front();
                    q.pop();

                    for(auto &nbx : adjList[node]) {
                        if(!visited[nbx]) {
                            visited[nbx] = 1;
                            q.push(nbx);
                        }
                    }
                }
            }
        }

        return components;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    Graph g;

    cout << "Number of Connected Components: " << g.countComponents(V, edges) << endl;

    return 0;
}