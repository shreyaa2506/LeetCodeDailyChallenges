class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums2.size());
        vector<int>result(nums1.size());
        stack<int>st;
        for(int i = nums2.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i]=-1;
            }
            else if (!st.empty() && st.top()>nums2[i]){
                ans[i]=st.top();
            }
            else{
                while(!st.empty()&& st.top()<nums2[i]){
                    st.pop();
                }
                if(!st.empty())ans[i]=st.top();
                else (ans[i]=-1);
                
            }
            st.push(nums2[i]);
        }
        for(int i =0; i<nums1.size();i++){
            for(int j =0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    result[i]=ans[j];
                }
            }

        }
        return result;
    }
};