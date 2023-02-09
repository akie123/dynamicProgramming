// Minimum Path Sum
// Ques Link - https://leetcode.com/problems/minimum-path-sum/description/
// Solution - 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    int ak[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        ak[i][0]=1e6;
    }
    for(int i=0;i<=m;i++)
    {
        ak[0][i]=1e6;
    }
    ak[1][0]=0;
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=m;j++)
       {
           ak[i][j]=min(ak[i-1][j],ak[i][j-1])+grid[i-1][j-1];
       }

    }
    return ak[n][m];

    }
};

// Approach
// suppose the minimum path sum of arriving at point (i, j) is S[i][j], 
// then the state equation is S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j]

// Complexity
// Time complexity:O(n*m)

// Space complexity:O(n*m)