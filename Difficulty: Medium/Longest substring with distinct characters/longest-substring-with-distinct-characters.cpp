class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        map<int,int>mp;
        int l=0;
        int maxi=0;
        int ans=0;
        
        int hash[256];
        for(int i=0;i<256;i++) hash[i] = -1;
        for(int r=0;r<s.size();r++){
            
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                // cout<<l<<" ";
                l=hash[s[r]]+1;
                // cout<<l<<endl;
            }
            
            ans=r-l+1;
            maxi=max(ans,maxi);
            hash[s[r]]=r;
            
        }
        return maxi;
    }
};
