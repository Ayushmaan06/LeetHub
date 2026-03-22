class Solution {
public:
    void tip(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) swap(mat[i][j], mat[j][i]);  
        
        for(int i = 0 ; i < n ; i++)reverse(mat[i].begin(),mat[i].end());
    }
    bool comp(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(mat[i][j]!=target[i][j])return false;
        
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0 ; i < 4 ; i++){
            tip(mat);
            if(comp(mat,target))return true;
        }
        return false;
    }
};