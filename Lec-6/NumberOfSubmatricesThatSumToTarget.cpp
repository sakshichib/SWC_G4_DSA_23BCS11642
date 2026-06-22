#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Prefix sum for each row
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    int count = 0;

    for (int left = 0; left < cols; left++) {
        for (int right = left; right < cols; right++) {

            unordered_map<int, int> mp;
            mp[0] = 1;

            int currSum = 0;

            for (int row = 0; row < rows; row++) {
                int sum = matrix[row][right];

                if (left > 0)
                    sum -= matrix[row][left - 1];

                currSum += sum;

                if (mp.find(currSum - target) != mp.end())
                    count += mp[currSum - target];

                mp[currSum]++;
            }
        }
    }

    return count;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    cout << numSubmatrixSumTarget(matrix, target);

    return 0;
}
