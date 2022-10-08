vector<int> twoSum(vector<int> &nums, int target)
{
    std::unordered_map<int, int> tmp;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp.count(target - nums[i]))
        {
            return {tmp[target - nums[i]], i};
        }
        tmp[nums[i]] = i;
    }
    return {-1, -1};
}