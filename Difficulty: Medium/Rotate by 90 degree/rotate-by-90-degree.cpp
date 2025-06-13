// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n=mat.size();
    vector<vector<int>>temp=mat;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=temp[n-j-1][i];
        }
    }
}
