#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;
class customer
{
    int ano, s = 0, t = 0;
    string atype, name, dolp, tran_type, password;
    double oldbal = 0, newbal = 0, lastpay = 0, curpay = 0, curbal = 0;

public: 
    void get_customer()
    {
        cout << "Enter your account No.\n";
        cin >> ano;
        cout << "Create password\n";
        cin >> password;
        cout << "Enter name of the customer\n";
        cin >> name;
        cout << "select your account type\n";
        cin >> atype;
        cout << "Enter your Account opening balance(must be greater then 500 rs.).\n";
        cin >> curbal;
    }

    bool verify(int acc, string pwd)
    {
        if (ano == acc && pwd == password)
            return true;
        else
            return false;
    }

    void get_transaction()
    {
        int ch;
        do
        {
            cout << "Choose operation you want to perform:\n";
            cout << "Press 1. to deposit into account\n";
            cout << "Press 2. to withdaraw from account\n";
            cout << "Press 3. to show account transaction details\n";
            cout << "Press 4. to logout from account\n";
            cout << "Enter you choice\n";
            cin >> ch;

            switch (ch)
            {

            case 1:
            {
                cout << "Enter amount you want to deposit\n";
                cin >> curpay;
                lastpay = curpay;
                oldbal = curbal;
                curbal = curbal + curpay;
                newbal = curbal;
                tran_type = "Deposit";
                time_t now = time(0);
                dolp = ctime(&now);
                this->store_customer_details();

                break;
            }
            case 2:
            {
                cout << "Enter amount you want to withdraw\n";
                cin >> curpay;
                if (curpay < curbal - 500)
                {
                    lastpay = curpay;
                    oldbal = curbal;
                    curbal = curbal - curpay;
                    newbal = curbal;
                    tran_type = "Withdraw";
                    time_t now = time(0);
                    dolp = ctime(&now);
                    this->store_customer_details();

                }
                else
                {
                    cout << "Minimum Account balance Should be 500 rs.\n";
                }
                break;
            }
            case 3:
                show_customer_file();
                break;
            // case 4:
            //     exit(1);
            default:
            break;
            }
        }while(ch!=4);
        
    }

    void store_customer_details()
    {
        if (s < 1)
        {
            fstream fout("q13.dat", ios::out | ios::binary);
            s++;
            if (!fout.fail())
            {
                if (fout.write((char *)this, sizeof(*this)))
                {
                    cout << "Data stored into file successfully\n";
                }
                else
                {
                    cout << "sorry unable to store data into file\n";
                }
            }
            else
            {
                cout << "sorry unable to open file\n";
            }
            fout.close();
        }
        else
        {
            fstream fout("q13.dat", ios::out | ios::binary);
            s++;
            if (!fout.fail())
            {
                if (fout.write((char *)this, sizeof(*this)))
                {
                    cout << "Data stored into file successfully\n";
                }
                else
                {
                    cout << "sorry unable to store data into file\n";
                }
            }
            else
            {
                cout << "sorry unable to open file\n";
            }
            fout.close();
        }
    }

    void show_customer()
    {
        cout << "Account No :-" << ano << "\n";
        cout << "Name :-" << name << "\n";
        cout << "Account Type :-" << atype << "\n";
        cout << "Current balance :-" << curbal << "\n";
        cout << "Old balance :-" << oldbal << "\n";
        cout << "Last transaction amount :-" << lastpay << "\n";
        cout << "New balance :-" << curbal << "\n";
        cout << "Last transaction type :-" << tran_type << "\n";
        cout << "Last transaction date :-" << dolp << "\n";
    }

    void show_customer_file()
    {

        int tempano = this->ano;
        if (t < 1 && s < 1)
        {
            fstream fin("q13.dat", ios::in | ios::binary | ios::trunc);
            s++;
            cout << "No data to show\n";
            // if (!fin.fail())
            // {
            //     while (fin.read((char *)this, sizeof(*this)))
            //     {
            //         if (tempano == this->ano)
            //             this->show_customer();
            //     }
            // }
            // else
            // {
            //     cout << "sorry unable to open file\n";
            // }
            fin.close();
        }
        else
        {
            fstream fin("q13.dat", ios::in | ios::binary);
            s++;
            if (!fin.fail())
            {
                while (fin.read((char *)this, sizeof(*this)))
                {
                    if (tempano == this->ano)
                        this->show_customer();
                }
            }
            else
            {
                cout << "sorry unable to open file\n";
            }

            fin.close();
        }
    }
};

int main()
{
    bool b = false;
    int n, a = 0, acc, ch;
    string pwd;
    cout << "welcome to banking management system:\n";
    cout << "how many customers you want to handle?\n";
    cin >> n;
    customer c[5];
    cout << "Banking system for " << n << " students created successfully...\n\n";
    cout << "Enter details of customers\n\n";
    for (int i = 0; i < n; i++)
    {
        c[i].get_customer();
    }
    cout << "customers added successfully...\n\n";

    // c.get_customer();
    while (1)
    {
        cout << "press 1 to login\n";
        cout << "press 2 to exit\n";
        cout << "Enter your choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter account no.\n";
            cin >> acc;
            cout << "enter password\n";
            cin >> pwd;
            for (int i = 0; i < n; i++)
            {
                if (c[i].verify(acc, pwd))
                {
                    a = i;
                    b = true;
                    cout << "login access granted...\n";
                    break;
                }
            }
            if (!b)
            {
                cout << "no account found\n";
            }
            else
            {
                c[a].get_transaction();
                // c[a].store_customer_details();
                b = false;
            }
        }

        break;
        case 2:
            exit(1);

        default:
            cout << "Invalid choice\n";
            break;
        }
    }

    // c.get_transaction();
    // c.show_customer();

    getch();
    return 0;
}