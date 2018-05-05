//Steffen Chirichiello
//12/05/14
//Prof. Aljamar
//*****************************************************************************
// This program uses functions to create and manipulate records from a binary *
// file.                                                                      *
//*****************************************************************************
#include<cstdlib>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;
//declare structure
struct TestScore{
                    int ID;
                    double score; 
                    char grade;
                };
                
void file_create(TestScore &);//creates a binary file
void file_check(TestScore &);//checks if the binary file exists/intact
void populate(TestScore &);//adds records to the binary file from the user
void display(TestScore &);//displays the records to the screen the user created
void append(TestScore &);//adds more records to the file without deleting the old ones
void file_delete(TestScore &);//deletes a record at the user's request
void file_search(TestScore &);//searches and displays a record at the user's request
void modify(TestScore &);//modifies an existing record at the user's request
void sort_file(TestScore &);//sorts the file from greatest to least
void file_clear(TestScore &);//clears the contents of the entire file
int main()
{
    TestScore scores;//declare structure variable
    int choice;
    
    while(choice != 11)
        {   //start menu
            cout << " \n\n 1. Create a Binary file!\n";
            cout << " 2. Check if the Binary file exists!\n";
            cout << " 3. Populate the file with records!\n";
            cout << " 4. Display the file!\n";
            cout << " 5. Append a record!\n";
            cout << " 6. Delete a record!\n";
            cout << " 7. Search for a record!\n";
            cout << " 8. Modify an existing record!\n";
            cout << " 9. Sort the file!\n";
            cout << "10. Clear the contents of the file!\n";
            cout << "11. Exit the program.\n";
    
            cout << " \n\nPlease select a choice!\n";
            cin >> choice;
            cout << "\n" << endl;
    
            switch(choice)
            { 
                case 1:
                        file_create(scores);
                        break;
                case 2:
                        file_check(scores);
                        break;
                case 3:
                        populate(scores);
                        break;
                case 4:
                        display(scores);
                        break;
                case 5:
                        append(scores);
                        break;
                case 6:
                        file_delete(scores);
                        break;
                case 7:
                        file_search(scores);
                        break;
                case 8:
                        modify(scores);
                        break;
                case 9:
                        sort_file(scores);
                        break;
                case 10:
                        file_clear(scores);
                        break;
                case 11:
                        cout <<"Bye.\n";
                        system("pause");
                        exit(1);
                default:
                        cout<< "Invalid choice, terminating program.\n";
                        system("pause");
                        exit(1);
            }//end switch    
        }//end while  
        cin.ignore();     
    system("pause");
    return 0;
}//end main
//**********************
//creates a binary file*
//**********************
void file_create(TestScore &scores)
{
    char choice;
    fstream file;
    cout << "Would you like to create a file?(Y/N)\n";
    cin >> choice;
     
     if (choice == 'y' || choice == 'Y')
     {
       file.open("TestS.dat", ios::out | ios::binary);
       file.close();
    } 
     else if(choice != 'y' || choice != 'Y')
     
     cout << "File was not created.\n";
}  
//****************************************
//checks if the binary file exists/intact*
//****************************************        
 void file_check(TestScore &scores) 
 {
        fstream file;
        
        file.open("TestS.dat", ios::in | ios::out | ios::binary);
        
        if(file.fail())//validate
            {
                cout <<"error, file may not exist!\n";
                system("pause");
                exit(1);
            }   
       cout << "file was created sucessfully!\n";
       system("pause");
}
//******************************************************
//adds records to the binary file at the user's request*
//******************************************************
void populate(TestScore &scores)
{
    fstream file;
    char choice;
    
    file.open("TestS.dat", ios::out | ios::binary);
    do
    {   //creates the record and formats it
        cout <<"Enter the following data about the person:\n";
        cout << "ID: ";
        cin >> scores.ID;
        cout << "Score: ";
        cin >> scores.score;
        cout << "Grade: ";
        cin >> scores.grade;
        file.write(reinterpret_cast<char *>(&scores),sizeof(scores));
        cout << "Would you like to add another record?(Y/N)\n";
        cin >> choice;
        cin.ignore();
    }while(choice == 'y' || choice == 'Y');
     file.close(); 
}
//****************************************************  
//displays the records to the screen the user created*
//****************************************************
void display(TestScore &scores)
{
    fstream file;
    file.open("TestS.dat", ios::in | ios::binary);
    
    if (!file)
        {
            cout <<" Error opening file. Program aborting.\n";
            system("pause");
            exit(1);
        }
        
    file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
    cin.get();
    while(!file.eof())
    {
        
        cout << "ID: ";
        cout << scores.ID << endl;
        cout << "Scores: ";
        cout << scores.score << endl;
        cout << "Grade: ";
        cout << scores.grade << "\n" << endl; 
        cin.get();
        file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
    }
    cout << "File read from successfully" << endl;
    system("pause");
    file.close();
}
//*************************************************************
//adds more records to the file without deleting the old ones * 
//*************************************************************      
void append(TestScore &scores)
{
    fstream file;
    char choice;
    file.open("TestS.dat", ios::out | ios::app | ios::binary);            
    do
    {
        cout <<"Enter the following data about another person:\n";
        cout << "ID: ";
        cin >> scores.ID;
        cout << "Score: ";
        cin >> scores.score;
        cout << "Grade: ";
        cin >> scores.grade;
        file.write(reinterpret_cast<char *>(&scores),sizeof(scores));
        cout << "Would you like to add another record?(Y/N)\n";
        cin >> choice;
        cin.ignore();
    }while(choice == 'y' || choice == 'Y');
     file.close(); 
}
//***************************************
//deletes a record at the user's request*
//***************************************  
void file_delete(TestScore &scores)
{
    fstream file;
    fstream temp;
    int ID_Number;
    file.open("TestS.dat", ios::in | ios::binary);
    temp.open("temp.dat", ios::out | ios::binary);
    if(!file)
    {
        cout << "Error opening file, now aborting" << endl;
        system("pause");
        exit(1);
    }
    cout <<" Enter the ID of the record you want to delete.\n";
    cin >> ID_Number;
    file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
     while(!file.eof())
     {
        if(scores.ID != ID_Number)
        {
           temp.write(reinterpret_cast<char *>(&scores),sizeof(scores));
        }
        file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
     }
    cout <<"Record has been deleted." << endl;

    temp.close();
    file.close();
    remove("TestS.dat");
    rename("temp.dat", "TestS.dat");    
}
//*****************************************************
//searches and displays a record at the user's request*
//*****************************************************
void file_search(TestScore &scores)
{
    fstream file;
    int ID_Number;
    int found = 0;
    file.open("TestS.dat", ios::in | ios::binary);
    if(!file)
    {
        cout << "Error opening file, now aborting" << endl;
        system("pause");
        exit(1);
    }
    cout <<" Enter the ID of the record you want to find.\n";
    cin >> ID_Number;
    file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
    cin.get();
    while(!file.eof())
    {
        if(ID_Number == scores.ID)
        {
            cout << "ID: ";
            cout << scores.ID << endl;
            cout << "Scores: ";
            cout << scores.score << endl;
            cout << "Grade: ";
            cout << scores.grade << "\n" << endl;
            found = 1;
            cout << "Here is the file!" << endl;
            cin.get();
        }
        file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
    }  
    file.close();
    if(found == 0)
    {
        cout << "Sorry record can't be found.\n";
        cin.get();
    }
}
//**************************************************
//modifies an existing record at the user's request*
//**************************************************
void modify(TestScore &scores)
{
    fstream file;
    int number = 1;
    int ID_Number;
    int position;
    
    file.open("TestS.dat", ios::in | ios::binary);//open file
    file.seekg(-1,ios::end);//get the size of the file
    int size = file.tellg();//store it in size
    file.close();
    
    file.open("TestS.dat", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(&scores), sizeof(TestScore));//read binary file
    while(!file.eof())
     {
           //cout << ID_Number << endl;
           cout<< (number++) << " " << scores.ID << endl;
           file.read(reinterpret_cast<char *>(&scores), sizeof(TestScore));
   
     }
     file.close();
     fstream temp("TestS.dat",ios::in | ios::out| ios::binary);
    
    cout <<" Enter the number next to the ID of the record you want to modify.\n";
    cin >> ID_Number;
    position = (ID_Number - 1) * sizeof(TestScore);
    temp.seekg(position,ios::beg);
    temp.read(reinterpret_cast<char *>(&scores), sizeof(TestScore));
    
     
            cout << ID_Number << endl;
            cout << scores.ID << endl;
            cin.ignore();
        cout << "ID: ";
        cin >> scores.ID;
        cout << "Score: ";
        cin >> scores.score;
        cout << "Grade: ";
        cin >> scores.grade;
        temp.seekp(position,ios::beg);
       temp.write(reinterpret_cast<char *>(&scores),sizeof(TestScore));
            
                cout << "ID: ";
                cout << scores.ID << endl;
                cout << "Scores: ";
                cout << scores.score << endl;
                cout << "Grade: ";
                cout << scores.grade << "\n" << endl;
                
                cout << "Here is the file!" << endl;
             temp.close();
           
}               
            
           
void sort_file(TestScore &scores)
{   fstream temp;
    fstream file;
    file.open("TestS.dat", ios::in | ios::binary);
    file.open("Temp.dat", ios::out | ios::binary);
    int max;
    max == scores.score;
    file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
    while(!file.eof())
    {
        
        if(scores.score > max)
        {
            temp.write(reinterpret_cast<char *>(&scores),sizeof(scores));
         }
        file.read(reinterpret_cast<char *>(&scores), sizeof(scores));
       
   }
    cout << "File has been sorted.\n";
    cin.get();
    temp.close();
    file.close();
    remove("TestS.dat");
    rename("temp.dat", "TestS.dat");
}   

   
//***************************************
//clears the contents of the entire file*
//***************************************
void file_clear(TestScore &scores)
{
    fstream file;
    fstream temp;
    char choice;
    file.open("TestS.dat", ios::app | ios::binary);
    cout << "This will delete the contents of the file. Do you wish to proceed?(Y/N)\n";
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
    {
        temp.open("temp.dat", ios::out | ios::binary);
        cout <<" The contents have been erased!\n";
        system("pause");
        temp.close();
        file.close();
        remove("TestS.dat");
        rename("temp.dat", "TestS.dat");
    }
    else if(choice != 'y' || choice != 'Y')
    {
        cout<< "The contents have not been erased!\n";
        system("pause");
        file.close();
    }
}
    
                
