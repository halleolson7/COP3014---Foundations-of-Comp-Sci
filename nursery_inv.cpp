/***********************************************************
Halle Olson           Total Points:  10
Due Date: June 2
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard

Description:  In this program we calculate the cost, tax, and discount of a purchase. It accepts input from the user such as name, cost, and qualtiy and print details neatly to the screen


*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <iomanip>

using namespace std;

int main()
{

    //decimal point format
    //**********MAGIC FORMULA  WILL EXPLAIN**************************
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //***************************************************************

    string user_response = "y";

    //declare and comment your user variable here
    string pname;   //string that holds the plant name
    string cname;   //string that holds the county name
    double plant_cost; //double that hold the cost of a plant;
    int quantity; //int that hold the number of plants purchased;
    double purchase_tax = 0; //double that initializes the purchase tax to zero
    double net_cost = 0; //double that initializes the net cost to zero
    double discount = 0; //double that initializes the percent discount to zero
    double total_cost = 0; //double that initializes the total cost to zero

    while (user_response == "y" || user_response == "Y")
    {
      //The code to get the user's input if given in the following
        //Input Statements
        cout << "Enter the Plant Name: ";
        cin >> pname;
        cout << "Enter the County Name: ";
        cin >> cname;
        cout << "Enter the Plant Cost: ";
        cin >> plant_cost;
        cout << "Enter the Quantity: ";
        cin >> quantity;

      //Perform the calculations here
        //Calculations
        net_cost = quantity * plant_cost;

        //Logic ...if else statements
        //quantity and discount percent
        if (quantity <= 0)
            discount = 0;
        
        else if (quantity >= 1 && quantity <= 5)
            discount = .01 * net_cost;
        
        else if (quantity >= 6 && quantity <= 11)
            discount = .03 * net_cost;
        
        else if (quantity >= 12 && quantity <= 20)
            discount = .05 * net_cost;
        
        else if (quantity >= 21 && quantity <= 50)
            discount = .08 * net_cost;
        
        else if (quantity > 50)
            discount = .12 * net_cost;
        
        
        //determine purchase tax
        if (cname == "dade")
            purchase_tax = net_cost * .065;
        
        else if (cname == "broward")
            purchase_tax = net_cost * .06;
        
        else if (cname == "palm")
            purchase_tax = net_cost * .07;
        
        //calculate total cost
        total_cost = net_cost + purchase_tax - discount;

        //Print Results to screen here
        //Output Statement
        cout << endl << endl;
        cout << "Plant Name = " << pname << endl;
        cout << "County Name = " << cname << endl;
        cout << "Plant Cost = " << plant_cost << endl;
        cout << "Quantity of Plants = " << quantity << endl;
        cout << "Net Cost of Purchase = " << net_cost << endl;
        cout << "Purchase Tax = " << purchase_tax << endl;
        cout << "Discount on Purchase = " << discount << endl;
        cout << "Total Cost of Purchase = " << total_cost << endl;

        //ask if user wants to do another calculation
        cout << "Would you like to do another calculation (Y or N): " << endl;
        cin >> user_response;
    }

    return  0;
}
