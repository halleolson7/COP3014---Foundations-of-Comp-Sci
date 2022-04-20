
/************************************************************************************************************************
 order_class.h
 
Name:  Halle Olson        Z#: Z23547920
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  08/03/2021           Due Time: 11:59 PM
Total Points: 20
Assignment #: nursery_porder11.cpp

Description: This assignment is an extension of Program 10, which implements a class called order_class. We decalre the class in "order_class.h" and implement the class in "order_class.cpp". We use processor directives #ifndef, #define, and #endif

*************************************************************************************************************************/

#ifndef ORDER_CLASS_H
#define ORDER_CLASS_H

#include <iostream> // for input and output
#include <string> // for string operations
#include <fstream> // for file
#include <iomanip> // for formatting

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

order_class();
order_class(const order_class& org);
~order_class(); //de-allocates all memory allocate to STR by operator new.
bool is_Empty(); //inline implementation
bool is_full();//inline implementation
int search(const string key);//returns location of key if in STR; otherwise return -1
void add( ); //adds a order record to STR
order_class & operator-(const string key); //removes all items in STR with a plant name that matches key.
void double_size();
void process();
friend ostream& operator<<(ostream & out, order_class & ORG); //prints all the elements in ORG's STR to the screen

private:

int count;
int size;
order_record *STR;

};

#endif 
