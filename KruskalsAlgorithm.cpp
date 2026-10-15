
#include <iostream>
#include <algorithm>
using namespace std;

#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[V];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    Edge edges[E] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    sort(edges, edges + E, compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int count = 0;

    cout << "Edge \tWeight\n";

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            totalCost += edges[i].weight;
            unite(u, v);
            count++;
        }
    }

    cout << "Total MST Cost: " << totalCost << endl;

    return 0;
}
