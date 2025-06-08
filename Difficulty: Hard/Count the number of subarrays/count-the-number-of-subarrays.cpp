// User function Template for C++
class Solution {
    
 long long   int help(vector<int>&a,long long target){
        int n=a.size();
        long long sum=0;
       long long int ct=0;
     long long   int l=0,r=0;
        while(r<n){
            sum+=a[r];
            while(sum>target){
                sum-=a[l];
                l++;
            }
            ct+=(r-l+1);
            r++;
        }
        return ct;
    }
  public:
  
    long long countSubarray(int N, vector<int> a, long long l, long long r) {
        // code here
        return (help(a,r)-help(a,l-1));
        
    }
};