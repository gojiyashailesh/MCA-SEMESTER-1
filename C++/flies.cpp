#include<iostream>
#include<fstream>


using namespace std;

int main (){

    string st = "gojiya shailesh";
    string st2;
    
    ofstream out ("my.txt");
    out<<st;

    ifstream in ("my.txt");
    getline(in, st2);
    out<<st2;

    return 0;
}