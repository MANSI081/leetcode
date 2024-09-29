class Solution {
public:
    char kthCharacter(int k) {
        string word="a";

        // loop until atleast k parts
        while(word.size()<k){
            string newWord="";

            // create a new string by convert each character
            for(char ch :word){
                if(ch=='z'){
                    newWord+='a'; //z followed by a
                }
                else{
                    newWord+=(ch+1);
                }
            }
            // appenfd new string to the current word
            word+=newWord;
        }
        // retur the kth elemnt
        return word[k-1];
    }
};