#include <iostream>
#include <vector>
using namespace std;

int Bellman_Ford(vector<vector<int>> &G, int V, int E, vector<pair<int, int>> &edge)
{
    int i, u, v, k, S, flag = 1;
    vector<int> distance(V, 1000);

    cout << "\nEnter source : ";
    cin >> S;

    distance[S - 1] = 0;

    for (i = 0; i < V - 1; i++)
    {
        for (k = 0; k < E; k++)
        {
            u = edge[k].first;
            v = edge[k].second;
            if (distance[u] + G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v];
        }
    }

    for (k = 0; k < E; k++)
    {
        u = edge[k].first;
        v = edge[k].second;
        if (distance[u] + G[u][v] < distance[v])
            flag = 0;
    }

    if (flag)
        for (i = 0; i < V; i++)
            cout << S << " - " << i + 1 << " : " << distance[i] << endl;

    return flag;
}

int main()
{
    int V, i, j, k = 0;
    cout << "Enter no. of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    vector<pair<int, int>> edge;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = rand() % 8;
        }
    }

    if (Bellman_Ford(graph, V, edge.size(), edge))
        cout << "\nNo negative weight cycle exists\n";

    return 0;
}