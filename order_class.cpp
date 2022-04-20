
/************************************************************************************************************************
 order_class.cpp
 
Name:  Halle Olson        Z#: Z23547920
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  08/03/2021           Due Time: 11:59 PM
Total Points: 20
Assignment #: nursery_porder11.cpp

Description: This assignment is an extension of Program 10, which implements a class called order_class. We decalre the class in "order_class.h" and implement the class in "order_class.cpp". We use processor directives #ifndef, #define, and #endif

*************************************************************************************************************************/
#include <iomanip>

//#include "/Users/halleolson/Documents/COP3014/Program 11/Program 11/order_class.h"
#include "order_class.h"



/************************************************************************************************************************************/
//Name: default constructor
//Precondition: count is not yet initialized, size is not yet initialized, ifstream has not been declared or opened, data from file has not been read
//Postcondition: count is initialized to 0, size is initialized to 1, ifstream has been declared and file has been opened, data from the file has been read. If full, double_size was called
//Decription: Reads the data file of purchase order information (plant name, county name, plant cost and quantity) into the dynamic array of order records,
//STR. If the count become equal to the size the function double_size is called and the memory allocated to STR is doubled.

/************************************************************************************************************************************/

order_class::order_class()
{
    size = 1;
    count = 0;
    STR = new order_record[size];

    cout << "The default constructor has been called\n";
    
ifstream in;
    in.open("nursery_stock.txt");
    //in.open("/Users/halleolson/Documents/COP3014/Program 11/nursery_stock.txt"); // open the input file

// check if file can be opened
    if (in.fail())
    {
        cout << "input file did not open correctly" << endl;
    }
    else
    {
        while(!in.eof())
        {
            if (count < size)
            {
                in >> STR[count].pname >> STR[count].cname >> STR[count].plant_cost >> STR[count].quantity;
                count++;
            }
            else if (is_full())
            {
                double_size();
                in >> STR[count].pname >> STR[count].cname >> STR[count].plant_cost >> STR[count].quantity;
                count++;
            }
                
        }
        
    }
    in.close();
}
/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: deep copy of object not yet performed
//Postcondition: deep copy of object performed
//Description:  The function performs a deep copy of the formal parameter org.
//
/************************************************************************************************************************************/
order_class::order_class(const order_class& org)
{
    count = org.count;
    size = org.size;

    STR = new order_record[size];

        for (int i = 0; i < count; i++)
        {
            STR[i].cname = org.STR[i].cname;
            STR[i].pname = org.STR[i].pname;
            STR[i].plant_cost = org.STR[i].plant_cost;
            STR[i].quantity = org.STR[i].quantity;
        }

    process();
}

/***********************************************************************************************************************************/

//Name: is_Empty
//Precondition: will return true or false
//Postcondition: returned true or false
//Decription: returns true if STR is empty

/**********************************************************************************************************************************/

bool order_class::is_Empty()
{
    return count == 0;
}

/**********************************************************************************************************************************/

//Name: is_full
//Precondition: count will return true or false
//Postcondition: returned true or false
//Decription: returns true if STR is full

/*********************************************************************************************************************************/

bool order_class::is_full()
{
    return count == size;
}

/**********************************************************************************************************************************/

//Name: search
//Precondition: not yet searched and found key or returned -1
//Postcondition: searched and found key or returned -1
//Decription: locates key i.e plant name in STR if it is there; otherwise -1 is returned

/*********************************************************************************************************************************/

int order_class::search(const string key)
{
    
    for (int i = 0; i < count; i++)
    {
        if (STR[i].pname == key)
            return i;
    }
    return -1;
}

/*********************************************************************************************************************************/

//Name: add
//Precondition: user has not been prompted for pname, cname, plant_cost, and quantity to insert into STR
//Postcondition: user has been prompted for pname, cname, plant_cost, and quantity, which have been inserted into STR
//Decription: adds a order_record to STR; if STR is full, double_size is called to increase the size of STR. The user
// is prompted to enter the plant name, county name, plant cost and quantity.

/********************************************************************************************************************************/

void order_class::add( )
{
   
    //prompt user for info
    if (count < size)
    {
        cout << "Plant name: ";     //plant name
        cin >> STR[count].pname;
        cout << "County name: ";    //county name
        cin >> STR[count].cname;
        cout << "Plant cost: ";     //plant cost
        cin >> STR[count].plant_cost;
        cout << "Quantity: ";       //quantity
        cin >> STR[count].quantity;
        count++;
    }
    
    else if (is_full())
    {
        double_size();
        cout << "Plant name: ";     //plant name
        cin >> STR[count].pname;
        cout << "County name: ";    //county name
        cin >> STR[count].cname;
        cout << "Plant cost: ";     //plant cost
        cin >> STR[count].plant_cost;
        cout << "Quantity: ";       //quantity
        cin >> STR[count].quantity;
        count++;
    }
    process();
}

/********************************************************************************************************************************/

//Name: operator-
//Precondition: will delete any pname that match key stored in STR
//Postcondition: deleted any pname that matched key from STR
//Decription: removes all order records in STR with a plant name field that matches key, if it is there.
/*******************************************************************************************************************************/

order_class& order_class::operator-(const string key)
{
    int i = search(key);
    
    if (i == -1)
        cout<<"No record with key : "<< key <<" exists" << endl;
    
    else
    {
        //loop to remove all plant records w/ key
        while (i != -1)
        {
            for (int j = i; j < count - 1; j++)
                STR[j] = STR[j+1];
            
            count--;
            i = search(key);
        }
    }

    return *this;
}

/******************************************************************************************************************************/

//Name: double_size
//Precondition: size capacity not doubled
//Postcondition: size capacity doubled
//Decription: doubles the size (capacity) of STR

/******************************************************************************************************************************/

void order_class::double_size( )
{
    size *=2;
    order_record *temp = new order_record[size];
    
    for (int i = 0; i < count; i++)
    {
        temp[i] = STR[i];
    }

    delete [] STR;
    STR = temp;
}

/******************************************************************************************************************************/

//Name: process
//Precondition: pname, cname, plant_cost, and quantity have been initialized. net_cost, tax_rate, discount, purchase_tax, and total_cost have not yet been calculated
//Postcondition: pname, cname, plant_cost, and quantity have been initialized. net_cost, tax_rate, discount, purchase_tax, and total_cost have been calculated and stored
//Decription: calculate the net cost, tax rate, order tax, discount and total cost for every order record in STR. for every call record in STR.

/*****************************************************************************************************************************/

void order_class::process()
{
        
    for (int i = 0; i < count; i++)
    {
        //calculate net cost
        STR[i].net_cost = STR[i].quantity * STR[i].plant_cost;
        
        //calculate quantity and discount statements
        if (STR[i].quantity <= 0)
            STR[i].discount = 0;
        
        else if (STR[i].quantity >= 1 && STR[i].quantity <= 5)
            STR[i].discount = .01 * STR[i].net_cost;
            
        else if (STR[i].quantity >= 6 && STR[i].quantity <= 11)
            STR[i].discount = .03 * STR[i].net_cost;
            
        else if (STR[i].quantity >= 12 && STR[i].quantity <= 20)
            STR[i].discount = .05 * STR[i].net_cost;
         
        else if (STR[i].quantity >= 21 && STR[i].quantity <= 50)
            STR[i].discount = .08 * STR[i].net_cost;

        else
            STR[i].discount = .13 * STR[i].net_cost;
        
        //calculate tax rate
        if (STR[i].cname == "dade")
            STR[i].tax_rate = 0.065;
        
        else if (STR[i].cname == "broward")
            STR[i].tax_rate = 0.06;
        
        else if (STR[i].cname == "palm")
            STR[i].tax_rate = 0.07;
        
        //calculate purchase tax
        STR[i].purchase_tax = STR[i].net_cost * STR[i].tax_rate;
        
        //calculate total cost
        STR[i].total_cost = STR[i].net_cost + STR[i].purchase_tax - STR[i].discount;
        
    }
}

/****************************************************************************************************************************/

//Name: operator<<
//Precondition: value of run not yet printed
//Postcondition: value of run printed and incremeted throughout file
//Decription: prints every field of every call_record in STR formatted to a file and return the stream.
/***************************************************************************************************************************/

ostream& operator<<(ostream& out, order_class & org)
{

    static int run = 1;

    for (int i = 0; i < org.count; i++)
    {
        out << setw(20) << left << org.STR[i].pname;
        out << setw(10) << org.STR[i].cname;
        out.setf(ios :: fixed);
        out << setw(6) << right << setprecision(2) << org.STR[i].plant_cost << "\t";
        out << setw(4) << org.STR[i].quantity << "\t";
        out << setw(7) << setprecision(2) << org.STR[i].net_cost << "\t";
        out << setw(4) << setprecision(3) << org.STR[i].tax_rate << "\t";
        out << setw(7) << setprecision(2) << org.STR[i].purchase_tax << "\t";
        out << setw(6) << setprecision(2) << org.STR[i].discount << "\t";
        out << setw(9) << setprecision(2) << org.STR[i].total_cost << endl;
    }
    out << "****************************\n";
    out << "*********end of run " << run << "****" << endl;
    out << "*******************************\n";
        
    run++;
    return out;
}

//Name: destructor
//Precondition: memory not yet de-allocated from STR
//Postcondition: memory de-allocated from STR
//Decription: de-allocates all memory allocated to STR. This will be the last function to be called (automatically by the compiler)
//before the program is exited.

/***************************************************************************************************************************/

order_class::~order_class()
{
    cout << "The destructor has been called\n";
    delete [] STR;
    size = 0;
    count = 0;
}
