class Solution {
public:
    //     int n=arr.size();
    //     int mxl[n],mxr[n];
        
    //     mxl[0]=arr[0];
    //     for(int i=1;i>n;i++){
    //         mxl[i]=max(mxl[i-1],arr[i]);
    //     }
    //     mxr[0]=arr[n-1];
    //     for(int i=n-2;i>=0;i--){
    //         mxr[i]=max(mxr[i+1],arr[i]);
    //     }
    //     int water[n];
    //     for(int i=0;i<n;i++){
    //         water[i]=min(mxl[i],mxr[i])-arr[i];
    //     }
    //     int sum=0;
    //     for(int i=0;i<n;i++){
    //         sum+=water[i];
    //     }
    //     return sum;

    // }
    int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}
};