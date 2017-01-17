#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

int main(void)
{
        int n, len, check, j, i;
        char str[100];
        scanf("%d", &n);
        getchar();
        for(i = 0; i < n; i++)
        {
                check = 1;
                stack<int> sk;
                memset(str, 0, sizeof(str));
                scanf("%s", str);
                len = strlen(str);

                for(j = 0; j < len; j++)
                {
                        if(str[j] == '(')
                                sk.push(1);
                        else
                        {
                                if(sk.empty() && j != len - 1)
                                {
                                        check = 0;
                                        break;
                                }
                                sk.pop();
                        }
                }
                if(sk.empty() == 0 || check == 0)
                        printf("NO\n");
                else
                        printf("YES\n");
        }
        return 0;
}