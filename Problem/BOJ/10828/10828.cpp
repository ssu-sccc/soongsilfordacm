#include <stdio.h>
#include <string.h>
#include <stack>
int main(){
    std::stack<int> mystack;
    char input[6] = {0};
    int test, i, push_num;
    scanf("%d", &test);
    for(i = 1; i <= test; i++){
        scanf("%s", input);
        if(!strcmp(input, "push")){
            scanf("%d", &push_num);
                mystack.push(push_num);
        }
        else if(!strcmp(input, "top")){
            if(!mystack.empty()){
                printf("%d\n", mystack.top());
            }
            else
                printf("%d\n", -1);
        }
        else if(!strcmp(input, "size")){
            printf("%d\n", mystack.size());
        }
        else if(!strcmp(input, "pop")){
            if(!mystack.empty()){
                printf("%d\n", mystack.top());
                mystack.pop();
            }
            else
                printf("%d\n", -1);
        }
        else if(!strcmp(input, "empty")){
            if(!mystack.empty()){
                printf("%d\n", 0);
            }
            else
                printf("%d\n", 1);
        }
    }
    return 0;
}