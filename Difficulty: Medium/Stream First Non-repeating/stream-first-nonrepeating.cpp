class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
    queue<char>q;
    map<char,int>mp;
    string res="";
    for(int i=0;i<s.size();i++){
        q.push(s[i]);
        mp[s[i]]++;
        
        while(q.size() && mp[q.front()] > 1)
        q.pop();
        
        
        if(q.size()==0)
        res+='#';
        else
        res+=q.front();
        
    }
    return res;
    }
};