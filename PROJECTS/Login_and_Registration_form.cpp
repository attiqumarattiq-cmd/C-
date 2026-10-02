#include<iostream>
#include<fstream>
using namespace std;

class temp
{
    string username;
    string email;
    string password;
    fstream file;

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

        break;
    case '2':

        break;
    case '3':

        break;
    case '4':

        break;
    default:
        cout << "Invalid Choice..........";
    }

    return 0;
}

void temp :: signup()
{
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
    string searchpassword;
    cout << "---------- LOGIN ----------" << endl;
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
                cout << "\nAccount Login Succesful.........." << endl;
                cout << "Username: " << username << endl;
                cout << "Email: " << email << endl;
                cout << "Password: " << password << endl;
            }
        }
        else 
        {
            cout << "Username / Password is not correct." << endl;
        }
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    }
    file.close();

}