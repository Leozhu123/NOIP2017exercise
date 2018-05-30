#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <ctime>
const int times = 40000000;
using namespace std;
int n, l;
double r, rf;
double posx[20],posy[20];
int main()
{
    srand(time(0));
    cin >> n;
    cin >> l;
    r = l / n;
    rf = r * r;
    for (int i = 0; i < n; i++)
    {
        cin >> posx[i] >> posy[i];
    }
    if (n==1){
    	double ansx[4]={0,0,l,l},ansy[4]={0,l,0,l}; 
        for (int j=0;j<4;j++){
			bool ok = true;
        	double x=ansx[j],y=ansy[j];
        	for (int i = 0; i < n && ok; i++)
        	{
            	double df = (x - posx[i]) * (x - posx[i]) + (y - posy[i]) * (y - posy[i]);
            	if (df <= rf )
            	{
                	ok = false;
                	break;
            	}
        	}
        	if (ok)
        	{
            	printf("%.3lf %.3lf\n", x, y);
            	return 0;
        	}
    	}
    	cout << "GG" << endl;
    	return 0;
    }
    for (int i = 0; i < times; i++)
    {
        bool ok = true;
        int dx = rand() % l, dy = rand() % l;
        double rx = (rand() & 1000) / 1000.0, ry = (rand() & 1000) / 1000.0;
        double x = dx + rx, y = dy + ry;
        if (x < 0 || x > l || y < 0 || y > l)
            ok = false;
        for (int i = 0; i < n && ok; i++)
        {
            double df = (x - posx[i]) * (x - posx[i]) + (y - posy[i]) * (y - posy[i]);
            if (df < rf-0.0001)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            printf("%.3lf %.3lf\n", x, y);
            return 0;
        }
    }
    cout << "GG" << endl;
    int a;
    cin>>a;

}
