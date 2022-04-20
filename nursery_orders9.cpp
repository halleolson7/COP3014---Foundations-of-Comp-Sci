/************************************************************************************************************************

Name:  Halle Olson       Z#: Z23547920
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  07/27/2021           Due Time: 11:59 PM
Total Points: 20
Assignment #: nursey_porders9.cpp

Description: This program is an extension of Program 8 where we implement constructors (to initialize the state of the class) and destructors (to de-allocate memory) to define a class and manage a dynamic array.
*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class order_record
{
public:
    string pname;
    string cname;
    double plant_cost;
    int quantity;
    double net_cost;
    double tax_rate;
    double purchase_tax;
    double discount;
    double total_cost;
};



class order_class
{
public:
    order_class(); //default constructor
    ~order_class(); //de-allocates all memory allocate to STR by operator new.
    bool is_Empty(); //inline implementation
    bool is_full();//inline implementation
    int search(const string key);//returns location of key if in STR; otherwise return -1
    void add( ); //adds a order record to STR
    void remove(const string key); //removes all items in STR with a plant name that matches key.
    void double_size();
    void process();
    void print(); //prints all the elements in STR to the screen
private:
    int count;
    int size;
    order_record *STR;  //array containing the order record data
};



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
    
    //read file
    ifstream in;
    in.open("nursery_stock.txt");
    //in.open("/Users/halleolson/Documents/COP3014/Program 9/nursery_stock.txt");
    
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
//Decription: locates key in STR if it is there; otherwise -1 is returned
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
//            is prompted to enter the plant name, county name, plant cost and quantity.
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
//Name: remove
//Precondition: will delete any pname that match key stored in STR
//Postcondition: deleted any pname that matched key from STR
//Decription: removes all order records in STR with a plant name field that matches key, if it is there.
/*******************************************************************************************************************************/
void order_class::remove(const string key)
{
    for (int i = 0; i < count; i++)
    {
        if(STR[i].pname == key)
        {
            for (int j = i; j < count - 1; j++)
                STR[j] = STR[j+1];
            
            count--;
        }
    }
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

    for(int i=0; i<count; i++)
    {
        temp[i] = STR[i];
    }

    delete [ ] STR;
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
//Name: print
//Precondition: value of run not yet printed
//Postcondition: value of run printed and incremeted throughout file
//Decription: prints every field of every call_record in STR formatted to a file.
/***************************************************************************************************************************/
void order_class::print()
{
    ofstream out;
    out.open("nursery_result30.txt");
    //out.open("/Users/halleolson/Documents/COP3014/Program 9/nursery_result30.txt", fstream::app);
    static int run = 1;

    //put code here for the loop to print the data in the array to the stream out.
    for (int i = 0; i < count; i++)
    {
        out << setw(20) << left << STR[i].pname;
        out << setw(10) << STR[i].cname;
        out.setf(ios :: fixed);
        out << setw(6) << right << setprecision(2) << STR[i].plant_cost << "\t";
        out << setw(4) << STR[i].quantity << "\t";
        out << setw(7) << setprecision(2) << STR[i].net_cost << "\t";
        out << setw(4) << setprecision(3) << STR[i].tax_rate << "\t";
        out << setw(7) << setprecision(2) << STR[i].purchase_tax << "\t";
        out << setw(6) << setprecision(2) << STR[i].discount << "\t";
        out << setw(9) << setprecision(2) << STR[i].total_cost << endl;
    }

    out << "****************************\n";
    out << "*********end of run " << run << "****" << endl;
    out << "*******************************\n";
    run++;
    out.close();
}


/****************************************************************************************************************************/
//Name: destructor
//Precondition: memory not yet de-allocated from STR
//Postcondition: memory de-allocated from STR
//Decription: de-allocates all memory allocated to STR.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
    cout << "The destructor has been called\n";
    delete [] STR;
    size = 0;
    count = 0;
}


//Here is your driver to test the program
int main()
{
    order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
    cout << "**********************************************************************\n";
    //Test 1:
    cout << "Test 1: Testing default construcor, double_size, process, is_full and print " << endl;
    myOrders.process();
    myOrders.print();
    cout << "End of Test 1" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    //Test 2:
    //void add();
    cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
    myOrders.add();//test case: pname = rose, cname = dade, plant cost = 1, quantity = 1
    myOrders.print();
    cout << "End of Test 2" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    //Test 3:
    //void remove(string key);
    cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
    cout << "Removing rose\n";
    myOrders.remove("rose");
    myOrders.print();
    cout << "Removing bergenia\n";
    myOrders.remove("bergenia");
    myOrders.print();
    cout << "Removing yarrow\n";
    myOrders.remove("yarrow");
    myOrders.print();
    cout << "Removing rose ---AGAIN--- SHOULD GET MESSAGE\n";
    myOrders.remove("rose");
    myOrders.print();
    cout << "End of Test 3" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    //Test 4:
    //destructor will be invoked when object myOrders goes out of scope
    cout << "Test 4: Destructor called" << endl;
    cout << "End of Test 4" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    return 0;
}
