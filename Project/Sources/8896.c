#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char robots[11][33]={0};
		int i,j,n,k,cr,cs,cp,cd,aa;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",robots[i]);
		k=strlen(robots[0]);
		for(i=0;i<k;i++)
		{cr=cs=cp=cd=0;
			for(j=0;j<n;j++)
			{
				switch(robots[j][i])
				{
					case 'R': cr++;	break;
					case 'S': cs++; break;
					case 'P': cp++;	break;
					case 0  : cd++; break;
				}
			}
			if(cd==n-1) break;
			if(cr&&cs&&cp) continue;
			if(cr&&!cs&&!cp) continue;
			if(!cr&&cs&&!cp) continue;
			if(!cr&&!cs&&cp) continue;
			if(!cr)
				for(j=0;j<n;j++)
					if(robots[j][i]=='P')
						for(int ii=i;ii<k;ii++)
							robots[j][ii]=0;
			if(!cs)
				for(j=0;j<n;j++)
					if(robots[j][i]=='R')
						for(int ii=i;ii<k;ii++)
							robots[j][ii]=0;
			if(!cp)
				for(j=0;j<n;j++)
					if(robots[j][i]=='S')
						for(int ii=i;ii<k;ii++)
							robots[j][ii]=0;
		}
	/*	printf("\n");
		for(int t=0;t<n;t++)
			printf("%s\n",robots[t]);*/
		bool pass=true;	aa=n;
		if(i==k)	i--;
		for(j=0;j<n;j++)
			if(robots[j][i])
				if(pass)
				{pass=false; aa=j;}
				else
				{	aa=n; printf("0\n"); break;}
		if(aa!=n) printf("%d\n",aa+1);
	}
}
