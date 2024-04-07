#include <iostream>
#include <string>

void reverseString(std::string& str, int start, int end) {
    if (start >= end)
        return;
    std::swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    reverseString(input, 0, input.length() - 1);

    std::cout << "Reversed string: " << input << std::endl;

    return 0;
}
