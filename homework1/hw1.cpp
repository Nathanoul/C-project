#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream in("in.txt"); 

    double x_0 = 0;
    double y_0 = 0;
    in >> x_0 >> y_0;

    double x_n = 0;
    double y_n = 0;

    double x_obtuse_l = x_0;
    double y_obtuse_l = y_0;
    double x_obtuse_r = x_0;
    double y_obtuse_r = y_0;

    double cos_l = 1;
    double cos_r = 1;

    while(in)
    {
        in >> x_n >> y_n;

        if ( x_n != 0 && y_n != 0)
        {
            if ( (cos_l > (x_0*x_n + y_n*y_0)/sqrt((x_0*x_0 + y_0*y_0)*(x_n*x_n + y_n*y_n))) && (x_n*y_0 - y_n*x_0 <= 0) || ( x_n*y_n == x_obtuse_l*y_obtuse_l ) ) 
            {
                cos_l = (x_0*x_n + y_n*y_0)/sqrt((x_0*x_0 + y_0*y_0)*(x_n*x_n + y_n*y_n));
                x_obtuse_l = x_n;
                y_obtuse_l = y_n;
            }

            if ( (cos_r > (x_0*x_n + y_n*y_0)/sqrt((x_0*x_0 + y_0*y_0)*(x_n*x_n + y_n*y_n))) && (x_n*y_0 - y_n*x_0 > 0) || ( x_n*y_n == x_obtuse_r*y_obtuse_r ) )
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
   
