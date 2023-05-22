class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i =0; i<nums.size();i++){
            mp[nums[i]]++;//important
        }
        priority_queue<pair<int,int>>m;
        for(auto i:mp){ //this auto i:mp is important
            m.push(make_pair(i.second,i.first)); //the ordering is important
        }
        for(int i =0;i<k;i++){
            res.push_back(m.top().second); 
            m.pop();// pehle kya nikalna hai that is also important
        }
        return res;
    }
};