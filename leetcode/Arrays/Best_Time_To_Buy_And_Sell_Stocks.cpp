// Problem: Best Time to Buy and Sell Stock
// Difficulty: Easy
// Concept: Greedy / Running Minimum Tracking
// Time Complexity: O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } 
            else {
                int profit = prices[i] - min_price;
                max_profit = max(max_profit, profit);
            }
        }

        return max_profit;
    }
};
/*Pseudo Code
min_price = price[0]
max_profit = 0

for i from 1 to n
if(price[i] < min_price)
	min_price = price[i];
	else
	profit = price[i] - min_price
	max_profit = max(profit, max_profit)
	 
return max_profit
	
	
*/