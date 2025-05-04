#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Graph
{
    int vert;
    list<int> *adj;

    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                DFSUtil(*i, visited);
            }
        }
    }

public:
    Graph(int v)
    {
        vert = v;
        adj = new list<int>[vert];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void DFS_iterative(int s)
    {
        vector<bool> visited(vert, false);
        stack<int> stack;

        stack.push(s);

        while (!stack.empty())
        {
            s = stack.top();
            stack.pop();

            if (!visited[s])
            {
                cout << s << " ";
                visited[s] = true;
            }

            for (auto i = adj[s].rbegin(); i != adj[s].rend(); ++i)
            {
                if (!visited[*i])
                {
                    stack.push(*i);
                }
            }
        }
        cout << endl;
    }

    void DFS_recursive(int s)
    {
        vector<bool> visited(vert, false);
        DFSUtil(s, visited);
        cout << endl;
    }
};

int main()
{

    cout << "\n----- 2-Traverse for DFS in Graph -----\n\n";

    Graph g(50);
    g.addEdge(0, 10);
    g.addEdge(0, 20);
    g.addEdge(10, 30);
    g.addEdge(10, 40);
    g.addEdge(20, 30);
    g.addEdge(30, 40);

    cout << "Iterative DFS starting from vertex 0:\n";
    g.DFS_iterative(0);
    cout << "Iterative DFS starting from vertex 20:\n";
    g.DFS_iterative(20);

    cout << "Recursive DFS starting from vertex 0:\n";
    g.DFS_recursive(0);
    cout << "Recursive DFS starting from vertex 10:\n";
    g.DFS_recursive(10);

    return 0;
}