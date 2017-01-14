#include <iostream>
#include <string>

int main(void) {
    std::string a;
    std::cin >> a;
    for(int i = 0; i < a.size(); i++) {
        if('a' <= a[i] && a[i] <= 'z')
            a[i] -= 'a' - 'A';
        else
            a[i] += 'a' - 'A';
    }
    std::cout << a << std::endl;
}