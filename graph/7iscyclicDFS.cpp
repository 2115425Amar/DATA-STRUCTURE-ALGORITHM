#include <bits/stdc++.h>
using namespace std;

   bool dfs(unordered_map<int,list<int>>&adj, int parent, unordered_map<int,bool>&visited, int node){
           
           visited[node]=true;
           
           for(auto neighbour:adj[node]){
               if(!visited[neighbour]){
                   
                   if( dfs(adj, node, visited, neighbour)){
                       return true;
                   }
               }
               else if(neighbour != parent){
                       return true;
                   }
           }
         return false;
  }
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        //create an adjacency matrix
        unordered_map<int,list<int>>adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,int>parent;
        unordered_map<int,bool>visited;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if (dfs(adj, -1, visited, i)) {
                    return true;
                }
            }
        }
        return false;
    }