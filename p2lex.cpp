#include<iostream>
#include<string>
#include"p2lex.h"
#include<map>
#include<fstream>
using namespace std;

// defines the linenum declared as extern in p2lex.h
	int linenum = 1;

extern bool verbose;

void skipSpace(std::istream *instream);

//getToken function
Token getToken(std::istream* instream)
{
    map <char,string> Tokens = { {'+', "plus"}, {'*', "star"}, {'[', "LEFTSQ" }, {']',"RIGHTSQ"},
                                 {';',"SC" }, {'(', "LPAREN"}, {')',"RPAREN"}
                               };
    map <char,string>::iterator it;


    map <char,int> TokenFreq = { {'+', 0}, {'*', 0}, {'[', 0 }, {']',0},
                                 {';',0 }, {'(', 0}, {')',0}
                               };

    map<string,int> uniqueINT;
    map <string,int> uniqueID;
    map <string, int> uniqueSTR;


    string id = "";
    string st = "";
    string num = "";
    int idNum = 0;
    int strNum = 0;
    int setNum = 0;
    int printNum = 0;
    int plusNum = 0;
    int starNum = 0;
    int leftsqNum = 0;
    int rightsqNum = 0;
    int scNum = 0;
    int lparenNum = 0;
    int rparenNum = 0;
    int intNum = 0;
	char c;

	while(true)
    {

        if (instream->eof())
        {
                if(idNum != 0)
                {
                     cout << "id: " << idNum << endl;
                }

                if(setNum != 0)
                {
                    cout << "set: " << setNum << endl;
                }

                if(printNum != 0)
                {

                    cout << "print: " << printNum << endl;
                }

                if(plusNum != 0)
                {
                    cout << "plus: " << plusNum << endl;
                }

                if(strNum != 0)
                {
                    cout << "str: " << strNum << endl;
                }

                if(starNum != 0)
                {
                    cout << "star: " << starNum << endl;
                }

                if(leftsqNum != 0)
                {
                    cout << "leftsq: " << leftsqNum << endl;
                }

                if(rightsqNum != 0)
                {
                    cout << "rightsq: " << rightsqNum << endl;
                }

                if(lparenNum != 0)
                {
                    cout << "lparen: " << lparenNum << endl;
                }

                if(rparenNum != 0)
                {

                    cout << "rparenL " << rparenNum << endl;
                }
                if(scNum != 0)
                {
                    cout << "sc: " << scNum << endl;
                }

                if(intNum != 0)
                {
                    cout << "int: " << intNum << endl;
                }

            cout << "Number of unique lexemes for id: " << uniqueID.size() << endl;
            cout << "Number of unique lexemes for int: " << uniqueINT.size() << endl;
            cout << "Number of unique lexemes for str: " << uniqueSTR.size() << endl;

            return Token(DONE, "done");
        }

        skipSpace(instream);//skips space until can't anymore

        c = (char) instream->get();
        it = Tokens.find(c);
        if(it != Tokens.end())//if you find special token in map display it
        {
            if(verbose)
            {
            cout << Tokens.find(c)->second << endl;
            }
            else
            {
                cout << Tokens.find(c)->second << endl;
            }

            if(c == '+')
            {
                plusNum += 1;
            }

            if(c == '*')
            {
                starNum += 1;
            }

            if(c == '[')
            {
                leftsqNum += 1;
            }

            if(c == ']')
            {
                rightsqNum += 1;
            }

            if(c == ';')
            {
                scNum += 1;
            }

            if(c == '(')
            {
                lparenNum += 1;
            }

            if(c == ')')
            {
                rparenNum += 1;
            }

            TokenFreq.at(c) += 1;//increment its frequency by one
        }//end if you find special token

            while(isalpha(c))
            {
                id += c;

                if(isspace(instream->peek()) || !isalpha(instream->peek()))//if next character is a space or not a letter
                   {
                       if(id.length() == 3 && id == "set")
                       {
                           if(verbose)
                           {
                                Token tset(SET,"set");
                                cout << tset;
                                id = "";
                                setNum += 1;
                                break;
                           }
                           else
                           {
                                Token tset(SET,"set");
                                cout << tset;
                                id = "";
                                setNum += 1;
                                break;
                           }
                           id = "";
                           setNum += 1;
                           break;
                       }

                       if(id.length() == 5 && id =="print")
                       {
                           if(verbose)
                           {
                                Token tprint(PRINT, "print");
                                cout << tprint;
                                id = "";
                                printNum += 1;
                                break;
                           }
                           else
                           {
                               Token tprint(PRINT, "print");
                                cout << tprint;
                                id = "";
                                printNum += 1;
                                break;
                           }
                           printNum += 1;
                           id = "";
                           break;
                       }

                       uniqueID[id]+= 1;

                       if(verbose)
                       {
                           Token ti(ID,id);
                           cout << ti;
                           id = "";
                       }

                       else
                       {
                           Token ti(ID,id);
                           cout << ti;
                           id = "";
                       }

                       id = "";
                       idNum += 1;
                       break;
                   }

                c = (char) instream->get();
            }

            if(c == '"')
            {
                while(isalnum(instream->peek()))
                {
                    c = (char) instream->get();
                    st += c;
                }

                uniqueSTR[st] += 1;
                strNum += 1;
                instream->get();

                if(verbose)
                {
                    Token ts(STR,st);
                    cout << ts;
                }

                else
                {
                    Token ts(STR,st);
                    cout << ts;
                }

                st = "";
            }
            while(isdigit(c))
            {
                num += c;

                if(isspace(instream->peek()) || !isdigit(instream->peek()))
                   {
                       uniqueINT[num] += 1;

                       if(verbose)
                       {
                            Token Tint(INT,num);
                            cout << Tint;
                            num = "";
                            intNum +=1;
                            break;
                       }
                       else
                       {
                           Token Tint(INT,num);
                            cout << Tint;
                            num = "";
                            intNum +=1;
                            break;
                       }

                    intNum += 1;
                    num = "";
                    break;
                   }

                c = (char) instream->get();
            }

            if(c == '/' && instream->peek() == '/')
            {
                while(c != '\n')
                {
                    c = (char)instream->get();
                }
            }
            if(c == '\n')
            {

                linenum += 1;
            }
    }
}
//ostream function
ostream& operator<<(std::ostream& out, const Token& t)
{
    map <int, TokenType> TokenName = { {2,INT}, {1,STR}, {3,PLUS}, {0,ID}, {4, STAR}, {5, LEFTSQ}, {6, RIGHTSQ},
                                           {7, PRINT},{8, SET}, {9, SC}, {10, LPAREN}, {11, RPAREN}, {12, DONE},
                                           {13, ERR}
                                         };
            switch(t.getTok())
            {
                case 0:
                    return out << "ID" << "(" << t.getLexeme() << ")" << endl;
                case 1:
                    return out << "STR" << "(\"" << t.getLexeme() << "\")" << endl;
                case 2:
                    return out << "INT" << "(" << t.getLexeme() << ")" << endl;
                case 7:
                    return out << "print" << endl;
                case 8:
                    return out << "set" << endl;
                case 12:
                    return out << "DONE" << endl;
                case 13:
                    return out << "ERR" << "(" << t.getLexeme() << ")" << endl;

            }
}
//skipSpace function
void skipSpace(std::istream *instream)
{
	while(isspace(instream->peek()))
	{
		instream->get();
	}
}
