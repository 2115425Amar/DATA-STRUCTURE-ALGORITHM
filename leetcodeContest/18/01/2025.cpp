#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long cost = 0;
        for (int i = 0; i < n; i++) {
            cost += abs(arr[i] - brr[i]);
        }
        if (n > 1) {
            sort(arr.begin(), arr.end());
            sort(brr.begin(), brr.end());
            long long t = 0;
            for (int i = 0; i < n; i++) {
                t += abs(arr[i] - brr[i]);
            }
            t += k;
            return min(cost, t);
        }
        return cost;
    }
};

int main() {
    // Input arrays and k
    vector<int> arr = {-7, 9, 5};
    vector<int> brr = {7, -2, -5};
    long long k = 2;

    Solution solution;
    long long result = solution.minCost(arr, brr, k);

    // Output the result
    cout << "Minimum cost to make arrays identical: " << result << endl;

    return 0;
}
