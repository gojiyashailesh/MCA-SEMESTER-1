#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
using namespace std;
class employee{
int empid;
string str;
string name,address;
public:
void getdata()
{
    cout<<"Employee Id:-"<<"\n";
    cin>>empid;
    cout<<"Name of employee"<<"\n";
    cin>>name;
    cout<<"Address of employee"<<"\n";
    cin>>address;
}
void addRecord()
{
    fstream fout("q12.txt",ios::out|ios::app);
    while(true)
    {
        getline(cin,str);
        if(str=="$")
        break;
        fout<<str<<"\n";
    }
    fout.close();
}

void showData()
{
    fstream fin("q12.txt",ios::in);
    while(getline(fin,str))
    {
        cout<<str<<"\n";
    }
    fin.close();
}

};
int main()
{   
    employee e;

    int ch;
    while(true)
    {
    cout<<"choose any one option.\n";
    cout<<"1. to add a new record.\n";
    cout<<"2. to modify an existing record.\n";
    cout<<"3. to Retrieve and display an entire record for a given name.\n";
    cout<<"4. to add a new record.\n";
    cout<<"5. to exit.\n";
    cout<<"Enter your choice...\n";
    cin>>ch;

        switch(ch)
        {
            case 1:
            e.addRecord();
            break;
            case 2:
            break;
            case 3:
            e.showData();
            break;
            case 4:
            break;
            case 5:
            exit(1);
            default:
            cout<<"You have entered wrong choice\n";

        }
    }
    return 0;
    getch();
}