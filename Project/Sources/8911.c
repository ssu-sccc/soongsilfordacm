#include <stdio.h>
#include <string.h>
int main()
{
	int t;
	char commands[555];
	for(scanf("%d",&t);t--;)
	{
		int s,x=0,y=0,mx=0,my=0,nx=0,ny=0,dir=0;	//위0,왼쪽1,아래2,오른쪽3
		scanf("%s",commands);
		s=strlen(commands);
		for(int i=0;i<s;i++)
		{
			switch(commands[i])
			{
				case 'F':
					switch(dir)
					{
						case 0: y++;	break;
						case 1: x++;	break;
						case 2: y--;	break;
						case 3: x--;	break;
					}
					break;
				case 'B':
					switch(dir)
					{
						case 0: y--;	break;
						case 1: x--;	break;
						case 2: y++;	break;
						case 3: x++;	break;
					}
					break;
				case 'L':
					dir=(dir+1)%4;
					break;
				case 'R':
					dir=(dir+3)%4;
					break;
			}
			if(x>mx) mx=x;	if(y>my) my=y;
			if(x<nx) nx=x;	if(y<ny) ny=y;
		}
		printf("%d\n",(mx-nx)*(my-ny));
	}
}
