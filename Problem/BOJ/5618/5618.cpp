#include <stdio.h>
#include <algorithm>
#include <limits.h>

int arr[3];

int main(void) {
    int n, min1 = INT_MAX / 2;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        min1 = std::min(min1, arr[i]);
    }
    
    for(int i = 1; i <= min1; i++) {
        bool flag = false;
        
        for(int j = 0; j < n && !flag; j++)
            if(arr[j] % i != 0)
                flag = true;
        
        if(!flag)
            printf("%d\n", i);
    }
}