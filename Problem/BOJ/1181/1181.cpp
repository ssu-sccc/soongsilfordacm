#include <stdio.h>
#include <algorithm>
#include <string>

std::string arr[20010];
char buffer[60];

int main(void) {
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%s", buffer);
        arr[i] = buffer;
    }
    
    std::sort(arr, arr + n, [](std::string a, std::string b) {
        if(a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    });
    printf("%s\n", arr[0].c_str());
    for(int i = 1; i < n; i++)
        if(arr[i] != arr[i - 1])
            printf("%s\n", arr[i].c_str());
}