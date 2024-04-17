//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    private:
    int f1(int a[],int temp[],int left,int mid,int right){
        int i=left;
        int k=left;
        int j=mid;
        int count=0;
        while((i<=mid-1) && (j<=right)){
            if(a[i]<=a[j])
            {
             temp[k++]=a[i++];  
            }
            else{
               temp[k++]=a[j++];
                count+=(mid-i);
            }
        }
        while(i<=mid-1)
          temp[k++]=a[i++];
        while(j<=right)
          temp[k++]=a[j++];
        for( i=left;i<=right;i++)
          a[i]=temp[i];
        return count;
    }
    int f(int a[],int temp[],int left,int right ){
       int mid=0;
       int count=0;
        if(right>left){
             mid=(right+left)/2;
          count= f(a,temp,left,mid);
        count+= f(a,temp,mid+1,right);
        count+=   f1(a,temp,left,mid+1,right);
        }
            return count;
        
    }
    public:
    int countPairs(int a[] , int n ) 
    {
        // Your code goes here  
        for(int i=0;i<n;i++){
            a[i]=i*a[i];
        }
        int temp[n];

      return   f(a,temp,0,n-1);
        
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends