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
	//for(int j=0;(1<<j)<=i;j++)
	for(int j=0;j<8;j++)
		if(i&(1<<j)) backforward.push_back('1');
		else backforward.push_back('0');
	string ff;
	for(int j=backforward.length();j>0;j--)
		ff.push_back(backforward[j-1]);
//	cout<<i<<" -> "<<ff<<" = "<<btoi(ff)<<endl;
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
			printf("pc : %d\tinc : %d\n",pc,increaser);
			switch(btoi(memory[pc++].substr(0,3)))
			{
				case 0:	//sta x
					printf(">sta(%d) ",btoi(memory[pc-1].substr(3,5)));
					memory[btoi(memory[pc-1].substr(3,5))]=itob(increaser);
					printf("%d %d\n",increaser,btoi(memory[btoi(memory[pc-1].substr(3,5))]));
					break;
				case 1:	//lda x
					printf(">lda(%d) %d ",btoi(memory[pc-1].substr(3,5)),increaser);
					increaser=btoi(memory[btoi(memory[pc-1].substr(3,5))]);
					printf("-> %d\n",increaser);
					break;
				case 2:	//beq x
					printf(">beq %d",pc);
					if(increaser==0)
						pc=btoi(memory[pc-1].substr(3,5));
					printf("-> %d\n",pc);
					break;
				case 3:	//nop : do nothing
					printf(">nop\n");
					break;
				case 4:	//dec
					printf(">dec %d",increaser);
					increaser--;
					if(increaser<0) increaser=255;
					printf(" -> %d\n",increaser);
					break;
				case 5:	//inc
					printf(">inc %d ->",increaser);
					increaser=(increaser+1)%256;
					printf(" %d\n",increaser);	
					break;
					case 6:	//jmp
					printf(">jmp");
					pc=btoi(memory[pc-1].substr(3,5));
					printf(" %d\n",pc);
					break;
				case 7:	//hlt exits program
					printf(">hlt\n");
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
