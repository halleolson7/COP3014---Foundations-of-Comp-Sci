/*****************************************************************
   Name:      Halle Olson                  Z-number Z23547920
   Course: COP3014
   Professor: Dr.Lofton Bullard
   Due Date : 7/20/2021
   Total Points : 10
   Assignment# : Assignment 8

   Description : The purpose of this program is to read a data file and process that data into a dynamic array. The records are then printed to the ofstream file. We work with the "new" and "delete" operators for allocating and de-allocating memory. Our data is basically copied from one dynamic array to another dynamic array we use append mode with our ofstream.
   *************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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


//Prototypes for your functions

void initialize(order_record*& STR, int& count, int& size);
bool is_Empty(int count);
bool is_Full(int count, int size);
int search(order_record* STR, int  count, string key);
void add(order_record*& STR, int& count, int& size);
void remove(order_record* STR, int& count, string key);
void double_size(order_record*& STR, int  count, int& size);
void process(order_record* STR, int count);
void print(const order_record* STR, const int  count);
void destory_STR(order_record* STR, int& count, int& size);

//Function Implementations will go here
/*************************************************************************************************************************************************/
//Name: initialize
//Precondition: count is not yet initialized, size is not yet initialized, ifstream has not been declared or opened, data from file has not been read
//Postcondition: count is initialized to 0, size is initialized to 1, ifstream has been declared and file has been opened, data from the file has been read
//Decription: Reads the data file of call information (cell number, item_number, quantity, price, and processing_plant) into the dynamic
//array of call record, STR. If the count because equal to the size the function double_size is called and the memory allocated to STR is doubled.
/***********************************************************************************************************************************************/
void initialize(order_record*& STR, int& count, int& size)
{
    //Put the code here to the dynamic array STR.  Remember to: 1) initialize size to 1 and count to 0;
    count = 0;
    size = 1;
    STR = new order_record[size];
    //2)open and close the ifstream object; 3) allocate memory for the dynamic array; 4) call double_size if
    ifstream in;
    in.open("nursery_stock.txt");
    //in.open("/Users/halleolson/Documents/COP3014/Program 8/nursery_stock.txt");
    
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
            else
            {
                double_size(STR, count, size);
                in >> STR[count].pname >> STR[count].cname >> STR[count].plant_cost >> STR[count].quantity;
                count++;
            }
                
        }
        
    }
    in.close();
    

    //the array becomes full. Hint see program "dynamic_array_example8.cpp"
}

/**********************************************************************************************************************************/
//Name: is_Empty
//Precondition: will return true or false
//Postcondition: returned true or false
//Decription: returns true if STR is empty
/*********************************************************************************************************************************/
bool is_Empty(int count)
{
    return count == 0;
}

/**********************************************************************************************************************************/
//Name: Is_full
//Precondition: will return true or false
//Postcondition: returned true or false
//Decription: returns true if STR is full
/*********************************************************************************************************************************/
bool is_Full(int count, int size)
{
    return count == size;
}


/**********************************************************************************************************************************/
//Name: search
//Precondition: not yet searched and found key or returned -1
//Postcondition: searched and found key or returned -1
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int search(order_record* STR, int  count, string key)
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
//Decription: adds a new record to STR; if STR is full, double_size is called to increase the capacity of STR.
/********************************************************************************************************************************/
void add(order_record*& STR, int& count, int& size)
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
    
    else if (count == size)
    {
        double_size(STR, count, size);
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
    process(STR, count);
}


/********************************************************************************************************************************/
//Name: Remove
//Precondition: will delete any pname that match key stored in STR
//Postcondition: deleted any pname that matched key from STR
//Decription: remove all occurences of key from STR if it is there.
/*******************************************************************************************************************************/
void remove(order_record* STR, int& count, string key)
{
    //Put the code here to remove ALL the records in STR that have a pname equal to key
    //If you find the item(s), you must shift and decrement count. Hint see program "dynamic_array_example8.cpp"
 
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
void double_size(order_record*& STR, int  count, int& size)
{
    //Put the code here to double the size (amount of memory allocated to the array) of the dynamic array.
    //You must allocate memory using new. Hint see program "dynamic_array_example8.cpp"
    size *= 2;
    order_record *temp = new order_record[size];
    
    for (int i = 0; i < count; i++)     //records in STR copied into temp
        temp[i] = STR[i];
    
    delete [] STR;      //old memory de-allocated
    STR = temp;         //STR set to point to the new memory, poinhted to temp
}

/******************************************************************************************************************************/
//Name: process
//Precondition: pname, cname, plant_cost, and quantity have been initialized. net_cost, tax_rate, discount, purchase_tax, and total_cost have not yet been calculated
//Postcondition: pname, cname, plant_cost, and quantity have been initialized. net_cost, tax_rate, discount, purchase_tax, and total_cost have been calculated and stored
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in STR.
/*****************************************************************************************************************************/
void process(order_record* STR, int count)
{
    //Put the code here for the loop to process the data stored in the array.
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
            STR[i].discount = .12 * STR[i].net_cost;
        
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
//Decription: prints every field of every order_record in STR formatted to the screen.
/***************************************************************************************************************************/
void print(const order_record* STR, const int  count)
{
    ofstream out;
    out.open("nursery_result20.txt", fstream::app);
    //out.open("/Users/halleolson/Documents/COP3014/Program 8/nursery_result20.txt", fstream::app);
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
//Name: destroy_STR
//Precondition: memory not yet de-allocated from STR
//Postcondition: memory de-allocated from STR
//Decription: de-allocates all memory allocated to STR.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void destory_STR(order_record* STR, int& count, int& size)
{
    //Remember to set count and size to zero, and delete the memory allocated to STR using the new operator.
    delete [] STR;
    count = 0;
    size = 0;
}

//Here is your driver to test the program
int main()
{
    int count = 0; //intializating count
    int size = 1;
    order_record* STR = 0;//declaring the dynamic array

    cout << "**********************************************************************\n";
    cout << "Test 1: Testing initialize, double_size, process, is_full and print " << endl;
    initialize(STR, count, size);
    process(STR, count);
    print(STR, count);
    cout << "End of Test 1" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    ////Test 2:
    ////void add(order_record * & STR, int & count, int & size);
    cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
    add(STR, count, size);
    print(STR, count);
    cout << "End of Test 2" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    ////Test 3:
    ////void remove(order_record * STR, int & count, string key);
    cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
    cout << "Removing rose\n";
    remove(STR, count, "rose");
    print(STR, count);
    cout << "Removing owl\n";
    remove(STR, count, "owl");
    print(STR, count);
    cout << "End of Test 3" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    ////Test 4:
    ////void add(order_record * & STR, int & count, int & size);
    cout << "Test 4: Testing add, double_size, process, is_full, and print " << endl;
    add(STR, count, size);
    print(STR, count);
    cout << "End of Test 4" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    ////void destroy_STR(order_record  * STR, int & count, int & size);*/
    cout << "Test 5: destroy_STR and print " << endl;
    destory_STR(STR, count, size);
    cout << "size = " << size << endl;
    cout << "count = " << count << endl;
    cout << "End of Test 5" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    return 0;
}
