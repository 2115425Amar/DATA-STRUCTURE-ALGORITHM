#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        unordered_map<int, bool> visited; 
        unordered_map<int, int>parent;
        
        queue<int>q;
        q.push(s);
        parent[s]=-1;
        visited[s]=1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    visited[i]=1;
                    parent[i]=frontNode;
                    q.push(i);
                }
            }
        }
        
        vector<int>ans;
        // If there's no path to t
        if (!visited[t]) return {-1}; // optional
        
        ans.push_back(t);
        
        int curr = t;
        while (curr != s) {
            curr = parent[curr];
            ans.push_back(curr);
        }
        reverse(ans.begin(), ans.end());
        return ans;
}

int main() {
    // Example graph:
    // 0 -- 1 -- 2
    // |    |
    // 3 -- 4
    int n = 5; // number of nodes
    int m = 5; // number of edges
    vector<pair<int,int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {1, 4},
        {3, 4}
    };
    int source = 0;
    int destination = 2;

    vector<int> path = shortestPath(edges, n, m, source, destination);

    if (path.size() == 1 && path[0] == -1) {
        cout << "No path found." << endl;
    } else {
        cout << "Shortest path from " << source << " to " << destination << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}


// Shortest path from 0 to 2: 0 1 2
