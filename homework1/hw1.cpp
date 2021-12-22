#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream in("in.txt"); 
    const double eps = 1e-15;

    double x_0 = 0;
    double y_0 = 0;
    in >> x_0 >> y_0;

    double x_n = 0;
    double y_n = 0;

    double x_obtuse_l = 0;
    double y_obtuse_l = 0;
    double x_obtuse_r = 0;
    double y_obtuse_r = 0;

    double cos_l = 1;
    double cos_r = 1;
    double cos = 1;

    while(in)
    {
        in >> x_n >> y_n;

        if ( x_n*x_n + y_n*y_n != 0)
        {
            cout << x_n << " " << y_n << std::endl; 
            cos = (x_0*x_n + y_n*y_0)/sqrt((x_0*x_0 + y_0*y_0)*(x_n*x_n + y_n*y_n));
            if ( ( ((abs(cos_l - cos) > eps) && (cos_l > cos)) || (abs(x_obtuse_l*y_n - x_n*y_obtuse_l) < eps) ) && (x_n*y_0 - y_n*x_0 < 0) )
            {
                cos_l = (x_0*x_n + y_n*y_0)/sqrt((x_0*x_0 + y_0*y_0)*(x_n*x_n + y_n*y_n));
                x_obtuse_l = x_n;
                y_obtuse_l = y_n;
            }

            if ( ( ((abs(cos_r - cos) > eps) && (cos_r > cos)) || (abs(x_obtuse_r*y_n - x_n*y_obtuse_r) < eps) ) && (x_n*y_0 - y_n*x_0 >= 0) ) 
            {
                cos_r = (x_0*x_n + y_n*y_0)/sqrt((x_0*x_0 + y_0*y_0)*(x_n*x_n + y_n*y_n));
                x_obtuse_r = x_n;
                y_obtuse_r = y_n;
            }
        } 
    }
        
    cout << "Leftmost: " << x_obtuse_l << " " << y_obtuse_l << std::endl; 
    cout << "Rightmost: " << x_obtuse_r << " " << y_obtuse_r << std::endl;
    return 0;
}
   
