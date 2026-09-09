class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        int total = n;

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
                total += candies[i] - 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                int newCandy = candies[i + 1] + 1;

                if (newCandy > candies[i]) {
                    total += newCandy - candies[i];
                    candies[i] = newCandy;
                }
            }
        }

        return total;
    }
};