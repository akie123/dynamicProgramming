//Integer Break
//Ques Link - https://leetcode.com/problems/integer-break/description/
//Solution - 

class Solution {
public:
    int integerBreak(int n) {
        int ak[n+1];
        ak[0]=0;
        ak[1]=1;
        ak[2]=1;
        for(int i=3;i<=n;i++)
        {
            if(i%2==0)
            ak[i]=(i/2)*(i/2);
            else
            ak[i]=(i/2+1)*(i/2);
            for(int j=1;j<=i-1;j++)
            {
                ak[i]=max(ak[i],ak[j]*ak[i-j]);
                ak[i]=max(ak[i],j*ak[i-j]);
                ak[i]=max(ak[i],(i-j)*ak[j]);
            }
        }
        return ak[n];
    }
};

// Approach
// ak(n) denote the maximum product we can get if we split n into positive integers. 
// Complexity
// Time complexity:
// o(n^2)

// Space complexity:
// o(n)