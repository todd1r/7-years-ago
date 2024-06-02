#include<bits/stdc++.h>
using namespace std;
void printBinary(int num)
{
    for(int i=10;i>=0;i--)
    cout<<((num>>i)&1);//cct+= ((num>>i)&1);
    cout<<endl;
}
int main()
{
    // for(int i=0;i<8;i++)
    // {
    //     printBinary(i);
    //     if(i&1)
    //     cout<<"Odd\n"<<endl;
    //     else
    //     cout<<"Even\n"<<endl;
    // }
    //  int n=5;
    // cout<<(n<<1)<<endl;
    // cout<<(n>>1)<<endl;
    // //101--> (2^2*1+2^1*0+2^0*1)*2;



    // for(char c='A';c<='E';c++)
    // {
    //     cout<<c<<endl;
    //     printBinary(int(c));
    // }
    // for(char c='a';c<='e';c++)
    // {
    //     cout<<c<<endl;
    //     printBinary(int(c));
    // }

    //the difference bet lower case and uppercase letters is that lower case mein 5th bit set hoti hai aur uppercase
    //mein unset hoti hai

    // char A='A';
    // char a=A|(1<<5);
    // cout<<a<<endl;
    // cout<<(char)(a&(~(1<<5)))<<endl;

    // //ascii value of space is
    // cout<<(1<<5)<<endl;
    // cout<<char('C'|' ')<<endl;

    //underscore ki binary is the require binary i.e. 00001000011
    //underscore ke saath kisi lower case letter ka & karne pe we get the uppercase 
    // printBinary(int('_'));
    // cout<<char('c'&'_')<<endl;



    // //so now we can convert lowwr to upper and vice versa by
    // char B='B';
    // char b=B|' ';
    // cout<<b<<endl;

    //  char d='d';
    //  char D=(d&'_');
    //  cout<<D<<endl;


//i th bit ke right tak saari ki saari msb kaise clear kar sakte hai
    //  printBinary(59);
    //  int aa=59;
    //  int i=4;
    //  int b=(aa&(~((1<<(i+1))-1)));
    //  printBinary(b);

//i th bit ke left tak saari ki saari msb kaise clear kar sakte hai
    int a=59;
    int i=3;
    int c=(a&((1<<(i+1))-1));
    printBinary(c);


    int n=16;
    if(n&(n-1))
    cout<<"not a power of 2"<<endl;
    else
    cout<<"power of 2"<<endl;
}