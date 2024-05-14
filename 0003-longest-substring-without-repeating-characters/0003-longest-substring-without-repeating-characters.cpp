// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
    //     vector<int>mpp(256,-1);

    //     int l=0,r=0;
    //     int n=s.size();
    //     int len=0;
    //     while(r<n){
    //         if(mpp[s[r]]!=-1){
    //             l=max(mpp[s[r]]+1,l);
    //             mpp[s[r]]=r;

    //             len=max(len,r-l+1);
    //             r++;
    //         }
    //     }
    //                 return len;
    // }
    class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        int n=s.size();
        int left=0,right=0;
        int length=0;
        while(right<n){
            if(mpp[s[right]]!=-1)left =max(mpp[s[right]]+1,left);
            mpp[s[right]]=right;
            length=max(length,right-left+1);
            right++;
        }
        return length;


        }
    };
    