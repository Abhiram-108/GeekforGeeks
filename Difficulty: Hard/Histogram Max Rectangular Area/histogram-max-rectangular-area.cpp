class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
    //largest rectangle in histogram
    stack<int>st;
    int n=arr.size();
    vector<int>l(n),r(n);
    for(int i=0;i<n;i++){
        while(st.size() && arr[st.top()]>=arr[i])
        st.pop();
        
        if(st.size()==0)
        l[i]=0;
        else
        l[i]=st.top()+1;
        st.push(i);
    }
    while(st.size())
    st.pop();
    
    for(int i=n-1;i>=0;i--){
        while(st.size() && arr[st.top()]>=arr[i])
        st.pop();
        
        if(st.size()==0)
        r[i]=n-1;
        else
        r[i]=st.top()-1;
        
        st.push(i);
    }
    
    int maxi=0;
    for(int i=0;i<n;i++){
        int ans=arr[i]*(r[i]-l[i]+1);
        maxi=max(maxi,ans);
    }
    return maxi;
    }
};
