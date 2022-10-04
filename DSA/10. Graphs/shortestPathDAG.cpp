//#bits/stdc++.h
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
#include<queue>


using namespace std;

class Graph{

    public:
    unordered_map<int, list<pair<int,int>> > adj;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdjMatrix (){
        for(auto x:adj){
            cout<<x.first<<"-> ";
            for(auto y:x.second){
                cout<<"(" <<y.first<<","<<y.second<<") ";
            }
            cout<<endl;
        }
    }

    //stack<int> s;

    vector<int> topoSort(int V) {
        vector<int> ans;
        vector<int> indegree(V);
        
        for(int i=0; i<V; i++){
            for(auto elem: adj[i]){
                indegree[elem.first]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto x:adj[front]){
                indegree[x.first]--;
                if(indegree[x.first] == 0){
                    q.push(x.first);
                }
            }
        }
        return ans;
    }

    void shortestPath(vector<int> topo, vector<int> &distance){
        for(int i=0; i<topo.size(); i++){
            if(distance[topo[i]] != INT_MAX){
                for(auto neighbour:adj[topo[i]]){
                    if(distance[neighbour.first] > distance[topo[i]]+neighbour.second)
                        distance[neighbour.first] = distance[topo[i]]+neighbour.second;
                    
                }
            }
        }
    }

};

int main(){

    Graph G;
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);
    int n = 6;                  // no of nodes

    vector<int> topo = G.topoSort(n);
    for(auto x:topo){
        cout<<x<<" ";
    } cout<<endl;
    //G.printAdjMatrix();

    int src = 1;
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    G.shortestPath(topo, distance);
    
    for(auto x:distance){
        cout<<x<<" ";
    }

    return 0;
}