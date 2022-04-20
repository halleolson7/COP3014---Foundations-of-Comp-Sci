
/************************************************************************************************************************

Name:  Halle Olson                         Z#: Z23547920
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   June 22nd              Total Points: 20
Assignment#:Assignment#4  (all_area_semi.cpp)

Description: The purpose of the program is to promt the user to enter the lengths for the sides of triangles and user our
 compute function to calculate the semiperimeter and area of the triangle or detect when the sides entered by the user are invalid

*************************************************************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//include function prototypes
void Compute(int a, int b, int c, double &semi, double &area);


int main( ) {
        //magic formula
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout.setf(ios::fixed);

        //declare variables a, b, c,area, and semiperimeter
        int a, b, c;
        double semi, area;
    
        //declare variable for while loop
        char choice = 'y';

        //while loop
        while(choice == 'y') {
                //begin while loop
                cout << "Please enter side a: ";
                cin >> a;
                cout << "Please enter side b: ";
                cin >> b;
                cout << "Please enter side c: ";
                cin >> c;

                Compute(a, b, c, semi, area);

                //call Computer
                if(semi == -1)
                {
                        cout << "Semiparamter: Invalid " << endl;
                }
            
                else
                {
                        cout << "Semiparamter: " << semi << endl;
                }
                
                if(area == -1)
                {
                        cout << "Area: Invalid " << endl;
                }
            
                else
                {
                        cout << "Area: " << area << endl;
                }
            
                //add extra line space for neatness
                cout << endl;
                
                //ask and prompt user if they want to continue
                cout << "Do you want to continue? (y/n): ";
                cin >> choice;
        }

        return 0;

}

// this function sets area and semi as -1, if values passed are invalid.
void Compute(int a, int b, int c, double &semi, double &area) {

        if ((a + b <= c) || (a + c <= b) || (b + c <= a))
        {
                semi = -1;
                area = -1;
                return;
        }

        double s = (a + b + c) / 2.0;
        semi = s;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
}
