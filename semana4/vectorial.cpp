#include<bits/stdc++.h>
#include<cmath>
using namespace std;
 
// function for finding the angle
float angle_triangle(int x1, int x2, int x3,
            int y1, int y2, int y3, int z1, int z2, int z3)
{
 
    int num = (x2-x1)*(x3-x1)+(y2-y1)*(y3-y1)+(z2-z1)*(z3-z1) ;
 
    float den = sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2))*\
                sqrt(pow((x3-x1),2)+pow((y3-y1),2)+pow((z3-z1),2)) ;
 
    float angle = acos(num / den)*(180.0/3.141592653589793238463) ;
 
    return angle ;
}
 
// Driver code
int main()
{
int x1 = 1;
int y1 = 0;
int z1 = -1;
int x2 = 3;
int y2 = -2;
int z2 = 0;
int x3 = 1;
int y3 = 3;
int z3 = 3;
float angle_A = angle_triangle(x1, x2, x3, y1, y2,
                                y3, z1, z2, z3);
float angle_B = angle_triangle(x2, x3, x1, y2, y3,
                                y1, z2, z3, z1);
float angle_C = angle_triangle(x3, x2, x1, y3,
                            y2, y1, z3, z2, z1);
cout<<"Angles are :"<<endl;
cout<<setprecision(3);
cout<<"angle A = "<<angle_A<<" degree"<<endl;
cout<<"angle B = "<<angle_B<<" degree"<<endl;
cout<<"angle C = "<<angle_C<< " degree"<<endl;
}