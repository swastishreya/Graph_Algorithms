#include <bits/stdc++.h>

using namespace std;

//Time complexity: O(V+E)
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
    }

    void topologicalSortUtil(int v, int *visited, stack <int> &S){
        visited[v] = 1;
        list <int>::iterator t;
        for(t = adj[v].begin(); t != adj[v].end(); t++){
            if(visited[*t] == 0)
                topologicalSortUtil(*t,visited,S);
        }
        S.push(v);
    }

    void topologicalSort(){
        stack <int> S;
        int *visited = new int[n];
        for(int i = 0; i < n; i++)
            visited[i] = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0)
                topologicalSortUtil(i,visited,S);
        }

        while(!S.empty()){
            cout << S.top() << endl;
            S.pop();
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
    g.topologicalSort();
    
}