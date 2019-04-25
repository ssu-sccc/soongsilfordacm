#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <vector>
#define M 1337377
using namespace std;
class Trie
{
private :
    struct moo
    {
        int go[26]; 
        int term;
    };
    typedef struct moo moo;
    //arr size must be >= total input_charater number.
    moo arr[1<<19];
    int sz = 0;
public:
    Trie()
    {
        memset(arr,0,sizeof(moo)*(1<<19)); sz = 0;
    }
    void add(char *str)
    {
        int cur = 0;
        for(int i=0;str[i];i++)
        {
            if(arr[cur].go[str[i]-'a']==0)
            {
                sz++;
                arr[cur].go[str[i]-'a'] = sz;
            }
            cur = arr[cur].go[str[i]-'a'];    
        }
        arr[cur].term++;
    }
    vector <int> find(char *str)
    {
        int cur = 0;
        vector <int> v; v.clear();
        for(int i=0;str[i];i++)
        {
            if(arr[cur].go[str[i]-'a']==0)
                break;
            cur = arr[cur].go[str[i]-'a'];
            if(arr[cur].term)
                v.push_back(i);
        }
        //if find str in Trie
        //check v[v.size()-1] == strlen(str)-1
        return v;
    }
    void del(char *str)
    {
        int cur = 0;
        for(int i=0;str[i];i++)
        {
            if(arr[cur].go[str[i]-'a']==0)
                return;
            cur = arr[cur].go[str[i]-'a'];
        }
        if(arr[cur].term!=0)
            arr[cur].term--;
    }
};
Trie trie;
char str[300002];
char pat[101];
int dp[300002];
void rev(char *tar);
void build(int lo,int ni);
vector <int> ti;
int main(void)
{
    int n; dp[0] = 1; scanf("%s\n%d\n",str+1,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s\n",pat); rev(pat); trie.add(pat);
    }
    for(int i=1;str[i];i++)
    {
        build(i,100);
        ti = trie.find(pat);
        int ret = 0;
        for(int j=0;j<ti.size();j++)
        {
            ret = ret + dp[i-1-ti[j]]; ret = ret%M;
        }
        dp[i] = ret;
    }
    printf("%d\n",dp[strlen(str+1)]);
    return 0;
}
void build(int lo,int ni)
{
    int p = 0;
    memset(pat,0,sizeof(char)*101);
    for(int i=lo;i>=max(lo-ni,1);i--)
    {
        pat[p++] = str[i];
    }
}
void rev(char *tar)
{
    char temp[101] = {0};
    int len = strlen(tar);
    for(int i=0;i<len;i++)
        temp[len-1-i] = tar[i];
    strcpy(tar,temp);
}
