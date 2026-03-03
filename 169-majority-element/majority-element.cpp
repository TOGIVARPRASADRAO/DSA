class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        for(int val : nums){
            int fr=0;
            for(int el : nums){
                if(val==el){
                fr++;
            }
        }
        if(fr>n/2){
            return val;
            }
        }
        return -1;
    }
};