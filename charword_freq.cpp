/*****************************************************************
   Name:      Halle Olson                  Z-number Z23547920
   Course: COP3014
   Professor: Dr.Lofton Bullard
   Due Date : 7/14/2021
   Total Points : 10
   Assignment# : Assignment 7

   Description : This program calculates the number of letters and words that occur in a block of text stored in a data file
   *************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//prototypes
void openFile(ifstream &in); //opens file
void readFile(ifstream &in); //reads file
void closeFile(ifstream &in); //closes file

//definitions
///*************************************************************************************
//Name:  openFile
//Precondition: "word_data.txt" is not open
//Postcondition: "word_data.txt" is opened
//Description: The function openFile opens "word_data.txt" file with an ifstream accessible to other functions
///*************************************************************************************
void openFile(ifstream &in)
{
    in.open("word_data.txt");
    //in.open("/Users/halleolson/Documents/COP3014/Program 7/word_data.txt");
}

///*************************************************************************************
//Name:  readFile
//Precondition: "word_data.txt" is accessible via ifstream, frequency of letters is not yet calculated, variables let and wordCount are not yet declared, file has not been read through, output has not been printed to screen
//Postcondition: "word_data.txt" is still accessible via ifstream, frequency of letters has been calculated and all letters have been initialized and changed to lowercase, end of file has been reached, word and letter count have been printed to the screen
//Description: The function readFile reads "word_data.txt" file with an ifstream accessible to other functions. It counts how many times a letter appears and how many total words appear on the file using a while loop. If letters are uppercase they are changed to lowercase and then the total words and letters are printed to the screen
///*************************************************************************************
void readFile(ifstream &in)
{
    //store the frequency of the letters
    int letters[128];
    
    //declare variables
    char let;
    int wordCount = 0;
    
    //for loop to initialize all counts to zero
    for (int i = 0; i < 128; i++)
    {
        letters[i] = 0;
    }

    //get letters until we reach end of file
    //whitespace = wordCount++;
    let = in.get();
    while (let != EOF)
    {
        if (let == ' ')
            wordCount++;
        
        //change to lowercase
        let = tolower(let);
        
        letters[let]++;
        let = in.get();
    }
    
    //output
    //num words
    cout << wordCount + 1 << " words" << endl;
        
    //count how many of each letter there are & print to screen in alphabetical order
    for (char let = 'a'; let <= 'z'; let++)
    {
        if (letters[let] != 0)
        {
            cout << letters[let] << " "<< let <<endl;
        }
    }
}
///*************************************************************************************
//Name:  closeFile
//Precondition: "word_data.txt" is open
//Postcondition: "word_data.txt" is closed
//Description: The function closeFile closes "word_data.txt" file with an ifstream accessible to other functions
///*************************************************************************************
void closeFile(ifstream &in)
{
    in.close();
}

//main function
int main()
{
    //input stream
    ifstream in;

    openFile(in);   //open file
    readFile(in);   //read file
    closeFile(in);  //close file
    return 0;
}
