

class Solution {
  public:
    int isPossible(int x, int y, int a, int b) {
        // code here
    if(gcd(x,y)==gcd(a,b))
    return 1;
    return 0;
    }
};