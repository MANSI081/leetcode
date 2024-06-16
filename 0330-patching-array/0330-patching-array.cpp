class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count=0;
        int i=0;
        long reach=0;
        while(reach<n){//if your reach is less than n
            if(i>=nums.size()){
                // keee lowest upcoming elemeent
                reach+=reach+1;
                count++;


            }
            else if(i<nums.size() && nums[i]<=(reach+1)){//if itbid ledss than the reach
                reach+=nums[i];
                i++;
            }
            else{//missing element case herfore we should do patch
            reach+=reach+1;
            count++;

            }
        }
        return count;
    }
};