#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
        void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st){
            vis[node]=1;
            for(auto x:adj[node]){
                int u = x.first;
                if(!vis[u]){
                    topoSort(u,adj,vis,st);
                }
            }
            st.push(node);
        }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector < pair < int, int >> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      int vis[N] = {0};
      stack<int> st;
        for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
    vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }
      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;
          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }
      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};
int main() {

  int N = 6, M = 7;
  
  vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector < int > ans = obj.shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }

  return 0;

}