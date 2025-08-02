// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// 1 -> 2 -> 0 -> 1 is a cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool solve(unordered_map<int,list<int>>&adj, unordered_map<int,int>&parent,
       unordered_map<int,bool>&visited, int node){
      
      queue<int>q;
      q.push(node);
      visited[node]=1;
      parent[node]=-1;
      
      while(!q.empty()){
          int front = q.front();
          q.pop();
          
          for(auto neighbour : adj[front]){
              if(visited[neighbour]==true && neighbour!=parent[front]){
                  return true;
              }
              else if(!visited[neighbour]){
                  visited[neighbour]=1;
                  parent[neighbour]=front;
                  q.push(neighbour);
              }
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
        
        bool ans;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if (solve(adj, parent, visited, i)) {
                    return true;
                }
            }
        }
        return false;
        
    }
};