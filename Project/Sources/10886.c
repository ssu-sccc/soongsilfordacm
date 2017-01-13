s;
main(t,a)
{
	scanf("%*d");
	while(~scanf("%d",&t))
		s+=t?1:-1;
	if(s>0) printf("Junhee is cute!\n");
	else printf("Junhee is not cute!\n");
}
