class Solution {
public:

// Time complexity: O(n∗m)
// Space complexity: O(1)

    int strStr(string haystack, string needle) {
        if(haystack.length()<needle.length()){
            return -1;
        }

        for(int i=0;i<=haystack.length()-needle.length();i++){
            if(haystack.substr(i,needle.length())==needle){
                return i;
            }
        }
        return -1;
        
    }
};