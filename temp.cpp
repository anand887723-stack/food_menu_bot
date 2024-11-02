#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countMinimizeMaximizeSwaps(string &a, string &b)
{
    int operations = 0; // To count the number of swaps
    size_t n = a.length();

    // Step 1: Ensure a > b, swap if needed
    if (a < b)
    {
        swap(a, b);
    }

    // Step 2: Try to minimize 'a' and maximize 'b' by swapping digits
    for (size_t i = 0; i < n - 1; ++i)
    { // Leave the last digit for comparison
        for (size_t j = 0; j < n; ++j)
        {
            // Swap only if it helps minimize a and maximize b
            if (a[i] > b[j])
            {
                // Perform swap
                swap(a[i], b[j]);
                operations++;
                // Update 'a' and 'b' after the swap
                if (a < b)
                {
                    // If after swapping a is not greater than b, revert the swap
                    swap(a[i], b[j]);
                    operations--; // Decrease operation count as the swap is reverted
                }
            }
        }
    }

    return operations; // Return the total number of swaps
}

int main()
{
    string a, b;
    cout << "Enter first number (a): ";
    cin >> a;
    cout << "Enter second number (b): ";
    cin >> b;

    // Ensure the lengths are equal as per constraints
    if (a.length() != b.length() || a.empty() || b.empty())
    {
        cout << "Both strings must be of equal length and not empty." << endl;
        return 1;
    }

    int totalSwaps = countMinimizeMaximizeSwaps(a, b);
    cout << "Total number of swaps needed: " << totalSwaps << endl;

    return 0;
}
