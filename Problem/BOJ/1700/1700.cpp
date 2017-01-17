#include <stdio.h>
#include <queue>

std::queue<int> adj[200];
int arr[200], check[200], checking[200];
int muti[200];
  
int main(void)
{
    int n, k, i, j, result = 0;
  
    scanf("%d %d", &n, &k);
  
    for (i = 0; i < k; i++)
    {
        scanf("%d", arr + i);
        check[arr[i]]++;
		adj[arr[i]].push(i);
    }
    int u = 0;
    for (i = 0; i < k; i++) {
        if(checking[arr[i]] == 0)
            muti[u++] = arr[i];
        checking[arr[i]] = 1;
        check[arr[i]]--;
		adj[arr[i]].pop();
        if(u == n) break;
    }
	i++;
    for (; i < k; i++)
    {
        int min1 = 0;
        for (j = 0; j < n; j++) {
            if (muti[j] == arr[i])
				break;
            if (check[muti[j]] == 0)
                min1 = j;
			else if(check[muti[min1]] != 0 && adj[muti[min1]].front() < adj[muti[j]].front())
				min1 = j;
        }

        check[arr[i]]--;
		adj[arr[i]].pop();
        if (j == n) {
            result++;
            muti[min1] = arr[i];
        }
    }
  
    printf("%d\n", result);
    return 0;
  
}