class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), l = 1, r = piles[n - 1];
        int minK = r;
        while (l <= r) {
            int k = (l + r) / 2;
            long long need = 0;
            for (int bananas : piles) {
                bool hasRest = bananas % k > 0;
                need += bananas / k + hasRest;
            }
            if (need <= h) {
                minK = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return minK;
    }
};
