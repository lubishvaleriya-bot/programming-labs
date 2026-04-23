#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = 1e9;


struct GraphMatrix {
    int n;
    vector<vector<int>> g;

    GraphMatrix(int n) {
        this->n = n;
        g.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int w = 1) {
        g[u][v] = w;
        g[v][u] = w;
    }
};


struct GraphList {
    int n;
    vector<vector<pair<int,int>>> g;

    GraphList(int n) {
        this->n = n;
        g.resize(n);
    }

    void addEdge(int u, int v, int w = 1) {
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
};

// ---------------- DFS ----------------
void dfsMatrix(GraphMatrix &gr, int v, vector<bool>& used) {
    used[v] = true;
    cout << v << " ";

    for (int i = 0; i < gr.n; i++)
        if (gr.g[v][i] && !used[i])
            dfsMatrix(gr, i, used);
}


void bfsList(GraphList &gr, int start) {
    vector<bool> used(gr.n, false);
    queue<int> q;

    q.push(start);
    used[start] = true;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";

        for (auto to : gr.g[v]) {
            if (!used[to.first]) {
                used[to.first] = true;
                q.push(to.first);
            }
        }
    }
}

bool isConnected(GraphMatrix &gr) {
    vector<bool> used(gr.n, false);
    dfsMatrix(gr, 0, used);

    for (bool x : used)
        if (!x) return false;
    return true;
}

void dijkstra(GraphList &gr, int start) {
    vector<int> dist(gr.n, INF);
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();

        if (d > dist[v]) continue;

        for (auto [to, w] : gr.g[v]) {
            if (dist[v] + w < dist[to]) {
                dist[to] = dist[v] + w;
                pq.push({dist[to], to});
            }
        }
    }

    cout << "\nDistances:\n";
    for (int i = 0; i < gr.n; i++)
        cout << i << ": " << dist[i] << "\n";
}

//demo
void demo() {
    GraphMatrix gm(5);
    GraphList gl(5);

    gm.addEdge(0,1);
    gm.addEdge(1,2);
    gm.addEdge(2,3);
    gm.addEdge(3,4);

    gl.addEdge(0,1,2);
    gl.addEdge(1,2,3);
    gl.addEdge(2,3,1);
    gl.addEdge(3,4,4);

    cout << "DFS (matrix): ";
    vector<bool> used(5,false);
    dfsMatrix(gm, 0, used);

    cout << "\n\nBFS (list): ";
    bfsList(gl, 0);

    cout << "\n\nConnected: " << (isConnected(gm) ? "Yes" : "No");

    dijkstra(gl, 0);
}

void interactive() {
    int n;
    cout << "Vertices: ";
    cin >> n;

    GraphList g(n);

    while (true) {
        cout << "\n1-add edge\n2-bfs\n3-dijkstra\n0-exit\n> ";
        int c; cin >> c;

        if (c == 0) break;

        if (c == 1) {
            int u,v,w;
            cout << "u v w: ";
            cin >> u >> v >> w;
            g.addEdge(u,v,w);
        }

        if (c == 2) {
            int s;
            cout << "start: ";
            cin >> s;
            bfsList(g,s);
        }

        if (c == 3) {
            int s;
            cout << "start: ";
            cin >> s;
            dijkstra(g,s);
        }
    }
}

// main
int main() {
    int mode;
    cout << "Mode (1-demo, 2-interactive): ";
    cin >> mode;

    if (mode == 1) demo();
    else interactive();

    return 0;
}