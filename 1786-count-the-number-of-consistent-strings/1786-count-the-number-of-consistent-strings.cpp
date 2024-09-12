class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        //support variable
        int res=words.size();
        bool alpha[26]={};
        // populating alpha
        for(char c:allowed) alpha[c-'a']=true;
        //parsing kall the words to sec if each caharacter is in alpha
        for(string word:words){
            // in case we find an unallowed character ,we decreadse res and braek
            for(char c:word)if (!alpha[c-'a']){
                res--;
                break;

            }
        }
        return res;
    }
};