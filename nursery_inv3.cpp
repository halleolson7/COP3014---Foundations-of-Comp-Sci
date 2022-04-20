
/************************************************************************************************************************

Name:  Halle Olson                         Z#: Z23547920
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:   June 15th              Total Points: 20
Assignment#:Assignment#3  (nursery_inv3.cpp)

Description: The purpose of the program is to get user input and open a file to calculate costs, discounts, and tax rates, and print them to the screen along with another file

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
#include <iomanip>
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record
{
public:
    string pname;
    string cname;
    double plant_cost;
    int quantity;
    double tax_rate;
    double net_cost;
    double discount_rate;
    double discount;
    double purchase_tax;
    double total_cost;
};


//Prototypes for your functions: input, output, and process will go here

void input(ifstream&, order_record&);
void output(ofstream &, const order_record&);
void process(order_record&);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:
// Example:Get input (values of plant name, county name, plant cost, quantity )
//from data file order record (p_record).

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream& in, order_record& plant_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
    in >> plant_record.pname;
    in >> plant_record.cname;
    in >> plant_record.plant_cost;
    in >> plant_record.quantity;
    //the rest of your code goes here....
}


///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record & plant_record)
{
    //put your code here for your calculations
    //calculate net cost
    plant_record.net_cost = (plant_record.quantity * plant_record.plant_cost);
    
    //calculate tax
    if (plant_record.cname == "dade")
        plant_record.tax_rate = 5.5;
    
    else if (plant_record.cname == "broward")
        plant_record.tax_rate = 5.0;
    
    else if (plant_record.cname == "palm")
        plant_record.tax_rate = 6.0;
    
    
    //calculate discount rate
    if (plant_record.quantity == 0)
        plant_record.discount = 0;
    
    else if (plant_record.quantity >= 1 && plant_record.quantity <= 6)
    {
        plant_record.discount = .02 * plant_record.net_cost;
        plant_record.discount_rate = 2;
    }
    else if (plant_record.quantity >= 7 && plant_record.quantity <= 13)
    {
        plant_record.discount = .04 * plant_record.net_cost;
        plant_record.discount_rate = 4;
    }
    else if (plant_record.quantity >= 14 && plant_record.quantity <= 25)
    {
        plant_record.discount = .07 * plant_record.net_cost;
        plant_record.discount_rate = 7;
    }
    else if (plant_record.quantity >= 26 && plant_record.quantity <= 60)
    {
        plant_record.discount = .09 * plant_record.net_cost;
        plant_record.discount_rate = 9;
    }
    else if (plant_record.quantity > 60)
    {
        plant_record.discount = .14 * plant_record.net_cost;
        plant_record.discount_rate = 14;
    }
    
    
    //calculate the tax on purchase and total cost of purchase
    plant_record.purchase_tax = plant_record.net_cost * (plant_record.tax_rate / 100);
    plant_record.total_cost = plant_record.net_cost + plant_record.purchase_tax - plant_record.discount;
    
}


///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

void output(ofstream& out, const order_record& plant_record)
{


    //Use thee following statement to help you format you our output. These statements are called the magic formula.
    /*out.setf(ios::showpoint);
    out.precision(2);
    out.setf(ios::fixed);*/
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);

    //put your code here to print the formatted output. Check out the following code sample.
    cout << left << setw(15) << plant_record.pname <<
            left << setw(8) << plant_record.cname <<
            right << setw(8) << plant_record.plant_cost <<
            right << setw(8) << plant_record.quantity <<
            right << setw(8) << plant_record.tax_rate <<
            right << setw(8) << plant_record.net_cost <<
            right << setw(8) << plant_record.discount_rate <<
            right << setw(8) << plant_record.discount <<
            right << setw(8) << plant_record.purchase_tax <<
            right << setw(8) << plant_record.total_cost << endl;
}
//Here is your driver to test the program
int main()
{

    order_record purchase_record;

    ifstream in;    //declaring an input file stream
    in.open("nursery_stock.txt"); //opening the input file stream
    //in.open("/Users/halleolson/Documents/COP3014/Program 3/nursery_stock.txt");
    ofstream out;
    out.open("sample_calculations.txt");
    //out.open("/Users/halleolson/Documents/COP3014/Program 3/sample_calculations.txt");

    if (in.fail())
    {
        cout << "Input file did not open correctly" << endl;
    }
    else
    {   //the following while loop processes one order record at a time
        while (!in.eof())
        {
            input(in, purchase_record);
            process(purchase_record);
            output(out,purchase_record);
        }
    }

    in.close(); //always close opened files.
    out.close();
    return 0;
}


