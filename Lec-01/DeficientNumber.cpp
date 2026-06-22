#include <iostream>
#include <cmath>
using namespace std;

void checkDeficient(int x) {
    int sum = 0;

    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            sum += i;

            if (i != x / i)
                sum += x / i;
        }
    }

    if (sum < 2 * x) {
        cout << "Deficient Number\n";
        cout << "Deficiency = " << (2 * x - sum);
    } else {
        cout << "Not Deficient";
    }
}

int main() {
    int x = 8;
    checkDeficient(x);
}
