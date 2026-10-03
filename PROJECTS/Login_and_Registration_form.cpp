#include<iostream>
#include<fstream>
using namespace std;

class temp
{
    string username;
    string email;
    string password;
    fstream file;
    string searchname;
    string searchpassword;
    string searchemail;

public:
    void login();
    void signup();
    void forget();
}obj;

int main()
{
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.signup();
        break;
    case '3':
        cin.ignore();
        obj.forget();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "Invalid Choice..........";
    }

}

void temp :: signup()
{
    cout << "===========================" << endl;
    cout << "-------- Sign-Up ----------" << endl;
    cout << "===========================" << endl;
    cout << "\nEnter Your User Name: ";
    getline(cin, username);
    cout << "Enter Your Email Address: ";
    getline(cin, email);
    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("logindata.txt", ios :: out | ios :: app);
    file<<username<<" * "<<email<<" * "<<password<<" * "<<endl;
    file.close();
}

void temp :: login()
{
    string searchname;
    string searchpassowrd;
    cout << "===========================" << endl;
    cout << "---------- LOGIN ----------" << endl;
    cout << "===========================" << endl;
    cout << "Enter Your User Name: " << endl;
    getline(cin, searchname);
    cout << "Enter Your Password: " << endl;
    getline(cin, searchpassword);

    file.open("logindata.txt", ios :: in);
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    while(!file.eof())
    {
        if(username == searchname)
        {
            if(password == searchpassword)
            {
                cout << "--------------------------------------" << endl;
                cout << "\nAccount Loged in .........." << endl;
                cout << "Username: " << username << endl;
                cout << "Email: " << email << endl;
                cout << "Password: " << password << endl;
                cout << "--------------------------------------" << endl;
            }
        }
        else 
        {
            cout << "----------------------------------" << endl;
            cout << "Username / Password is not correct." << endl;
            cout << "----------------------------------" << endl;
        }
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    }
    file.close();
}

void temp :: forget()
{
    cout << "\nEnter Your Username: " << endl;
    getline(cin, searchname);
    cout << "Enter Your Email Address: " << endl;
    getline(cin, searchemail);

    file.open("logindata.txt", ios :: in);
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    while(!file.eof())
    {
        if(username == searchname)
        {
            if(email == searchemail)
        {
            cout << "\nAccount Found...." << endl;
            cout << "Your Password is: " << password << endl;
        }
            else
        {
            cout << "Not Found......" << endl;
        }
        }
        else
        {
            cout << "Not Found......." << endl;
        }

        file.close();
    }


}