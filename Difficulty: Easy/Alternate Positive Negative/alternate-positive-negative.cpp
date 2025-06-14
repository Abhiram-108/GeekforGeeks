// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &a) {
        // code here
        queue<int>q1,q2;
        int n=a.size();
        for(int i=0;i<n;i++){
        if(a[i]>=0)
        q1.push(a[i]);
        else
        q2.push(a[i]);}
        
       int i=0;
       while(q1.size() && q2.size()){
           if(i&1){
               a[i]=q2.front();
               q2.pop();
               
           }
           else{
               a[i]=q1.front();
               q1.pop();
               
           }
           i++;
       }
       while(q1.size()){
           a[i]=q1.front();
           q1.pop();
           i++;
       }
       while(q2.size()){
           a[i]=q2.front();
           q2.pop();
           i++;
       }
    }
};