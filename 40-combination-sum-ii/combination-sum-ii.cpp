class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        backtrack(candidates, target, 0, current);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current);
            current.pop_back();
        }
    }
};