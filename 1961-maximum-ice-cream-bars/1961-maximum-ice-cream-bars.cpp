class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int i = 0;
        int c = 0;
        if (costs[i] > coins)
            return 0;
        while (coins && i < n) {
            if (costs[i] > coins)
                break;
            coins -= costs[i];
            i++;
            c++;
        }
        return c;
    }
};