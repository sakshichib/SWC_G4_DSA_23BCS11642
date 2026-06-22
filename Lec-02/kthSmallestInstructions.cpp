class Solution {
public:
    long long nCr(int n, int r) {
        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
        }

        return ans;
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0];
        int h = destination[1];

        string ans;

        while (h > 0 && v > 0) {
            long long count = nCr(h + v - 1, h - 1);

            if (k <= count) {
                ans += 'H';
                h--;
            } else {
                ans += 'V';
                k -= count;
                v--;
            }
        }

        while (h--)
            ans += 'H';

        while (v--)
            ans += 'V';

        return ans;
    }
};
