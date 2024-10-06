#include <bits/stdc++.h>
using namespace std;

string enc(string text,int shift)
{
    string result="";
    char ch;
    for(int i=0;i<text.length();i++)
    {
        ch=text[i];
        if(isupper(ch))
        {
            result+= char(int(ch+shift-65)%26+65);
        }
        else if(islower(ch))
        {
            result+= char(int(ch+shift-97)%26+97);
        }
        else
            result+=ch;
    }
    return result;
}

int main()
{
    string line,ptext;
    ifstream inputFile("input.txt");
    if(inputFile.is_open())
    {
        while (getline(inputFile,line))
        {
            ptext+=line;
        }
        inputFile.close();
        
    }

    //getline(cin,ptext);
    string ctext=enc(ptext,3);
    string dtext=enc(ctext,26-3);
    cout<<ptext<<"\n"<<ctext<<"\n"<<dtext;
}
