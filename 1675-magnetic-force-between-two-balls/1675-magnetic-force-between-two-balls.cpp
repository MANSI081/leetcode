class Solution {
public:
    bool possibleplace(int force,vector<int>&position,int m){
        int prev=position[0];
        int countballs=1;

        //sare ball place kar paye ki nhi
        for(int i=1;i<position.size();i++)//1 se start karenge
        {
            int curr=position[i];
            if(curr-prev>=force){
                countballs++;
                prev=curr;
            }
            if(countballs==m)break;
        }
        return countballs==m;
}
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());

        int minforce=1;
        int maxforce=position[n-1];

        int result=0;
        while(minforce<=maxforce){
            int midforce=minforce+(maxforce-minforce)/2;

            if(possibleplace(midforce,position,m)){
                result=midforce;
                minforce=midforce+1;//aur betetr answer ke liye right side shigft
                // minfore{int msin of the{if
                
            }
            else{
                maxforce=midforce-1;//left side shift

            }
        }
        return result;

    }
};