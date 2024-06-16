class Solution {
public:
// Time complexity: O(N)
// Space complexity: O(N)
    int countCompleteDayPairs(vector<int>& hours) {
        long long ans=0;
        unordered_map<int,int>ump;
        for(auto h:hours){
            ans+=ump[(24-h%24)%24];
            ump[h%24]++;
            
    }
    return ans;
    }
};