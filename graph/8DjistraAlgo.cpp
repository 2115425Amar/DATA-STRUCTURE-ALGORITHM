#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        vector<int>dist(V, INT_MAX);
       
        set<pair<int,int>>st;
        st.insert(make_pair(0,src));
        dist[src]=0;
        
        while(!st.empty()){
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            
            //remove top record now
            st.erase(st.begin());
            
            for(auto neighbour : adj[topNode]){
                if(nodeDistance+neighbour.second < dist[neighbour.first]){  //see adjacency list for clearity
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    //distance update
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    
                    //record push in set
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
        return dist;
    }
};