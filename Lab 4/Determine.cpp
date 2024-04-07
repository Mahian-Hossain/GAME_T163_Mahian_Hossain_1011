#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str, int start, int end) {
    if (start >= end)
        return true;
    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Remove spaces and convert to lowercase
    input.erase(std::remove_if(input.begin(), input.end(), [](char c) { return std::isspace(c); }), input.end());
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (isPalindrome(input, 0, input.length() - 1))
        std::cout << "The string is a palindrome.\n";
    else
        std::cout << "The string is not a palindrome.\n";

    return 0;
}
