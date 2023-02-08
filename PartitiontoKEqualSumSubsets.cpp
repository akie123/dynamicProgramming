// Partition to K Equal Sum Subsets
// Ques Link - https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
// Solution - 

class Solution {
public:
    int dp[(1<<16)+2];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};

// Approach

// Let target = sum/k
// We are only starting a new subset when sum of previous subset is equal to target
// We are not allowing any state where the sum becomes more than the target value { dp[mask]+nums[i] <= tar } {avoids cases like {2,17,11} ,k = 3 }. So the sum of the (current subset + current element) is either less than target or equal to target. If it equals to target we can start the next subset
// Consider a valid dp state where sum of elements selected is equal to S, and S%target = r, then there are exactly [ (S - r) / target ] number of subsets that are equal to target due to the first and second statements.
// For the solution to return true there should be exactly 'K' subsets and this can only happen when dp[111.....1111] is a reachable/valid state. {So you can also replace dp[(1<<n)-1] == 0 with dp[(1<<n)-1] != -1 in above solution it would still work ,as it already has remainder 0 because sum%k == 0
// Complexity
// Time complexity:O(2^n*n)

// Space complexity:O(2^n)