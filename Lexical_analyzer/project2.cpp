//Steffen Chirichiello
//cs280-005
//10/27/16
//31389364
#include "p2lex.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool verbose;

int main(int argc, char *argv[])
{
    istream* in = &cin;
    ifstream infile;
    Token t;

    if(argc == 1)
    {
        verbose = false;

    }
    else if(argc == 2)
    {
        if((string)argv[1] == "-v")
        {
            verbose = true;
        }
        else
        {
            infile.open(argv[1]);

            if(infile.is_open() == false)
            {
                cout << "Error opening file" << endl;
            }

            in = &infile;
        }
    }

    else if(argc == 3)
    {
        if((string)argv[1] == "-v" || (string)argv[2] == "-v")
        {
            verbose = true;
        }

        infile.open(argv[1]);
        if(infile.is_open() == true)
        {
            in = &infile;
        }
        else if(infile.is_open() == false)
        {
            infile.open(argv[2]);
            if(infile.is_open() == true)
               {
                   in = &infile;
               }
        }
        else if(infile.is_open() == false)
        {
            cout << "error opening file" << endl;
        }
    }
    else if(argc > 3)
    {
        cerr << "ERROR: too many arguments" << endl;
        return 0;
    }

   while((t = getToken(in)).getTok() != DONE);

    infile.close();
    return 0;
}
