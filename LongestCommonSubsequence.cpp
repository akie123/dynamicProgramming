//Longest Common Subsequence
//Ques Link - https://leetcode.com/problems/longest-common-subsequence/
//Solution - 

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

       int n=text1.length(),m=text2.length();
       int arr[n+1][m+1];
       for(int i=0;i<=n;i++)
       {
           arr[i][0]=0;
       }
        for(int i=0;i<=m;i++)
       {
           arr[0][i]=0;
       }

       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               int a=arr[i][j-1],b=arr[i-1][j],c=arr[i-1][j-1];
               arr[i][j]=max(a,b);
               if(text1[i-1]==text2[j-1])
               {
                  arr[i][j]=max(arr[i][j],c+1);
               }
           }
       }
       return arr[n][m];

    }
};

// Approach
// Checking character by character and if at any point character matches we are side by side adding the previous result into out current result the same we do this in dp.

// Complexity
// Time complexity:
// o(n^2)

// Space complexity:
// o(n^2)


