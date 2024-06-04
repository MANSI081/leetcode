class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_set<char>st;

        int result=0;

        for(char &ch:s){
            if(st.count(ch)){
                result+=2;//take pair of the element
                st.erase(ch);//then rase from kthe set

            }
            else{
                st.insert(ch);
            }
        }
        if(!st.empty()){
            // rreturn anns;
            // asns=ans
            // +1;
            result++;//only single element added to the pallindrome string

        }
        return result;
    }
};