#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char roman[]={'I','V','X','L','C','D','M'};
int romani[]={1,5,10,50,100,500,1000};
char rans[100]={0};
int rtoa(char *input)
{
	int s,clvl=0,lvl=9999,ans=0;
	s=strlen(input);	
	for(int i=0;i<s;i++)
	{
		switch(input[i])
		{
			case 'M':
				clvl=1000;
				break;
			case 'D':
				clvl=500;
				break;
			case 'C':
				clvl=100;
				break;
			case 'L':
				clvl=50;
				break;
			case 'X':
				clvl=10;
				break;
			case 'V':
				clvl=5;
				break;
			case 'I':
				clvl=1;
				break;
		}
		if(lvl<clvl)
		{
			ans-=lvl*2;
			ans+=clvl;
		}
		else ans+=clvl;
		lvl=clvl;
	}
	return ans;
}
char* ator(int a)
{
	int i=0;
	bool ivix=true,xlxc=true,cdcm=true,v=true,l=true,d=true;
	while(a)
	{
		if(a>=1000)
		{rans[i++]='M'; a-=1000;}
		else if(a>=900 && cdcm)
		{
			rans[i++]='C';	rans[i++]='M';	cdcm=false;
			a-=900;
		}
		else if(a>=500 && d)
		{
			rans[i++]='D';	d=false;
			a-=500;
		}
		else if(a>=400 && cdcm && d)
		{
			rans[i++]='C';	rans[i++]='D';	cdcm=false;	d=false;
			a-=400;
		}
		else if(a>=100)
		{
			rans[i++]='C';
			a-=100;
		}
		else if(a>=90 && xlxc)
		{
			rans[i++]='X';	rans[i++]='C';	xlxc=false;
			a-=90;
		}
		else if(a>=50 && l)
		{
			rans[i++]='L';	l=false;
			a-=50;
		}
		else if(a>=40 && xlxc && l)
		{
			rans[i++]='X';	rans[i++]='L';	xlxc=false;	l=false;
			a-=40;
		}
		else if(a>=10)
		{
			rans[i++]='X';
			a-=10;
		}
		else if(a>=9 && ivix)
		{
			rans[i++]='I';	rans[i++]='X';	ivix=false;
			a-=9;
		}
		else if(a>=5 && v)
		{
			rans[i++]='V';	v=false;
			a-=5;
		}
		else if(a>=4 && ivix && v)
		{
			rans[i++]='I';	rans[i++]='V';	ivix=false;	v=false;
			a-=4;
		}
		else if(a>=1)
		{
			rans[i++]='I';
			a--;
		}
	}
	return rans;
}
int main()
{
	char input1[50],input2[50];
	int in1=0,in2=0,s,lvl=9999,clvl;
	scanf("%s\n%s",input1,input2);
	in1=rtoa(input1);	in2=rtoa(input2);
	printf("%d\n%s\n",in1+in2,ator(in1+in2));
}
