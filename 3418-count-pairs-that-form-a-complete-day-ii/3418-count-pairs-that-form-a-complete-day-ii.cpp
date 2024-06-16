class Solution {
public:
    #define ll long long
    long long countCompleteDayPairs(vector<int>& hours) {
        // construinve o fthe trtyuvtirw o fthe sintfor(int i=0;i<n;i+{git(intj=i+1;j<j;j++)}) change here thats why we have to
        int n=hours.size();

        unordered_map<ll,ll>freq;
        ll count=0;
        for(int j=0;j<n;j++){
            ll r=hours[j]%24;
            if(r==0){
                count+=freq[0];
            }
            else{
                count+=freq[24-r];
            }
            freq[r]++;
        }
        return count;
    }
};