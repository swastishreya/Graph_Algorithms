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

    void edgeClassification(int a, int b){
        DFS(0);
        if(d[b] < d[a] && d[a] < f[a] && f[a] < f[b])
            cout << "BACK EDGE" << endl;
        else if(d[a] < d[b] && d[b] < f[b] && f[b] < f[a])
            cout << "TREE or FORWARD EDGE" << endl;
        else if(d[b] < f[b] && f[b] < d[a] && d[a] < f[a])
            cout << "CROSS EDGE" << endl;
        else cout << "impossible edge" << endl;
    }

    int detectCycle(){
        DFS(0);
        int flag = 0;
        for(int u = 0; u < n; u++){
            list <int>::iterator v;
            for(v = adj[u].begin(); v != adj[u].end(); v++){
                if(d[*v] < d[u] && d[u] < f[u] && f[u] < f[*v]){
                    cout << "BACK EDGE between " << u << " and " << *v << endl;
                    flag = 1;
                }
            }
        }
        return flag;

    }

};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,1);
    g.addEdge(4,3);
    //g.DFS(0);
    g.detectCycle();    
}