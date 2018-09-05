#include <bits/stdc++.h>

using namespace std;

class Graph{
    int n;
    list <int> *adj;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(Graph g, int v, int *visited){
        //Time Complexity: O(V+E)
        visited[v] = 1;
        cout << v << endl;
        list <int>::iterator t;
        for( t = adj[v].begin(); t != adj[v].end(); t++){
            if(visited[*t] == 0)
                DFS(g, *t, visited);
        }
    }

    void BFS(int s, int *visited){
        queue <int> q;
        q.push(s);
        visited[s] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << endl;
            list <int>::iterator t;
            for(t = adj[u].begin(); t != adj[u].end(); t++){
                if(visited[*t] == 0){
                    q.push(*t);
                    visited[*t] = 1;
                }
            }
        }
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
    int visited[] = {0,0,0,0,0,0}; 
    g.BFS(1,visited);
    
}