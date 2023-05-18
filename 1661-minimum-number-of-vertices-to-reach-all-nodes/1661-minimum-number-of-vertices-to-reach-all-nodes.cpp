class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        vector<int>ans;

        unordered_map<int,list<int>>adj;
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        for(int i =0;i<indegree.size();i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;

    }
};