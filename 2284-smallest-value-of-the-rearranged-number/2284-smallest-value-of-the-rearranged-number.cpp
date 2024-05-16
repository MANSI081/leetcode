class Solution {
public:

long long stoll(string s){
    long long ans=0;
    for(int i=0;i<s.size();i++){
        ans=ans*10;
        ans+=(s[i]-'0');//string to long long integer
    }
    return ans;
}
    long long smallestNumber(long long num) {
     if(num<0){
        // make it positive
        num=num*-1;
        string s;
     while(num){
        int rem=num%10;
        num=num/10;
        s+=(rem+'0');
     }
     sort(s.begin(),s.end());
     reverse(s.begin(),s.end());//sabse bada number bananae ke liye
     return -1*stoll(s);
     }
     
     string s;
     while(num){
        int rem=num%10;
        num=num/10;
        s+=(rem+'0');//append chracter rem in a string from a integer
     }
     sort(s.begin(),s.end());
     if(s[0]!='0')return stoll(s);//stoll function convert string into long long
     else{
        int i=0;
        while(s[i]=='0')i++;
        swap(s[0],s[i]);
        return stoll(s);
     }



   /* // 
   int man of the ;
   while(s[i]==0)return amax 
    int naa=ans+1;
    for(itn i=0;i<n;i++)
{
    for(oitn j=i+1;j<n;j++)
    if(i+j<n)return ans;
}*/
    }

};