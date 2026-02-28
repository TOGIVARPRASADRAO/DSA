class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        backtrack(candidates, target, 0, current);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) return;

        for (int i = index; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current);  // reuse allowed
            current.pop_back();  // undo choice
        }
    }
};