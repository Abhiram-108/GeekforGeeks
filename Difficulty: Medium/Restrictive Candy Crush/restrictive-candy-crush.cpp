class Solution {
  public:
    string Reduced_String(int k, string s) {
        // Your code goes here
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            st.push(ch);
            int ct=0;
            while(st.size() && st.top()==ch){
                st.pop();
                ct++;
            }
            if(ct==k)
            continue;
            else{
                while(ct--){
                    st.push(ch);
                }
            }
        }
        
        string res="";
         n=st.size();
        while(n--){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};