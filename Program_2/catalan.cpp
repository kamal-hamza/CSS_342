#include <iostream>
#include <vector>

using namespace std;

vector<long long> memo;

long long calcCatalan(int n) {
    if (n < 0) {
        return -1;
    }

    if (n <= 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += calcCatalan(i) * calcCatalan(n - 1 - i);
    }

    memo[n] = ans;
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    memo.assign(n + 1, -1);

    cout << "Catalan(" << n << ") = " << calcCatalan(n) << endl;
    return 0;
}
