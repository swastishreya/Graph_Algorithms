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

    int kruskal(){
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
        sort(color.begin(),color.end());
        int sum = 1;
        int prod = 1;
        for(int i = 1; i < n; i++){
            //cout << "color: " << color[i] << endl;
            //cout << "1 sum: " << sum << ", prod: " << prod << endl;
            if(color[i-1] == color[i]) sum++;
            else{
                prod *= sum;
                sum = 1;
            }
            //cout << "2 sum: " << sum << ", prod: " << prod << endl;
        }
        return prod;
    }

};

int main(){
    int n,p;
    cin >> n >> p;
    Graph g(n);
    for(int i = 0; i < p; i++){
        int a,b;
        cin >> a >> b;
        g.addEdge(a,b,0);
    }
    cout << g.kruskal() << endl;
}
