#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    char ch,oldch;
    string str;
    int word=0,line=0;
    fstream fout("q8.txt",ios::out);
    // if(!fout.is_open())
    // {
    //     cout<<"file opening is failed\n";
    // }
    while(true)
    {
        cin.get(ch);
        if(ch=='$')
        break;
        fout<<ch;
    }
    fout.close();

    fstream fin("q8.txt",ios::in);
    fin.unsetf(ios::skipws);

    while(!fin.eof())
    {
        fin>>ch;
        if(oldch=='\n'&&(ch!='\0'&&ch!=' '))
        {
        word++;
        }
        if(ch=='\n')
        line++;
        if(ch==' ')
        word++;
        //.put(ch);
        cout.put(ch);
        oldch=ch;

    }
    fin.close();

    cout<<"\n\n";
    cout<<"there were "<<word<<" words and "<<line-1<<" lines\n";

    fin.open("q8.txt",ios::in);
    fout.open("q8copy.txt",ios::out);

    if(fin&&fout)
    {
        while(getline(fin,str))
        {
            fout<<str<<"\n";
        }
        cout<<"file copied successfully\n";
    }
    else
    {
        cout<<"file copying failed\n";
    }

    fout.close();
    fin.close();

    getch();
    return 0;

}