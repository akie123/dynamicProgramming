//Climbing Stairs
//Ques Link -https://leetcode.com/problems/climbing-stairs/
//Solution - 
class Solution {
public:
    int climbStairs(int n) {
        int ak[n+1];
        ak[0]=1;
        ak[1]=1;
        for(int i=2;i<=n;i++)
        ak[i]=ak[i-1]+ak[i-2];

        return ak[n];
    }
};

// Complexity
// Time complexity: O(n)
// Space complexity:O(n)