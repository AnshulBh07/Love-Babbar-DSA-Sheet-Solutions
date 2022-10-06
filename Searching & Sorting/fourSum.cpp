#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// highly inefficient : O(n^4)
vector<vector<int>> fourSum1(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int sum;
    int n = nums.size();
    vector<int> temp;
    vector<vector<int>> ans;
    for (int a = 0; a < n - 3; a++)
    {
        for (int b = a + 1; b < n - 2; b++)
        {
            for (int c = b + 1; c < n - 1; c++)
            {
                for (int d = c + 1; d < n; d++)
                {
                    sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == k)
                    {
                        temp.push_back(nums[a]);
                        temp.push_back(nums[b]);
                        temp.push_back(nums[c]);
                        temp.push_back(nums[d]);
                        ans.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
    }
    return ans;
}

//better : O(n^3)
vector<vector<int>> fourSum2(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> helper;
    int sum, start, end;
    int n = nums.size();
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            start = j + 1, end = n - 1;
            while (start < end)
            {
                sum = nums[i] + nums[j] + nums[start] + nums[end];
                if (sum == k)
                {
                    helper.push_back(nums[i]);
                    helper.push_back(nums[j]);
                    helper.push_back(nums[start]);
                    helper.push_back(nums[end]);

                    ans.push_back(helper);
                    helper.clear();
                    start++;
                    end--;
                }
                if(sum>k){
                    end--;
                }else if(sum<k){
                    start++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{10, 2, 3, 4, 5, 7, 8};
    int k = 23;
    vector<vector<int>> ans1 = fourSum1(nums, k);
    for (vector<int> x : ans1)
    {
        for (int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    vector<vector<int>> ans2 = fourSum2(nums, k);
    for (vector<int> x : ans2)
    {
        for (int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}