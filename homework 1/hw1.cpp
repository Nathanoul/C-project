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

    float x_frst = x_0;
    float y_frst = y_0;
    float x_obtuse = x_0;
    float y_obtuse = y_0;

    float angle = 1;
    float dist = 0;

    while(in)
    {
        in >> x_n >> y_n;

        if ( x_0 != 0 && y_0 != 0)
        {
            if ( angle > (x_n*x_0 + y_n*y_0)/sqrt( (x_n*x_n + y_n*y_n)*(x_0*x_0 + y_0*y_0) ) )
            {
                angle = (x_n*x_0 + y_n*y_0)/sqrt( (x_n*x_n + y_n*y_n)*(x_0*x_0 + y_0*y_0) );
                x_obtuse = x_n;
                y_obtuse = y_n;
            }

            if ( dist < x_n*x_n*y_0*y_0 + x_0*x_0*y_n*y_n - 2*x_n*x_0*y_n*y_0 )
            {
                dist = x_n*x_n*y_0*y_0 + x_0*x_0*y_n*y_n - 2*x_n*x_0*y_n*y_0;
                x_frst = x_n;
                y_frst = y_n;
            }
        } 
    }
     
    cout << "furtherest point: " << x_frst << " " << y_frst << std::endl;
    cout << "most obtuse angle: " << x_obtuse << " " << y_obtuse << std::endl;
    return 0;
}
   