/*
最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

// class Solution
// {
//   public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int *dp = new int[nums.size()];
//         dp[0] = nums[0];
//         for (int i = 1; i < nums.size(); i++)
//         {
//             dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//         }
//         return *std::max_element(dp,dp+nums.size());
//     }
// };
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int sum = 0;
        for (int num : nums)
        {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            res = max(res, sum);
        }
        return res;
    }
};

int main()
{
    int x;
    Solution s;
    vector<int> prices = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d", s.maxSubArray(prices));
    return 0;
}