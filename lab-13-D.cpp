#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Graph
{
    int vert;
    list<int> *adj;

public:
    Graph(int v)
    {
        vert = v;
        adj = new list<int>[vert];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        // adj[w].push_back(v); // Undirected ke liye ye bhi chalao
    }

    void BFS(int start)
    {
        queue<int> q;
        vector<bool> visited(vert, false);

        q.push(start);
        visited[start] = true;

        cout << "---> BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    cout << "\n----- 4-Traverse for BFS in Graph -----\n\n";

    Graph g(50);
    g.addEdge(0, 10);
    g.addEdge(0, 20);
    g.addEdge(10, 30);
    g.addEdge(10, 40);
    g.addEdge(20, 30);
    g.addEdge(30, 40);

    cout << "BFS Traversal Starting from Vertex 0:\n";
    g.BFS(0);
    cout << "BFS Traversal Starting from Vertex 10:\n";
    g.BFS(10);
    cout << "BFS Traversal Starting from Vertex 20:\n";
    g.BFS(20);

    return 0;
}