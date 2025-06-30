class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        unordered_map<int, int>mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            int key = it.first;
            int freq = it.second;
            if(mpp.find(key + 1) != mpp.end()){
                maxi = max(maxi, freq + mpp[key + 1]);
            }
        }
        return maxi;
    }
};