#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int btoi(string bin)
{
	int a=0,s=bin.length();
	for(int i=s-1;i>=0;i--)
	{
		a|=(bin[i]=='1'?1:0)<<s-i-1;
	}
	return a;
}
string itob(int i)
{
	string backforward;
	for(int j=0;j<8;j++)
		if(i&(1<<j)) backforward.push_back('1');
		else backforward.push_back('0');
	string ff;
	for(int j=backforward.length();j>0;j--)
		ff.push_back(backforward[j-1]);
	return ff;
}
int main()
{
	int aa;
	int pc,increaser;
	bool halt;
	string memory[32];
	while(1)
	{
		pc=0,increaser=0;
		halt=false;
		for(int i=0;i<32;i++)
		{
			cin>>memory[i];
			if(cin.eof()) return 0;
		}
	
		while(!halt)
		{
			switch(btoi(memory[pc++].substr(0,3)))
			{
				case 0:	//sta x
					memory[btoi(memory[pc-1].substr(3,5))]=itob(increaser);
					break;
				case 1:	//lda x
					increaser=btoi(memory[btoi(memory[pc-1].substr(3,5))]);
					break;
				case 2:	//beq x
					if(increaser==0)
						pc=btoi(memory[pc-1].substr(3,5));
					break;
				case 3:	//nop : do nothing
					break;
				case 4:	//dec
					increaser--;
					if(increaser<0) increaser=255;
					break;
				case 5:	//inc
					increaser=(increaser+1)%256;
					break;
					case 6:	//jmp
					pc=btoi(memory[pc-1].substr(3,5));
					break;
				case 7:	//hlt exits program
					for(int i=7;i>=0;i--)
						printf("%d",increaser&(1<<i)?1:0);
					printf("\n");
					halt=true;
			}
			if(pc>=32) pc%=32;
			//cin>>aa;
		}
	}
}
