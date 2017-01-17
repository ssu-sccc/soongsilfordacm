#include <stdio.h>
#include <algorithm>

std::pair<int, int> arr[100010];

int main(void) {
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    
    std::sort(arr + 1, arr + 1+ n);
    for(int i = 1; i <= n; i++)
        printf("%d %d\n", arr[i].first, arr[i].second);
}