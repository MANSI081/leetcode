class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // vector<int>count(26,0);
        // for(char &ch:s){
        //     count[ch-'a']++;//to get indeex avess
        // }

        // string result;

        // int i=25;// stratt from the last letter to find the largest element first 
        // while(i>=0){
        //     if(count[i]==0){
        //         i--;
        //         continue;
        //     }
        //     char ch='a'+i;//you will get a cahracter
        //     int freq =min(count[i],repeatLimit);

        //     result.append(freq,ch);//result+= string(ch,freq) 
        //     count[i]-=freq;

        //     if(count[i]>0)///frequency bachi toh nhi hai
        //     {
        //         // find next largest character
        //         int j=i-1;
        //         while(j>=0 && count[j]==0){
        //             j--;
        //         }
        //         if(j<0){
        //             break;
        //         }
        //         result.push_back('a'+j);
        //         count[j]--;
        //     } 

        // }
        // return result;


        // Approach 2  heap approach

        vector<int>count(26,0);
        for(char &ch:s){
            count[ch-'a']++;
        }

        // initialise the priority queue
        priority_queue<char>pq;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                char ch='a'+i;
                pq.push(ch);
            }
        }
        string result;

        while(!pq.empty()){
            char ch=pq.top();
            pq.pop();

            int freq=min(count[ch-'a'],repeatLimit);
            result.append(freq,ch);

            count[ch-'a']-=freq;

            if(count[ch-'a']>0 && !pq.empty()){
                char nextChar= pq.top();
                pq.pop();


                result.push_back(nextChar);
                count[nextChar-'a']--;

                if(count[nextChar-'a']>0){
                    pq.push(nextChar);
                }
                pq.push(ch);

            }
            
        }
        return result;

    

    }
};