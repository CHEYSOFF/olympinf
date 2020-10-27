#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    if(sqrt( (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2) )>r1+r2 || sqrt( (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2) )<abs(r1-r2) ){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}
