class Solution {
public:
    int fillCups(vector<int>& amount) {
        int cold = amount[0];
        int warm = amount[1];
        int hot = amount[2];

        int sum = cold + warm + hot;

        return max(max(cold, warm), max(hot, (sum + 1) / 2));
    }
};