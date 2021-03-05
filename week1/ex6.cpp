#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> bit;

    std::cin >> n;
    while (n > 0) {
        bit.push_back(n % 2);
        n /= 2;
    }

    for (int i = bit.size() - 1; i >= 0; i--) {
        std::cout << bit[i];
    }
    return 0;
}
