/**
 * @file BestTimeToSellStocks2.cpp
 * @brief Given an array of stock prices, find the maximum profit by buying and selling multiple times.
 * @author Mervin Nguyen
 * @date 2026-05-09
 * @version 1.0.0
 */
 
 #include <iostream>
 #include <vector>

 using namespace std;

/**
 * @brief Calculate the maximum profit from multiple buy/sell transactions.
 *
 * Sums all positive adjacent differences which is equivalent to buying at
 * each local valley and selling at the subsequent local peak. This allows
 * unlimited transactions but you cannot hold more than one share at a time.
 *
 * @param[in] prices Vector of stock prices by day.
 * @return Maximum achievable profit as an integer.
 * @note Time complexity: O(n). Space complexity: O(1).
 * @example max_profit({7,1,5,3,6,4}) == 7
 */
int max_profit(vector<int> &prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

 int main(void) {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {1, 2, 3, 4, 5};
    int result_1 = max_profit(prices1);
    int result_2 = max_profit(prices2);

    cout << "The maximum profit for prices1 is: " << result_1 << endl;
    cout << "The maximum profit for prices2 is: " << result_2 << endl;

    return 0;
 }