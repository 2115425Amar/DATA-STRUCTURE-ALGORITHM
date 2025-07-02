// `vector<vector<int>> adj(n);` C++ mein ek **2D vector** banata hai, jo commonly **adjacency list** ko represent karne ke liye use hota hai, especially **graphs** ke context mein.

// ---
// ### 🧠 Breakdown:

// * `vector<vector<int>>` → ek vector hai, jismein har element bhi ek vector hai of type `int`.
// * `adj(n)` → iska matlab hai ki outer vector ka size `n` hai. Yaani:

//   * `adj[0]`, `adj[1]`, ..., `adj[n-1]` sab vectors hain (initially empty).


// ### 🕸️ Use case: Graph Representation (Adjacency List)

// Suppose tumhare paas `n` nodes ka graph hai. Har node `i` ke corresponding, `adj[i]` ek list store karta hai uske neighbors ki.

// #### Example:

// int n = 5;
// vector<vector<int>> adj(n);

// // Add edge between node 0 and 1
// adj[0].push_back(1);
// adj[1].push_back(0);

// // Add edge between node 0 and 4
// adj[0].push_back(4);
// adj[4].push_back(0);

// **Resulting Structure:**

// adj[0] = {1, 4}
// adj[1] = {0}
// adj[2] = {}
// adj[3] = {}
// adj[4] = {0}

// ### ✅ Conclusion:

// `vector<vector<int>> adj(n);` creates an adjacency list (or general 2D vector) with `n` rows, where each row can hold a list of integers. Useful for storing graphs, grids, or tables.

vector <vector<int>>printAdjacency(int n,int m,vector<vector<int>>&edges) {
    vector<vector<int>>adj(n);
   
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        vector<int>temp;
        temp.push_back(i);

        for(auto x:adj[i]){
            temp.push_back(x);    ///puri ki puri row push kar do
        }
        ans.push_back(temp);
    }
    return ans;
}