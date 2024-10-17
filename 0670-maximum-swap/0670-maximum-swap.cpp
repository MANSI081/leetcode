class Solution {
public:
    int maximumSwap(int num) {
        // convert the bumberv to a string for easier digit manipulation
        string numstr=to_string(num);
        int n=numstr.size();

        // store the last occurence of each digit(0-9)
        vector<int>last(10,-1);
        for(int i=0;i<n;i++){
            last[numstr[i]-'0']=i;
        }

        // traverse each digit from left to right
        for(int i=0;i<n;i++){
            // check if there a larger digit appearing later
            for(int d=9;d>numstr[i]-'0';--d){
                if(last[d]>i){
                    // swap the current digit with alrger one
                    swap(numstr[i],numstr[last[d]]);
                    return stoi(numstr);//convert back to integer and return

                }
            }
        }
        // if no swap was made, return the original number
        return num;

    }
};