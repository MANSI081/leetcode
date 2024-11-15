class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        // step-1-find the jth pointer from right side
        int j=n-1;
        while(j>0 && arr[j]>=arr[j-1]){
            j--;//j jo hoga agar vo right me se bada nikal jaye
        }
        int i=0; //right side pointer
        // int result=n;  //worst case we shoulkd delete all elements
        int result=j;//we are removing all elements left to index j because indexj to n-1 are sorted


        // step-2 start finding correct i and j and find deleted elements = j-i-1
        while(i<j && (i==0|| arr[i]>=arr[i-1])){//increasing order of elements from i  
            // arr[j]<arr[i]  if j pointer value is smaller then i pointer value
            while(j<n && arr[i]>arr[j]){
                j++;
            }
            // we have found correct jth element such that arr[i]<=arr[j]
            result =min(result,j-i-1);
            i++;
        }
        return result;
    }
};