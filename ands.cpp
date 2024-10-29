#include <iostream>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    string cleaned = "";
    for (char c : s)
    {
        if (isalnum(c))
            cleaned += tolower(c);
    }
    int left = 0, right = cleaned.size() - 1;
    while (left < right)
    {
        if (cleaned[left++] != cleaned[right--])
            return false;
    }
    return true;
}

int main()
{
    cout << isPalindrome("Bob") << endl;                            // Output: 1 (true)
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl; // Output: 1 (true)
    cout << isPalindrome("Hello, World!") << endl;                  // Output: 0 (false)
    return 0;
}
