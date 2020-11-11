#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l, d, n;
    std::cin >> l >> d >> n;
    l = l - 12;
    int count = l/d;
    if (!n) count++;
    int b;
    for (int i = 0; i < n; i++){
        std::cin >> b;
        count--;
    }
    std::cout << count << std::endl;
    return 0;
}