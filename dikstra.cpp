#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <random>
using namespace std;

int V;

void dijkstra(vector<vector<int>> graph, int source)
{
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);
    distance[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int min = INT_MAX, min_index;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false && distance[i] <= min)
            {
                min = distance[i];
                min_index = i;
            }
        }

        visited[min_index] = true;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && graph[min_index][i] && distance[min_index] != INT_MAX && distance[min_index] + graph[min_index][i] < distance[i])
                distance[i] = distance[min_index] + graph[min_index][i];
        }
    }

    cout << "Vertex - Distance" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << i << "    -     " << distance[i] << endl;
    }
}

int main()
{
    srand(std::time(0));
    // vector<vector<int>> graph = {{0, 4, 0, 0},
    // 							 {4, 0, 8, 0},
    // 							 {0, 8, 0, 7},
    // 							 {0, 0, 7, 0}};

    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = rand() % 8;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << "\nStart - " << i << endl;
        dijkstra(graph, i);
    }
    return 0;
}