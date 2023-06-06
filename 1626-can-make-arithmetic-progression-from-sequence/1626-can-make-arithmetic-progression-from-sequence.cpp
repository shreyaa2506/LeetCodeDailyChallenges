class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int a = arr[1];
        int b = arr[0];
        int diff = a-b;

        for(int i =2; i<n;i++){
            if(arr[i]-arr[i-1]!=diff)return false;
        }
        return true;
    }
};