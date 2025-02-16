// https://leetcode.com/problems/merge-intervals

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||--
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class Solution
{
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (ans.size() != 0 && intervals[i][0] <= ans[ans.size() - 1][1])
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/