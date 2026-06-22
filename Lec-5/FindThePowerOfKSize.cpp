#include <iostream>
#include <vector>
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i <= n - k; i++) {
        bool valid = true;

        for (int j = i + 1; j < i + k; j++) {
            if (nums[j] != nums[j - 1] + 1) {
                valid = false;
                break;
            }
        }

        if (valid)
            ans.push_back(nums[i + k - 1]);
        else
            ans.push_back(-1);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;

    vector<int> result = resultsArray(nums, k);

    for (int x : result)
        cout << x << " ";

    return 0;
}
