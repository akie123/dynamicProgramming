// Longest Increasing Path in a Matrix
//Ques Link - https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//Solution - 
void dfs(vector<vector<int>>& mat,int co,vector<vector<int>>& ak,int i,int j)
    {
        int m=ak.size(),n=ak[0].size();
        
        if(ak[i][j]>co)
        return; 

        ak[i][j]=co;
       

        if(j-1>=0&&mat[i][j-1]>mat[i][j])
        {
             dfs(mat,co+1,ak,i,j-1);
        }
        if(j+1<n&&mat[i][j+1]>mat[i][j])
        {
             dfs(mat,co+1,ak,i,j+1);
        }
        if(i+1<m&&mat[i+1][j]>mat[i][j])
        {
             dfs(mat,co+1,ak,i+1,j);
        }
        if(i-1>=0&&mat[i-1][j]>mat[i][j])
        {
             dfs(mat,co+1,ak,i-1,j);
        }    

    }
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ak;
       
        for(int i=0;i<m;i++)
        {
            vector<int>bk;
            for(int j=0;j<n;j++)
            bk.push_back(0);

            ak.push_back(bk);
        
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j-1>=0&&mat[i][j-1]<mat[i][j])
                continue;
                if(i-1>=0&&mat[i-1][j]<mat[i][j])
                continue;
                if(i+1<m&&mat[i+1][j]<mat[i][j])
                continue;
                if(j+1<n&&mat[i][j+1]<mat[i][j])
                continue;
                dfs(mat,1,ak,i,j);
            }
        }
        int maxe=0;
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(ak[i][j]>maxe)
                maxe=ak[i][j];
            }
        }
        return maxe;

    }

    
};

// Approach
// Find points where all neighbouring element are greater than itself and apply dfs to neighbour and if(k>than previous) update value. 
// Complexity
// Time complexity:
// o(n^2)

// Space complexity:
// o(n^2)