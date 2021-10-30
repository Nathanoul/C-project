#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{

    ifstream in("in.txt"); 

    float h_0 = 0;
    in >> h_0;

    float vx_0 = 0;
    float vy_0 = 0;
    in >> vx_0 >> vy_0;

    vector <float> x_arr;
    vector <float> h_arr;
    float x_n = 0;
    float h_n = 0;
    x_arr.push_back(0);
    h_arr.push_back(h_0);

    while(in >> x_n >> h_n)
    {   

        x_arr.push_back(x_n);
        h_arr.push_back(h_n);
    }

    int direct = 1;
    int end = 0;
    int k = 1;     
    float A = -9.81/(2*vx_0*vx_0);
    float B = vy_0/vx_0;
    float C = h_arr[0];
    float y = A*x_arr[1]*x_arr[1]+ B*x_arr[1] + C;

    while(!end)
    {
        if( (y <= h_arr[k]) || (k == 0) )
        {   
            cout << "hit " << k << std::endl;
            cout << "y= " << y << std::endl;

            if( (y <= 0) || (k == 0) )
            {
                end = 1;
                if(direct == 1)
                {
                    cout << "End " << k-1 << std::endl;
                } 
                else 
                {
                    cout << "End " << k << std::endl;
                }
            }

            if(direct == 1)
            {
                direct = -1; 
                B = -4*A*x_arr[k] - B;
                C = -4*A*x_arr[k]*x_arr[k] - 2*B*x_arr[k] + C;
                y = A*x_arr[k-1]*x_arr[k-1] + B*x_arr[k-1] + C; 
                k--;
            }
             else 
            {
                direct = 1; 
                B = -4*A*x_arr[k] - B;
                C = -4*A*x_arr[k]*x_arr[k] - 2*B*x_arr[k] + C;
                y = A*x_arr[k+1]*x_arr[k+1] + B*x_arr[k+1] + C; 
                k++;
            }

               
        } 
        else
        {
            cout << "passed " << k << std::endl;
            if(direct == 1)
            {k++;} else {k--;}
            cout << "y= " << y << std::endl;

            y = A*x_arr[k]*x_arr[k] + B*x_arr[k] + C;
        }    
    }
    
    return 0;
}
   
