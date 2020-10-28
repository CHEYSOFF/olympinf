#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double PI=acos(-1.0);

double eps=1e-9;

struct point{
    double x,y;
    point(double _x, double _y){
        x=_x;
        y=_y;
    }
    point(){
        x=0;
        y=0;
    }
};

point operator+(point p1, point p2){
    return point(p1.x+p2.x,p1.y+p2.y);
}

point operator-(point p1, point p2){
    return point(p1.x-p2.x,p1.y-p2.y);
}

point operator*(point p1, double k){
    return point(p1.x*k,p1.y*k);
}

double dot(point p1, point p2){
    return p1.x*p2.x+p1.y*p2.y;
}

double cross(point p1, point p2){
    return p1.x*p2.y-p1.y*p2.x;
}

double len(point p){
    return sqrt(p.x*p.x+p.y*p.y);
}

point rotatev(point p, double a){
    //cos -sin
    //sin cos
    return point(p.x*cos(a)-p.y*sin(a), p.x*sin(a)+p.y*cos(a));
}

double angle(point v1, point v2){
    return acos(dot(v1,v2)/len(v1)/len(v2));
}

struct line
{
    double a,b,c;
    point p1,p2;
    //ax+by=c
    line(point _p1, point _p2){
        p1=_p1;
        p2=_p2;
        point v1=p2-p1;
        point v2(-v1.y,v1.x);
        a=v2.x;
        b=v2.y;
        c=p1.x*a+b*p1.y;
    }
    line(){
        p1=point(0,0);
        p2=point(0,0);
        a=0;
        b=0;
        c=0;
    }
};

point cross(line l1, line l2){
    //a1 b1
    //a2 b2
    double det=l1.a*l2.b-l2.a*l1.b;
    point ans;
    ans.x=(l1.c*l2.b-l2.c*l1.b)/det;
    ans.y=(l1.a*l2.c-l2.a*l1.c)/det;
    return ans;
}

line perp(line l, point p){
    return line(p,p+point(l.a,l.b));
}

point norm(point v){
    return point(v.x/len(v),v.y/len(v));
}

int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }
    cout<<n*(n-1)+2;
}
