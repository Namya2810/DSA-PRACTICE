#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (true) {
            bool sorted = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) break;
            int idx = 0;
            int minSum = nums[0] + nums[1];

            for (int i = 1; i + 1 < nums.size(); i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }

        return ops;
    }
};
int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.minimumPairRemoval(nums);

    return 0;
}
