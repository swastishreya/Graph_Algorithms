#include <bits/stdc++.h>

using namespace std;

class Graph{
    int n;
    list <int> *adj;
    vector <int> inDeg, outDeg;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
        for(int i = 0; i < n; i++){
            inDeg.push_back(0);
            outDeg.push_back(0);
        }
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        inDeg[v] += 1;
        outDeg[u] += 1;
    }

    int eulerTour(){
        for(int u = 0; u < n; u++){
            if(inDeg[u] != outDeg[u])
                return 0;
        }
        return 1;
    }
    

};

int main(){
    // Graph g(7);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(5,2);
    // g.addEdge(2,6);
    // g.addEdge(6,0);

    Graph g1(5);
    g1.addEdge(1,0);
    g1.addEdge(2,1);
    g1.addEdge(0,2);
    g1.addEdge(0,5);
    g1.addEdge(3,4);
    g1.addEdge(3,0);
    g1.addEdge(2,3);
    g1.addEdge(4,2);
    if(g1.eulerTour())
        cout << "Euler Tour is possible!!" << endl;
    else 
        cout << "Euler Tour is not possible!!" << endl;
    
}