#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //given an index in argv[1], return the corresponding argument from argv[]
    #include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// Function to convert a string to a vector of integers (digits)
std::vector<int> stringToVector(const std::string& s) {
    std::vector<int> v;
    for (char c : s) {
        v.push_back(c - '0');
    }
    return v;
}

// Function to convert a vector of integers (digits) to a string
std::string vectorToString(const std::vector<int>& v) {
    std::string s;
    for (int digit : v) {
        s += std::to_string(digit);
    }
    return s;
}

// Function to perform addition of two large numbers represented as vectors of digits
std::vector<int> add(std::vector<int> num1, std::vector<int> num2) {
    std::vector<int> result;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i--];
        }
        if (j >= 0) {
            sum += num2[j--];
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// Function to perform subtraction of two large numbers represented as vectors of digits
// Assumes num1 >= num2
std::vector<int> subtract(std::vector<int> num1, std::vector<int> num2) {
    std::vector<int> result;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int borrow = 0;

    while (i >= 0) {
        int diff = num1[i--] - borrow;
        if (j >= 0) {
            diff -= num2[j--];
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff);
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// Function to compare two large numbers represented as vectors of digits
// Returns 1 if num1 > num2, -1 if num1 < num2, 0 if num1 == num2
int compare(const std::vector<int>& num1, const std::vector<int>& num2) {
    if (num1.size() > num2.size()) return 1;
    if (num1.size() < num2.size()) return -1;
    for (size_t i = 0; i < num1.size(); ++i) {
        if (num1[i] > num2[i]) return 1;
        if (num1[i] < num2[i]) return -1;
    }
    return 0;
}

// Function to perform multiplication of a large number (vector) by a single digit
std::vector<int> multiplyByDigit(std::vector<int> num, int digit) {
    if (digit == 0) return {0};
    std::vector<int> result;
    int carry = 0;
    for (int i = num.size() - 1; i >= 0 || carry; --i) {
        int prod = carry;
        if (i >= 0) {
            prod += num[i] * digit;
        }
        result.push_back(prod % 10);
        carry = prod / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// Karatsuba multiplication algorithm
std::vector<int> karatsuba(std::vector<int> num1, std::vector<int> num2) {
    // Base case for small numbers
    if (num1.size() < 2 || num2.size() < 2) {
        long long n1 = std::stoll(vectorToString(num1));
        long long n2 = std::stoll(vectorToString(num2));
        return stringToVector(std::to_string(n1 * n2));
    }

    // Pad with leading zeros to make lengths equal and even
    size_t n = std::max(num1.size(), num2.size());
    if (n % 2 != 0) {
        n++;
    }
    while (num1.size() < n) num1.insert(num1.begin(), 0);
    while (num2.size() < n) num2.insert(num2.begin(), 0);

    size_t half = n / 2;

    std::vector<int> a(num1.begin(), num1.begin() + half);
    std::vector<int> b(num1.begin() + half, num1.end());
    std::vector<int> c(num2.begin(), num2.begin() + half);
    std::vector<int> d(num2.begin() + half, num2.end());

    // Recursive steps
    std::vector<int> ac = karatsuba(a, c);
    std::vector<int> bd = karatsuba(b, d);
    std::vector<int> a_plus_b = add(a, b);
    std::vector<int> c_plus_d = add(c, d);
    std::vector<int> ad_plus_bc = subtract(karatsuba(a_plus_b, c_plus_d), add(ac, bd));

    // Combine results with appropriate shifts
    // ac * 10^n
    for (size_t k = 0; k < n; ++k) ac.push_back(0);
    // ad_plus_bc * 10^(n/2)
    for (size_t k = 0; k < half; ++k) ad_plus_bc.push_back(0);

    std::vector<int> result = add(add(ac, ad_plus_bc), bd);

    // Remove leading zeros
    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }
    return result;
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<int> num1 = stringToVector(s1);
    std::vector<int> num2 = stringToVector(s2);

    std::vector<int> product = karatsuba(num1, num2);
    std::cout << vectorToString(product) << std::endl;

    return 0;
}
}