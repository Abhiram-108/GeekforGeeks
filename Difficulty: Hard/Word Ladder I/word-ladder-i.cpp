class Solution {
  public:
    int wordLadderLength(string start, string target,
                         vector<string>& wordlist) {
        // Code here
        unordered_set<string>s(wordlist.begin(),wordlist.end());
        unordered_set<string>visited;
        
        queue<string>q;
        int level=1;
        q.push(start);
        visited.insert(start);
        
        while(q.size()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                
                if(curr==target)
                return level;
                
                for(char ch='a';ch<='z';ch++){
                    int m=curr.size();
                    for(int i=0;i<m;i++){
                    string temp=curr;
                        temp[i]=ch;
                        if(visited.find(temp)==visited.end() && s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
        
    }
};