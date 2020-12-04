#include<bits/stdc++.h>
using namespace std;
double clock(double x)
{
    return x*1000/CLOCKS_PER_SEC;
}
int main()
{
    clock_t s,t,t2;
    register int i=1;
    for(;;++i)
    {
        system("data.exe > in.txt");
        s=clock();
        system("std.exe < in.txt  > stdout.txt");
        t=clock();
        system("test.exe < in.txt > testout.txt");
        t2=clock();
        if(system("fc /W stdout.txt testout.txt > nul"))
        {
			printf("point #%d\nWA time used: std %.2lfms test %.2lfms\n",i,clock(t-s),clock(t2-t));
			break;
        }
		printf("point #%d\nAC time used: std %.2lfms test %.2lfms\n",i,clock(t-s),clock(t2-t));
        system("pause");
    }
    system("pause>nul");
    return 0;
}