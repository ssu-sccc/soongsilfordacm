#include <stdio.h>

int arr[30];

int main(void) {
    for(int i = 1; i <= 28; i++)
        scanf("%d", arr + i);
    
    for(int i = 1; i <= 30; i++) {
        bool flag = false;
        
        for(int j = 1; j <= 28; j++)
            if(arr[j] == i)
                flag = true;
        
        if(!flag)
            printf("%d\n", i);
    }
}