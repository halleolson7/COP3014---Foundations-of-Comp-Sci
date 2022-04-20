
/************************************************************************************************************************

Name: Halle Olson                       Z#: Z23547920
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:                      Total Points: 20
Assignment#:Assignment#2  (nursery_inv2.cpp)

Description: In this assignment we will be processing orders for a nursey. For each order 10 values will be associated and called until we reach the end of the program

*************************************************************************************************************************/


//C++ introduced
//ifstream
//call-by-value
//call-by-reference
//constant
//input parameter
//output parameter
//input/ouput parameter
//prototypes
//string library
//function definition - means the actual code for the function
//actual arguments
//formal parameters
//magic formal:
    //cout.setf(ios::showpoint); //show decimal point
    //cout.precision(2);  // use 2 decimal places to the right of the decimal point
    //cout.setf(ios::fixed);  // use decimal to represent real numbers --

//Include the following

#include <iostream>//input and output library
#include <string> //string library
#include <fstream>  //you must include this library if you wish to do file i/o
#include <iomanip> //input and output manipulators  -- change the state of the class
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/

//Prototypes for your functions: input, output, and process will go here


void input(ifstream &, string &, string &, double &, int &);
//What does the & mean? --- the formal parameter is a reference paramter (input/output, or output)
//  that means that value will change inside the function
//   & means formal parameter is an alias for memory that was allocated else where.
//  You do not need the formal parameter names, you only need the data type
//  Why do you need only the data types of the formal parameters?  The compiler uses the data types
//  to set up for a function call --- allocate memory the return type, and the formal parameters.
//  ifstream -- input file stream ---



//what does the & tell - call-by-reference - values will change - output parameters

//void input(ifstream &, string &, string &, double &, int &) - Header
//input(ifstream &, string &, string &, double &, int &) - signature

void process(const string,const double,const int, double &, double &, double &, double &, double &,double &);
//what does const?  cannot change the value inside the function; never appear on the left side
//                  of the assignment operator  =;
// Formal parameters without & are input parameter -- call-by-value
// during a call by value a copy of the actual argument is placed in the corresponding formal parameter...

void output(const string, const string, const double, const int, const double, const double &,
            const double &, const double &, const double&, const double &);

//What does const and & mean when used in a declaration?  You have the protection of a call-by-value (must make a copy)
// and the speed of a call-by-reference (no need to take copy )

//WHY DO WE USE PROTOTYPES?
// DECLARES A FUNCTION - THE ORDER IN WHICH THE FUNCTIONS ARE CALLED DO NOT MATTER
// HELP THE COMPILER SETUP FOR A FUNCTION CALL



//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: pname, cname, plant_cost and quantity have not been initialized.
//
//Postcondition:
//  pname, cname, plant_cost and quantity have been initialized.
//
//Description:  The function input reads values from the datefile into the formal parameters
//              pname, cname, plant_cost, and quantity
//
//*************************************************************************************

void input(ifstream & in,string & pname,string & cname, double & plant_cost,int & quantity) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
    in >> pname;
    in >> cname;
    in >> plant_cost;
    in>> quantity;



    //in >> pname >> cname >> plant_cost >> quantity;  //operator overloading
      // >>  = operator>>
      // +   = operator+
    
}

///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

void process(const string cname, const double plant_cost, const int quantity, double& tax_rate,
    double& net_cost, double& discount_rate, double& discount, double& purchase_tax, double& total_cost)
{
    //put the code for your calculations here...
    
    //calculate net cost
    net_cost = quantity * plant_cost;
    
    //calculate tax
    if (cname == "dade")
        tax_rate = 5.5;
    
    else if (cname == "broward")
        tax_rate = 5.0;
    
    else if (cname == "palm")
        tax_rate = 6.0;
    
    //calculate discount rate
    if (quantity == 0)
        discount = 0;
    
    else if (quantity >= 1 && quantity <= 6)
    {
        discount = .02 * net_cost;
        discount_rate = 2;
    }
    else if (quantity >= 7 && quantity <= 13)
    {
        discount = .04 * net_cost;
        discount_rate = 4;
    }
    else if (quantity >= 14 && quantity <= 25)
    {
        discount = .07 * net_cost;
        discount_rate = 7;
    }
    else if (quantity >= 26 && quantity <= 60)
    {
        discount = .09 * net_cost;
        discount_rate = 9;
    }
    else if (quantity > 60)
    {
        discount = .14 * net_cost;
        discount_rate = 14;
    }
    
    
    
    //calculate the tax on purchase and total cost of purchase
        purchase_tax = net_cost * (tax_rate / 100);
        total_cost = net_cost + purchase_tax - discount;
    
}


///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

void output(const string pname, const string cname, const double plant_cost, const int quantity, double& tax_rate,
    double& net_cost, double& discount_rate, double& discount, double& purchase_tax, double& total_cost)
{
    //Use thee following statement to help you format you our output. These statements are called the magic formula.
    /*out.setf(ios::showpoint);
    out.precision(2);
    out.setf(ios::fixed);*/
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    
    cout << left << setw(15) << pname <<
            left << setw(8) << cname <<
            right << setw(8) << plant_cost <<
            right << setw(8) << quantity <<
            right << setw(8) << tax_rate <<
            right << setw(8) << net_cost <<
            right << setw(8) << discount_rate <<
            right << setw(8) << discount <<
            right << setw(8) << purchase_tax <<
            right << setw(8) << total_cost << endl;
    //complete the statement
                
}

//Here is your driver to test the program
int main()
{

    string pname = "";
    string cname = "";
    double plant_cost = 0;
    int quantity = 0;
    double tax_rate = 0;
    double net_cost = 0;
    double discount_rate = 0;
    double discount = 0;
    double purchase_tax = 0;
    double total_cost = 0;

    ifstream in;    //declaring an input file stream
    in.open("nursery_stock.txt"); //opening the input file stream //for visual studio
    //in.open("/Users/halleolson/Documents/COP3014/Program 2/nursery_stock.txt"); //opening the input file stream //mac
    
    if (in.fail())
    {
        cout << "Input file did not open correctly" << endl;
    }
    else
    {   //the following while loop processes one order record at a time
        while (!in.eof())
        {
            input(in, pname,cname, plant_cost, quantity);
            //process(cname,plant_cost,quantity,tax_rate);
            process(cname, plant_cost, quantity, tax_rate, net_cost, discount_rate, discount, purchase_tax, total_cost);
            //output(pname,cname, ... add other actual arguments);
            output(pname, cname, plant_cost, quantity, tax_rate, net_cost, discount_rate, discount, purchase_tax, total_cost);
        }
    }

    in.close(); //always close opened files.
    return 0;
}


