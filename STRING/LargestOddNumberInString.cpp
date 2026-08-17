#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            if (digit % 2 != 0) {
                // Return prefix till this index
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution sol;

    string num;
    cout << "Enter number string: ";
    cin >> num;

    string result = sol.largestOddNumber(num);

    if (result == "")
        cout << "No odd number possible" << endl;
    else
        cout << "Largest odd number: " << result << endl;

    return 0;
}
