class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=arr.size();
        int cost=0;
        for(int i=0;i<n;i++)
        pq.push(arr[i]);
        
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            cost+=(x+y);
            pq.push(x+y);
        }
        
        return cost;
    }
};