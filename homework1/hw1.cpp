#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream in("in.txt"); 

    float x_n = 0;
    float y_n = 0;
    in >> x_n >> y_n;

    float x_0 = 0;
    float y_0 = 0;
    in >> x_0 >> y_0;

    float x_frst_l = x_0;
    float y_frst_l = y_0;
    float x_frst_r = x_0;
    float y_frst_r = y_0;

    float dist_l = 0;
    float dist_r = 0;

    while(in)
    {
        in >> x_n >> y_n;

        if ( x_0 != 0 && y_0 != 0)
        {
            if ( (dist_l < x_n*x_n*y_0*y_0 + x_0*x_0*y_n*y_n - 2*x_n*x_0*y_n*y_0) && (x_n*y_0 - y_n*x_0 >= 0) )
            {
                dist_l = x_n*x_n*y_0*y_0 + x_0*x_0*y_n*y_n - 2*x_n*x_0*y_n*y_0;
                x_frst_l = x_n;
                y_frst_l = y_n;
            }

            if ( (dist_r < x_n*x_n*y_0*y_0 + x_0*x_0*y_n*y_n - 2*x_n*x_0*y_n*y_0) && (x_n*y_0 - y_n*x_0 < 0) )
            {
                dist_r = x_n*x_n*y_0*y_0 + x_0*x_0*y_n*y_n - 2*x_n*x_0*y_n*y_0;
                x_frst_r = x_n;
                y_frst_r = y_n;
            }
        } 
    }
     
    cout << "rightmost: " << x_frst_r << " " << y_frst_r << std::endl;
    cout << "leftmost: " << x_frst_l << " " << y_frst_l << std::endl;
    return 0;
}
   
