// Partition Equal Subset Sum
// Ques Link - https://leetcode.com/problems/partition-equal-subset-sum/
// Solution - 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        int n=nums.size();
        int ak[n+1][sum+1];
        for(int j=0;j<=sum;j++)
        ak[0][j]=0;
        for(int i=0;i<=n;i++)
        ak[i][0]=1;
       
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=sum/2;j++)
            {
                ak[i+1][j]=ak[i][j];
                if(j>=nums[i]){
                ak[i+1][j]=ak[i][j];
                if(ak[i][j-nums[i]]==1)
                ak[i+1][j]=1;
                }
            }
        }
    
        if(sum%2!=0)
        return 0;
        return ak[n][sum/2];


    }
};

// Approach
// Checking character by character and if at any point character matches we are side by side adding the previous result into out current result the same we do this in dp.
// Considering you know how to calculate subset sum equal to given sum .
// Just check if the total sum is even or odd .
// 1.odd: corresponds that you cant get 2 equal sum subset.
// 2.even:corresponds that you might get therefore pass the total sum divided by 2 as target sum if it return true that means the rest element sum will computed as target too.
// Therefore you can seemply return true

// Complexity
// Time complexity:O(n*sum)

// Space complexity:O(n*sum)