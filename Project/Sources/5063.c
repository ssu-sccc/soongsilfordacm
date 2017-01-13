main(T,a,b,c)
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a<b-c) printf("advertise\n");
		else if(a==b-c) printf("does not matter\n");
		else printf("do not advertise\n");
	}
}
