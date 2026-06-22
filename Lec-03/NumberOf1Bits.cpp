#include <iostream>
using namespace std;

int countSetBits(unsigned int n) {
    int count = 0;

    while (n) {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main() {
    unsigned int n;
    cin >> n;

    cout << countSetBits(n);

    return 0;
}
