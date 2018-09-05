#include <bits/stdc++.h>

using namespace std;

class Graph{
    int n;
    vector < tuple <int,int,int>> adjList;
    vector <int> color, size, pi, *L;
    public:
    Graph(int vertices){
        n = vertices;
        L = new vector <int> [n];
        for(int i = 0; i < n; i++){
            color.push_back(i);
            size.push_back(1);
            L[i].push_back(i);
            pi.push_back(i);
        }
    }

    void addEdge(int u, int v, int w){
        adjList.push_back(tuple<int,int,int>(w,u,v));
        adjList.push_back(tuple<int,int,int>(w,v,u));
    }

    void kruskal(){
        sort(adjList.begin(), adjList.end());
        for(int i = 0; i < adjList.size(); i++){
            int u,v;
            u = get<1>(adjList[i]);
            v = get<2>(adjList[i]);
            if(color[u] != color[v]){
                if(size[color[u]] < size[color[v]]){
                    pi[u] = v;
                    int color_u = color[u];
                    vector <int> vertices_color_u;
                    vertices_color_u = L[color_u];
                    L[color_u].erase(L[color_u].begin(),L[color_u].end());
                    for(int k = 0; k < vertices_color_u.size(); k++){
                        L[color[v]].push_back(vertices_color_u[k]);
                    }
                    size[color[v]] = size[color[v]] + size[color[u]];
                    size[color[u]] = 0;
                    for(int j = 0; j < n; j++){
                        if(color[j] == color_u){
                            color[j] = color[v];
                        }
                    }
                    
                }
                else{
                    pi[v] = u;
                    int color_v = color[v];
                    vector <int> vertices_color_v;
                    vertices_color_v = L[color_v];
                    L[color_v].erase(L[color_v].begin(),L[color_v].end());
                    for(int k = 0; k < vertices_color_v.size(); k++){
                        L[color[u]].push_back(vertices_color_v[k]);
                    }
                    size[color[u]] = size[color[u]] + size[color[v]];
                    size[color[v]] = 0;
                    for(int j = 0; j < n; j++){
                        if(color[j] == color_v){
                            color[j] = color[u];
                        }
                    }
                    
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << "Color of vertex " << i << " is " << color[i] << endl;
        }
        for(int i = 0; i < n; i++)
            cout << pi[i] << " is parent of " << i  << endl;
    }

};

int main(){
    Graph g(5);
    g.addEdge(1, 0, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.kruskal();
}