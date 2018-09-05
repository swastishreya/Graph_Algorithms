#include <bits/stdc++.h>
#define NIL -1
#define RED 0
#define YELLOW 1
#define BLUE 2
#define INF 999999

using namespace std;

class Graph{
    int n;
    list <int> *adj;
    vector <int> color, pi, priority, *w;
    vector < pair <int,int> > minHeap;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
        w = new vector <int> [n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                w[i].push_back(INF);
            }
        }
    }

    void addEdge(int u, int v, int weight){
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[u][v] = weight;
        w[v][u] = weight;
    }

    void bottomUpHeapify(int i, vector < pair <int,int> > &H){
        int p = (i-1)/2;
        while(i > 0 && H[i].first < H[p].first){
            swap(H[i],H[p]);
            i = p;
            p = (i-1)/2;
        }
    }

    void topDownHeapify(int i, vector < pair <int,int> > &H, int n){
        int l = 2*i + 1, r = 2*i + 2, min;
        while(r < n){
            if(H[l].first > H[r].first) min = r;
            else min = l;
            if(H[i].first > H[min].first){
                swap(H[i],H[min]);
                i = min;
                l = 2*i + 1;
                r = 2*i + 2;
            }
            else break;
        }
        if(l < n && H[l].first < H[i].first){
            swap(H[i],H[l]);
        }

    }

    void deleteMin(vector < pair <int,int> > &H){
        swap(H[0],H[(H.size())-1]);
        H.pop_back();
        topDownHeapify(0,H,H.size());
    }

    void decreaseKey(int i, int x, vector < pair <int,int> > &H){
        for(int j = 0; j < H.size(); j++){
            if(H[j].second == i){
                H[j].first = x;
                bottomUpHeapify(j,H);
            }
        }
    }

    void primMST(int s){
        for(int i = 0; i < n; i++){
            color.push_back(RED);
            pi.push_back(NIL);
            priority.push_back(w[s][i]);
        }

        color[s] = YELLOW;
        pi[s] = s;
        priority[s] = 0;

        minHeap.push_back(make_pair(priority[s],s));
        bottomUpHeapify(minHeap.size()-1,minHeap);

        while(!minHeap.empty()){
            int u = minHeap[0].second;
            deleteMin(minHeap);
            color[u] = BLUE;
            list <int>::iterator v;
            for( v = adj[u].begin(); v != adj[u].end(); v++){
                if(color[*v] == RED){
                    color[*v] = YELLOW;
                    pi[*v] = u;
                    priority[*v] = w[u][*v];
                    minHeap.push_back(make_pair(priority[*v],*v));
                    bottomUpHeapify(minHeap.size()-1,minHeap);
                }
                else if(color[*v] == YELLOW){
                    if(priority[*v] > w[u][*v]){
                        priority[*v] = w[u][*v];
                        decreaseKey(*v,w[u][*v],minHeap);
                        pi[*v] = u;
                    }
                }
            }
        }

    }

    void printPriority(int s){
        primMST(s);
        for(int i = 0; i < n; i++)
            cout << pi[i] << " is parent of " << i  << endl;
    }


};

int main(){
    Graph g(5);
    g.addEdge(0,1,4);
    g.addEdge(0,3,8);
    g.addEdge(1,2,6);
    g.addEdge(1,3,3);
    g.addEdge(3,4,1);
    g.addEdge(4,1,4);
    g.addEdge(4,2,1); 
    g.printPriority(4);   
}