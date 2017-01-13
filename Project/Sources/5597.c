s[31];
main(t,i)
{
	for(i=0;i<28;i++)
	{scanf("%d",&t);s[t]=1;}
	for(i=1;i<31;i++)
		if(!s[i]) printf("%d\n",i);
}
