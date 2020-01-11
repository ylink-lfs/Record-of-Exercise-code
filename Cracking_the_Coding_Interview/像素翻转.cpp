class Transform {
public:

    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        for(int i = 0; i < n/2; ++i){            
            for(int j = 0; j < n; ++j){                
                swap(mat[i][j], mat[n-1-i][j]);            
            }        
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }
};
