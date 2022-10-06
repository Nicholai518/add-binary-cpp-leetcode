#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        // pointers
        // starting at the end / back of the string and working to the front
        int i = a.length() - 1;
        int j = b.length() - 1;

        // string to be returned
        string result = "";

        // set carry to 0 by default
        // 1 + 1 = 2. Change 2 to 0 and set carry = 1
        int carry = 0;

        // while there are still numbers available 
        while (i >= 0 || j >= 0 || carry == 1)
        {

            // update carry
            if (i >= 0)
            {
                // becomes an int
                carry += a[i] - '0';

                // decrement i for next iteration
                i--;
            }

            // update carry
            if (j >= 0)
            {
                // becomes an int
                carry += b[j] - '0';

                // decrement j for next iteration
                j--;
            }

            // append to result
            // 2 % 2 = 0
            // 1 % 2 = 1
            result += carry % 2 + '0';

            // reset carry
            carry /= 2;
        }

        // all numbers are added to the end of the result
        // we need to reverse result to have the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};


int main()
{
    Solution solution;

    string example_one_a = "11";
    string example_one_b = "1";

    string example_two_a = "1010";
    string example_two_b = "1011";

    cout << "Example One : " << solution.addBinary(example_one_a, example_one_b) << endl;
    cout << "Example Two : " << solution.addBinary(example_two_a, example_two_b) << endl;

	return 0;
}
