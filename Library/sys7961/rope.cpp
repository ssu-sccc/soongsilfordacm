#include<bits/stdc++.h>
#include<ext/rope>
using __gnu_cxx::crope;
char tmp[100];
int main(){
    crope A,B;
    //std::cin>>A;
    //scanf("%s",tmp);
    //B=tmp;
    A="aaaa";
    A=crope("BBB")+A+"CCC";// const char[] + crope is error,but crope + const char[] is not. so A="BBB"+A+"CCC" is error.
    B="BBBaaaaCCC";
    if(A.compare(B)==0){
        printf("%s %s is same\n",A.c_str(),B.c_str());
    }
    if(A==B){// you can use this.
        std::cout << A << ' ' << B << " is same"<<std::endl;
    }

}
