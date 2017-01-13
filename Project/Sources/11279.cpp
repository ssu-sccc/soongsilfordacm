#include <stdio.h>
int heap[100000],s=0;
void swap(int *a,int *b)
{
	int c;
	c=*a;	*a=*b;	*b=c;
}
void push(int tt)
{
	int i=s;
	heap[s++]=tt;
	int j=(i-1)/2;
	while(i>0 && heap[i]>heap[j])
	{
		swap(&heap[i],&heap[j]);
		i=j;	j=(j-1)/2;
	}
}
int pop()
{
	if(s==0)	return 0;
	int ans=heap[0];	heap[0]=heap[s--];
	int i=0;
	do
	{
		int l=i*2+1,r=l+1,c;
		if(l>s) break;
		if(r>s) c=l;
		if(heap[l]>heap[r])
			c=l;
		else c=r;

		if(heap[c]>heap[i])
		{
			swap(&heap[c],&heap[i]);
			i=c;
		}else break;
	}while(1);
	return ans;
}
int main()
{
	int n,t;	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		if(t) push(t);
		else printf("%d\n",pop());
	}
}
