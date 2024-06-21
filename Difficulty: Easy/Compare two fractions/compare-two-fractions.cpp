//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        string temp1="",temp2="";
        string temp="equal";
        int a=0;
        int b=0;
        bool indication=false;
        double res1,res2;
        for(auto it: str){
            if(it=='/')
            {
                indication=true;
                temp2+=it;
                continue;
            }
            else if(it==','){
                indication=false;
                res1=(double)a/b;
                a=0;
                b=0;
                temp1=temp2;
                temp2="";
                continue;
            }
            else if(it==' ')
            continue;
            temp2+=it;
            if(!indication){
                a=a*10+(it-'0');
            }
            else
            b=b*10+(it-'0');
        }
        res2=(double)a/b;
        if(res1==res2)
        return temp;
        else if(res1>res2)
        return temp1;
        else
        return temp2;
        

        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends