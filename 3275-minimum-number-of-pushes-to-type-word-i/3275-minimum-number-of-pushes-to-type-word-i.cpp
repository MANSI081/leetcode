class Solution {
public:
    int minimumPushes(string word) {
        int result=0;
        unordered_map<int,int>mp;

        int assign_key=2;

        for(char &ch:word){
            if(assign_key>9){
                assign_key=2;
            }
            mp[assign_key]++;//word hashing
            result+=mp[assign_key];
            assign_key++;//23456789 assign keys
        }
        return result;
    }
};