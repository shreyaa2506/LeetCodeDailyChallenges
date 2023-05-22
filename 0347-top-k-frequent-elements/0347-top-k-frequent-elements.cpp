class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i =0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>m;
        for(auto i:mp){
            m.push(make_pair(i.second,i.first));
        }
        vector<int>res;
        for(int  i =0; i<k;i++){
            res.push_back(m.top().second);
            m.pop();
        }
        return res;
    }
};