#include <bits/stdc++.h>
#define NIL -1
#define RED 0
#define BLACK 1

using namespace std;

class Graph{
    int n;
    list <int> *adj;
    vector <int> color;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
        for(int i = 0; i < n; i++)
            color.push_back(NIL);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int checkBipartite(int s, int *visited){
        visited[s] = 1;
        color[s] = RED;
        queue <int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << endl;
            list <int>::iterator t;
            for(t = adj[u].begin(); t != adj[u].end(); t++){
                if(u == *t) return 0;
                if(visited[*t] == 0 && color[*t] == NIL){
                    q.push(*t);
                    visited[*t] = 1;
                    color[*t] = !color[u];
                }
                else if(color[*t] == color[u]) return 0;
            }
        }
        return 1;
    }    

};

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    // Graph g(4);
    // g.addEdge(0,1);
    // g.addEdge(0,3);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    int visited[] = {0,0,0,0};
    if(g.checkBipartite(0,visited))
        cout << "Bipartite !!" << endl;
    else 
        cout << "Not bipartite !!" << endl;
    
}