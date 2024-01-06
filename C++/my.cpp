#include<iostream>
#include<fstream>
using namespace std;

class student{
    int RollNo;
    char Name[30];
    char Address[40];
public:
    void ReadStudent();
};

void student::ReadStudent()
{
    cout << "\n Enter roll no.: ";
    cin >>RollNo;
    cout << "\n Enter name: ";
    cin >>Name;
    cout << "\n Enter address: ";
    cin >>Address;
    cout << "\n";
}

int main(){
    student obj;
    ofstream file;
    file.open("msc.dat", ios::out | ios::binary | ios::trunc);
    if(!file.is_open()){
        cout<<"File not opened.";
    }
    else{
        obj.ReadStudent();
        file.write((char *)&obj, sizeof(obj));
        obj.ReadStudent();
        file.seekp(0, ios::beg);
        file.write((char*)&obj, sizeof(obj));
        file.close();
    }
    return 0;
}