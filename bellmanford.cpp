#include <bits/stdc++.h>
using namespace std;

void Bellman_Ford(vector<vector<int>> &G, int V, int E, vector<pair<int, int>> &edge, vector<vector<int>> &ans)
{
    for (int p = 0; p < V; p++)
    {
        int i, u, v, k, S;
        vector<int> distance(V, 1000);
        S = p;
        distance[S] = 0;

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
        for (i = 0; i < V; i++)
            ans[S][i] = distance[i];
    }
}

int main()
{
    int V, i, j, k = 0;
    cout << "Enter no. of vertices: ";
    cin >> V;
    vector<vector<int>> ans(V, vector<int>(V, 0));
    vector<vector<int>> G(V, vector<int>(V, 0));
    vector<pair<int, int>> edge;

    cout << "Enter graph in matrix form:\n";
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            cin >> G[i][j];
            if (G[i][j] != 0)
                edge.emplace_back(i, j);
        }
    }

    Bellman_Ford(G, V, edge.size(), edge, ans);

    cout << "Final Graph is" << endl;
    for (auto x : ans)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
