#include <stdio.h>
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
		int hp,mp,ad,df,ahp,amp,aad,adf;
		scanf("%d%d%d%d%d%d%d%d",&hp,&mp,&ad,&df,&ahp,&amp,&aad,&adf);
		hp+=ahp;	ad+=aad;
		mp+=amp;	df+=adf;
		if(hp<1) hp=1;	if(mp<1) mp=1; if(ad<0) ad=0;
		printf("%d\n",hp+mp*5+ad*2+df*2);
	}
}
