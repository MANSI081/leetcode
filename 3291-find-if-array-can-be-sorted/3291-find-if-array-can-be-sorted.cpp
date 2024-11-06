// class Solution {
// public:
//     using int2=pair<int, int>;
//     bool canSortArray(vector<int>& nums) {
//         int2 prev={INT_MIN, INT_MIN}, curr;//(min, max) for this mutable subarray
//         const int n=nums.size();
//         int prevBit=-1;
//         for(int i=0; i<n; i++){
//             int x=nums[i];
//             int b=__builtin_popcount(x);
//             if (prevBit!=b){
//             //    cout<<"i="<<i<<" curr min="<<curr.first<<" prev max="<<prev.second<<endl;
//                 if (curr.first<prev.second) return 0;
//                 prev=curr;
//                 curr={x, x};
//                 prevBit=b;
//             }
//             else{
//                 curr.first=min(curr.first, x);
//                 curr.second=max(curr.second, x);
//             }
//         }
//         return curr.first>=prev.second;// compare last 2 segments
//     }
// };


// auto init = []()
// { 
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();


class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                int setCount = countSetBit(nums[j]);
                int setCount1 = countSetBit(nums[j + 1]);
                if (setCount == setCount1 && nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return isSorted(nums);
    }

private:
    int countSetBit(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }

    bool isSorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
};



