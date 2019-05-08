//made by chogahui05
//BOJ 9249
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAX_N 1000011
using namespace std;
class SA
{
private:
    int SA[MAX_N];
    int lcp[MAX_N];
    struct moo
    {
        int r1,r2,lo,rank;
    };
    typedef struct moo moo;
    vector <moo> v;
public:
    void get_lcp(char *str)
    {
        int len = strlen(str); int h = 0,mmx = 0;
        int loc = -1;
        int lo;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='$')
                loc = i;
        }
        vector <int> Rank(MAX_N+1,0);
        for(int i=0;i<len;i++)
            Rank[SA[i]] = i;
        for(int i=0;i<len;i++)
        {
            if(Rank[i]==0)
                continue;
            int j = SA[Rank[i]-1];
            while(str[i+h] == str[j+h]) h++;
            lcp[Rank[i]] = h;
            if(h) h--;
        }

        //process
        for(int i=1;i<len;i++)
        {
            if((SA[i]<loc&&SA[i-1]>loc)||(SA[i]>loc&&SA[i-1]<loc))
            {
                if(mmx<lcp[i])
                {
                    mmx = lcp[i];
                    lo = SA[i];
                }
            }
        }
        printf("%d\n",mmx);
        for(int i=lo;i<lo+mmx;i++)
            printf("%c",str[i]);
    }
    void build_sa(char *str)
    {
        int len = strlen(str); moo I;
        vector <int> rank(MAX_N+1,0);
        vector <int> cnt(27,0);
        vector <moo> v;
        for(int i=0;i<len;i++)
        {
            rank[i] = (str[i]=='$')?26:str[i]-'a'; cnt[rank[i]]++;
        }
        for(int i=1;i<=26;i++) 
            cnt[i] += cnt[i-1];
        for(int i=len-1;i>=0;i--)
            SA[--cnt[rank[i]]] = i;
        for(int d=1;d<len;d*=2)
        {
            int r1,r2,mmx=0; v.clear();
            for(int i=0;i<cnt.size();i++) cnt[i] = 0;
            for(int i=0;i<len;i++)
            {
                I.r1 = rank[i]+1; I.r2 = ((i+d<len)?rank[i+d]:-1)+1; I.lo = i; v.push_back(I);
                mmx = max(I.r1,mmx); mmx = max(I.r2,mmx);
            }
            sort_v(v,mmx);
            //after sorting, calculate rank
            //rank array, SA array fill
            for(int i=0;i<v.size();i++) 
            {
                rank[v[i].lo] = v[i].rank; SA[i] = v[i].lo;
            }
            if(v[v.size()-1].rank==len-1)
                break;
        }
    }
private:
    void sort_v(vector <moo> &v,int mmx)
    {
        vector <moo> temp; temp.resize(v.size());
        int co[mmx+1]={0};
        for(int i=0;i<v.size();i++) co[v[i].r2]++;
        for(int i=1;i<mmx+1;i++) co[i] += co[i-1];
        for(int i=v.size()-1;i>=0;i--) temp[--co[v[i].r2]] = v[i];
        for(int i=0;i<mmx+1;i++) co[i]=0;
        for(int i=0;i<temp.size();i++) co[temp[i].r1]++;
        for(int i=1;i<mmx+1;i++) co[i] += co[i-1];
        for(int i=temp.size()-1;i>=0;i--) v[--co[temp[i].r1]] = temp[i];
        
        v[0].rank = 0;
        for(int i=1;i<v.size();i++)
            v[i].rank =  v[i-1].rank + (v[i].r1!=v[i-1].r1||v[i].r2!=v[i-1].r2);
    }
};
char str[MAX_N];
char pat[MAX_N];
int main(void)
{
    SA sa=SA(); scanf("%s\n%s",str,pat); 
    strcat(str,"$"); strcat(str,pat); sa.build_sa(str); sa.get_lcp(str);
    return 0;
}
