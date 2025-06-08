class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>&a, int k) {
        // code here
        deque<int>dq;
        int n=a.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            
            if(dq.size() && dq.front()<=i-k)
            dq.pop_front();
            
            while(dq.size() && a[dq.back()]<=a[i])
            dq.pop_back();
            
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(a[dq.front()]);
            }
        }
        return ans;
    }
};
