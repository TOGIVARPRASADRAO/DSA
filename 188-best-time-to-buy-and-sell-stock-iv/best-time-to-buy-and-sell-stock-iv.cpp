class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        if(n == 0) return 0;

        if(k >= n/2) {
            int profit = 0;
            for(int i = 1; i < n; i++) {
                if(prices[i] > prices[i-1])
                    profit += prices[i] - prices[i-1];
            }
            return profit;
        }

        vector<vector<int>> hold(k+1, vector<int>(n, 0));
        vector<vector<int>> notHold(k+1, vector<int>(n, 0));

        for(int j = 0; j <= k; j++)
            hold[j][0] = -prices[0];

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= k; j++) {

                hold[j][i] = max(
                    hold[j][i-1],
                    notHold[j-1][i-1] - prices[i]
                );

                notHold[j][i] = max(
                    notHold[j][i-1],
                    hold[j][i-1] + prices[i]
                );
            }
        }

        return notHold[k][n-1];
    }
};
