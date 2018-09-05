#include <bits/stdc++.h>
#define NIL -1
#define RED 0
#define YELLOW 1
#define GREEN 2

using namespace std;

class Graph{
    int n;
    int t = 1;
    list <int> *adj;
    vector <int> color, pi, d, f;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    void DFS(int s){
        for(int u = 0; u < n; u++){
            color.push_back(RED);
            pi.push_back(NIL);
            d.push_back(0);
            f.push_back(0);
        }
        for(int u = 0; u < n; u++){
            if(color[u] == RED)
                DFS_visit(u);
        }

    }

    void DFS_visit(int u){
        color[u] = YELLOW;
        d[u] = t++;
        //cout << "discovery time of " << u << " is " << d[u] << endl;
        list <int>::iterator v;
        for(v = adj[u].begin(); v != adj[u].end(); v++){
            if(color[*v] == RED){
                pi[*v] = u;
                DFS_visit(*v);
            }
        }
        color[u] = GREEN;
        f[u] = t++;
        //cout << "finish time of " << u << " is " << f[u] << endl;
    }

    pair <int,int> detectCycle(){
        DFS(0);
        pair <int,int> backEdge;
        backEdge = make_pair(-1,-1);
        int flag = 0;
        for(int u = 0; u < n; u++){
            list <int>::iterator v;
            for(v = adj[u].begin(); v != adj[u].end(); v++){
                if(d[*v] < d[u] && d[u] < f[u] && f[u] < f[*v]){
                    //cout << u << "," << *v << endl;
                    backEdge = make_pair(u,*v);
                    break;
                }
            }
        }
        return backEdge;

    }

    void printPath(int u,int v){
        cout << u+1 << endl;
        while(pi[u] != v){
            cout << pi[u]+1 << endl;
            u = pi[u]; 
        }
        cout << v+1 << endl;
    }

};

int main(){
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u-1,v-1);
    }

    pair <int, int> cycle;
    cycle = g.detectCycle();
    cout << "If cycle is present, then the following is the cycle:" << endl;
    g.printPath(cycle.first, cycle.second);
    return 0;
}