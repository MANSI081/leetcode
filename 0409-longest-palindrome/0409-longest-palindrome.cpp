class Solution {
public:
    int longestPalindrome(string s) {

        // Approach 1
    //     int n=s.length();
    //     unordered_set<char>st;

    //     int result=0;

    //     for(char &ch:s){
    //         if(st.count(ch)){
    //             result+=2;//take pair of the element
    //             st.erase(ch);//then rase from kthe set

    //         }
    //         else{
    //             st.insert(ch);
    //         }
    //     }
    //     if(!st.empty()){
    //         // rreturn anns;
    //         // asns=ans
    //         // +1;
    //         result++;//only single element added to the pallindrome string

    //     }
    //     return result;
    



    // aprroach2
//     int n=s.length();
//     unordered_map<char,int>mp; //char and int ko store karne ke liye in set
//     for(char &ch:s){
//         mp[ch]++;//sab ko map me daal lenge traverse kar ke
//     }

//     // /initialization
//     int result=0;
//     bool flag=false;
    
//     for(auto &it:mp){
//         // if the element prsent in the map at second position
//         if(it.second%2==0){//if even
//             result+=it.second;
//         }
//         else{
//             result+=it.second-1;
//             flag=true;//here use the next element

//         }
//     }

//     // last me agar odd frequency hai toh result++ kar dena hai
//     if(flag){//flag not true
//         result++;
//     }
// return result;
//     }


    // approach 3

    // 1 baar hi traverse hi karnah hoga
    int  n=s.length();
    unordered_map<char,int>mp;


    int result=0;
    int oddfreq=0;

    for(char &ch:s){

        mp[ch]++;
        if(mp[ch]%2!=0){//odd
            oddfreq++;
        }
        else{
            oddfreq--;
        }
    }
    if(oddfreq>0){
        return n-oddfreq+1;

    }
    return n;
    }

};