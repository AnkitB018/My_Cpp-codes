#include<iostream>
#include<math.h>
using namespace std;

class points{
    int x,y;
    friend int cal_distance(points , points);
    public:
        points(int a , int b){
            x = a;
            y = b;
        }
};

int cal_distance(points p1 , points p2){
    double ans;
    ans =(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
    return sqrt(ans);
}

int main(){
    points p1(43,17) , p2(164 ,120);
    double dis = cal_distance(p1 , p2);
    cout<<"Distance between the points is: "<<dis;
    return 0;
}