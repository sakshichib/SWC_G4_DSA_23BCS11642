#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void generateSums(vector<int>& arr, vector<long long>& sums) {
    int n = arr.size();

    for (int mask = 0; mask < (1 << n); mask++) {
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                sum += arr[i];
        }

        sums.push_back(sum);
    }
}

int minAbsDifference(vector<int>& nums, int goal) {
    int n = nums.size();

    vector<int> left(nums.begin(), nums.begin() + n / 2);
    vector<int> right(nums.begin() + n / 2, nums.end());

    vector<long long> leftSums, rightSums;

    generateSums(left, leftSums);
    generateSums(right, rightSums);

    sort(rightSums.begin(), rightSums.end());

    long long ans = LLONG_MAX;

    for (long long x : leftSums) {
        long long target = goal - x;

        auto it = lower_bound(rightSums.begin(), rightSums.end(), target);

        if (it != rightSums.end())
            ans = min(ans, llabs(x + *it - goal));

        if (it != rightSums.begin()) {
            --it;
            ans = min(ans, llabs(x + *it - goal));
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int goal;
    cin >> goal;

    cout << minAbsDifference(nums, goal);

    return 0;
}
