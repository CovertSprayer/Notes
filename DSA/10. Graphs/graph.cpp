//#bits/stdc++.h
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;


// ------------------------------------------- BFS traversal -------------------------------------------------


void bfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, int node, vector<int> &ans) {
    queue<int> pending;
    pending.push(node);
    visited[node] = true;
    
    
    while(pending.size() != 0){
        int front = pending.front();
        pending.pop();
        
        ans.push_back(front);
        
        for(auto x:adj[front]){
            if(!visited[x]){
                pending.push(x);
                visited[x] = true;
            }
        }
    }
    
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> ans;
    
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adj, visited, i, ans);
        }
    }
    return ans;
}




// ------------------------------------------- DFS traversal -------------------------------------------------


void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component, int node){
    component.push_back(node);
    visited[node] = true;
    
    for(auto i:adj[node]){
        if(!visited[i])
            dfs(adj, visited, component, i);
    }
    
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}




// ------------------------------------------- cycle detection (undirected)- BFS/DFS -------------------------------------------------


bool detectCycleBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node){
    unordered_map<int, int> parent;
    queue<int> pending;
    
    pending.push(node);
    parent[node] = -1;
    visited[node] = true;
    
    while(!pending.empty()){
        int front = pending.front();
        pending.pop();
        
        for(auto neighbour: adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                pending.push(neighbour);
            }
            else if(parent[front] != neighbour){
                return true;
            }
        }
    }
    return false;
}

bool detectCycleDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, int parent){
    visited[node] = true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool detect = detectCycleDFS(adj, visited, neighbour, node);
            if(detect)
                return true;
        }
        else if(parent != neighbour){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool sol = detectCycleDFS(adj, visited, i, -1);
            if(sol == 1)
                return "Yes";
        }
    }
    return "No";
}






// ------------------------------------------- cycle detection (directed)- DFS -------------------------------------------------


bool detectCycleDFS(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &visitedDFS, int node){
    visited[node] = true;
    visitedDFS[node] = true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool checkFurther = detectCycleDFS(adj, visited, visitedDFS, neighbour);
            if(checkFurther) return true;
        }
        else if(visitedDFS[neighbour]){
            return true;
        }
        
    }
    visitedDFS[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> visitedDFS;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);        
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool iscycle = detectCycleDFS(adj, visited, visitedDFS, i);
            if(iscycle) return true;
        }
    }
    return false;
}




// ------------------------------------------- cycle detection (directed)- BFS -------------------------------------------------

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> visitedDFS;
    vector<int> indegree(n);
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first -1;
        int v = edges[i].second -1;
        
        adj[u].push_back(v);        
    }
    
    for(int i=0; i<n; i++){
        for(auto elem: adj[i]){
            indegree[elem]++;
        }
    }
    
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        count++;

        for(auto x:adj[front]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }

    if(count == n)
        return false;
    else
        return true;

    // if(count < n)            // because if cycle is present count will never exceed n
    //     return true;
    // else                     // if count > n it will fail, but in this case count will either be less than n or equal to n;
    //     return false;
}




// ------------------------------------------- Topological Sort (DAG)- DFS -------------------------------------------------


void builtTopology(unordered_map<int, list<int>> &adj, vector<int> &visited, stack<int> &st, int node){
    visited[node] = true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            builtTopology(adj, visited, st, neighbour);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    //unordered_map<int, bool> visited;
    vector<int> visited(v,0);
    
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    stack<int> st;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            builtTopology(adj, visited, st, i);
        }
    }
    
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}




// ------------------------------------------- Topological Sort (DAG)- BFS -------------------------------------------------

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    vector<int> indegree(V);
    
    for(int i=0; i<V; i++){
        for(auto elem: adj[i]){
            indegree[elem]++;
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
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }
    return ans;
}



// ------------------------------------------- Shortest Path (undirected) -------------------------------------------------


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    
    // adj list
    for(int i=0; i<m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // traversing BFS
    queue<int> q;
    visited[s] = true;
    q.push(s);
    parent[s] = -1;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adj[front]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    
    vector<int> ans;
    
    //if(s == t) return ans;
    
    int temp = t;
    ans.push_back(temp);
    
    while(temp != s){
        temp= parent[temp];
        ans.push_back(temp);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}




// ------------------------------------------- Shortest Path -- dijkstra's Algo -------------------------------------------------


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int, list<pair<int, int>> > adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    set<pair<int, int>> st;
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;
    st.insert({0,source});
    
    while(!st.empty()){
        auto top = *(st.begin());
        int node = top.second;
        int dist = top.first;
        st.erase(st.begin());
        
        for(auto neighbour:adj[node]){
            if(distance[neighbour.first] > neighbour.second + dist){
                
                auto temp = st.find({distance[neighbour.first], neighbour.first});
                if(temp != st.end()){
                    st.erase(temp);
                    //st.insert({neighbour.second + dist , neighbour.first});
                }
                
                distance[neighbour.first] = neighbour.second + dist;
                st.insert({neighbour.second + dist, neighbour.first});
            }
        }
    }
    return distance;
    
}



// ------------------------------------------- Shortest Path -- bellmonFord -------------------------------------------------


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> distance(n+1, 1e9);     //1e1 = 10; 1e2 = 100; 1e3 = 1000; ...
    distance[src] = 0;

    for(int x=1; x<n; x++){
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if(distance[u] != 1e9 && (distance[v] > distance[u] + w))
                distance[v] = distance[u] + w;
        }
    }
//     return distance[dest];
    
    int flag = 0;
    for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if(distance[u] != 1e9 && (distance[v] > distance[u] + w))
                flag = 1;
    }
    
    if(flag == 0) return distance[dest];
    else return -1;
}

int main(){
    
    return 0;
}