//Steffen Chirichiello cs435 9364 mp
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void HashCreate(int [], string &, int &, string[], int &);
int HashEmpty(int[], int &);
void HashInsert(string &, int[], int &, string[], int &);
void HashDelete(string &, int[], int &, string[], int &);
int HashFull(int[], int &);
void HashSearch(string &, int[], int &, string[], int &);
void HashPrint(int T[], int &T_size, string A[], int &A_size);
string grab_command1(string &);
string grab_command2(string &);

int main(int argc, char *argv[])
{
  ifstream infile;
  string line;
  string command1;
  string command2;
  int T_size;
  int T[T_size];
  
  int A_size = 170; //initialize to random large integer. This is the only way i do not receive a seg. fault. It's size is properly changed to 15 * m in HashCreate
  string A[A_size]; 
  
  infile.open(argv[1]);
  
  if(argc < 2)
  {
    cerr << "File to be opened is missing" << endl;
    return 1;
  }
  
  if(infile.is_open() == false)
  {
    cerr << "Cannot open file " << argv[1] << endl;
    return 1;
  }
  
  if(argc > 2)
  {
    cerr << "Too many file names specified" << endl;
    return 1;
  }
  
  while(getline(infile, line))//while loop
  {
    command1 = grab_command1(line);
    command2 = grab_command2(line);
    
    if(command1 == "14") //Create
    {
      HashCreate(T, command2, T_size, A, A_size);
    }
     
    if(command1 == "10") //insert
    {
      HashInsert(command2, T, T_size, A, A_size);
    }
    
    if(command1 == "11") //delete
    {
      HashDelete(command2, T, T_size, A, A_size);
    }
    
    if(command1 == "13") //print
    {
      HashPrint(T, T_size, A, A_size);
    }
    
    if(command1 == "12") //search
    {
      HashSearch(command2, T, T_size, A, A_size);
    }
  }
  
 if(HashEmpty(T, T_size))
  {
    cerr << "it's empty" << endl;
  }
  
  return 0;
}

string grab_command1(string &line) // grab fist command
{
  string command1;
  
  if(line.length() == 2)
  {
    command1 = line.substr(0,3);
    return command1;
  }
  
  command1 = line.substr(0,2);
  
  return command1;
}

string grab_command2(string &line) // grab second command
{
  string command2;
  
  if(line.length() < 3)
  {
    return "";
  }
  
  command2 = line.substr(3, line.length());
  
  return command2;

}

void HashCreate(int T[] , string &command2, int &T_size, string A[], int &A_size) // create hash table
{
  T_size = stoi(command2);
  A_size = 15 * T_size; //set the A array to hold 15 times the size of the T table
  
  for(int i = 0; i < T_size; i++) // initialize all elements in T table to -1 for checking purposes
      {
        T[i] = -1;
      }
  
  for(int i = 0; i < A_size; i++) // initalize all elements in A array to spaces for requirement purposes =]
  {
    A[i] = " ";
  }
}

int HashEmpty(int T[], int &T_size) // check if hashtable is empty
{
  for(int i = 0; i < T_size; i++)
  {
    if(T[i] != -1)
    {
      return 0;
    }
  }
  
  return 1;
  
}

int HashFull(int T[], int &T_size)
{
  for(int i = 0; i < T_size; i++)
  {
    if(T[i] == -1)
    {
      return 0;
    }  
  }
  
  return 1;
}

void HashInsert(string &command2, int T[], int &T_size, string A[], int &A_size)
{
  //h(k,i) = (h'(k)+i^2) % m
  //h'(k) = Sum of ascii characters
  int sum = 0;
  int t_index = 0; //index in T table which contains the starting index of where the name can be found in A array
  int a_index = 0; //starting index in which name will be found in A array
  int nul = 0;
  
  if(HashFull(T, T_size))
  {
    cerr << endl << "Error, Hash table is full. Cannot insert: " << command2 << endl;
    return;
  }
  
  for(int i = 0; i < T_size; i++)//i^2
  {
    for(int j = 0; j < command2.size(); j++)//h'(k)
    {
      sum += command2[j];
    }
   
    sum += i*i;
    
    t_index = sum % T_size;

    if(T[t_index] == -1)// if the index in table T is empty
    {
      for(a_index = 0; a_index < A_size; a_index++)// find starting place in A array to put string
      {
        if(A[a_index] == " ")
        {
          
          break;
        }
      }
      T[t_index] = a_index;// you can find the string at location a_index in A array from the T array
      break; // found a spot for index in T
    }
    
    if(i == T_size - 1)
    {
      cerr << endl << "Overflow error, i cannot exceed length of T table. Cannot insert: " << command2 << endl;
      return;
    } 
    else // if collision occurs
    {
      sum = 0;
      continue;
    }
    
    
  }//end for
  
  //insert name into A array
  for(int i = 0; i < command2.size(); i++)
  {
    A[a_index + i] = command2[i];
  }
    
  A[a_index + command2.size()] = "\0"; //insert null charcater at end of word in A array
    
  return;
}

void HashDelete(string &command2, int T[], int &T_size, string A[], int &A_size)//delete index in T array and replace word in A array with *'s
{
  string match = "";
  int d_index = 0;
  bool flag = 0;
  
  if(HashEmpty(T, T_size))
  {
    cerr << "Error, Hash table is empty. Cannot Delete: " << command2 << endl;
    return; 
  } 
   
  for(int i = 0; i < A_size; i++)
  {
    if(A[i] != "\0")
    {
      match += A[i];
    }
    
    if(A[i] == "\0")
    {
      if(match != command2)
      {
        match = "";
        continue;
      }
      else // if a matching name is found
      {
        flag = 1;
       
        for(int j = i - 1; A[j] != "\0"; j--)
        {
          A[j] = "*";//replace name with '*'
          d_index = j;
          if(d_index == 0)
          {
            break;
          }
          
        }
      }
    }
  
  }
  
  if(flag == 0)
  {
    cout << endl << command2 << " cannot be deleted " << endl;
    return;
  }
  
  for(int i = 0; i < T_size; i++)
  {
    if(T[i] == d_index)
    {
      T[i] = -1; //delete key from T array
      cout << endl << command2 << " deleted from " << "slot: " << i << endl; 
    }
  
  }
  
}

void HashSearch(string &command2, int T[], int &T_size, string A[], int &A_size)
{
  string match = "";
  int s_index = 0;
  bool flag = 0;
  
  if(HashEmpty(T, T_size))
  {
    cerr << "Error, Hash table is empty. Cannot Search for: " << command2 << endl;
    return; 
  } 
   
  for(int i = 0; i < A_size; i++)
  {
    if(A[i] != "\0")
    {
      match += A[i];
    }
    
    if(A[i] == "\0")
    {
      if(match != command2)
      {
        match = "";
        continue;
      }
      else // if a matching name is found
      {
        flag = 1;
        
        for(int j = i - 1; A[j] != "\0"; j--)
        {
          s_index = j;
          if(s_index == 0)
          {
            break;
          }
          
        }
      }
    }
  
  }
  
  if(flag == 0)
  {
    cout << endl << command2 << " not found " << endl;
    return;
  }
  
  for(int i = 0; i < T_size; i++)
  {
    if(T[i] == s_index)
    {
      cout << endl << command2 << " found at slot: " << i << endl; 
    }
  }
  
}


void HashPrint(int T[], int &T_size, string A[], int &A_size)
{
  string A_content = "";

  cout << endl << endl; // start print below extra new line
    
  cout << setw(5) << "T" << setw(20) << "A: ";
  
  for(int i = 0; i < A_size; i++) // print A array in all of its glory
  {
    if(A[i] != " ")
    {  
      cout << A[i];
      if(A[i] == "\0")
      {
        cout << "\\";
      }
    }
  }
  
  cout << endl; // start T table on new line
  
  for(int i = 0; i < T_size; i++) // print T array, is ight
  {
    if(T[i] == -1)
    {
      cout << setw(2) << i << ": " << endl;
      continue;
    }
    
    cout << setw(2) << i << ": " << T[i] << endl;
  }
  
  cout << endl << endl;

}
