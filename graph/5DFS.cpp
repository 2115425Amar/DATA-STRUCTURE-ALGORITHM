#include <vector>
using namespace std;

class Solution {
  public:
  
  vector<int> solve(vector<vector<int>>& adj, int n, vector<bool>&visited, int node, vector<int>&ans) {
      
      ans.push_back(node);
      visited[node]=1;
      
      for(auto i:adj[node]){
          if(!visited[i]){
              solve(adj, n, visited, i, ans);
            //   ans.push_back(i);
          }
      }
      return ans;
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>ans;
        vector<bool>visited(n,0);
        int node = 0;
        return solve(adj, n, visited, node, ans);
    }
};