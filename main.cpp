#include<conio.h>
#include<iostream>
#include<string>
using namespace std;


/* Mini Project - ATM
   -> Check Balance
   -> Cash withdraw
   -> User Details
   -> Update Mobile No.
*/

class ATM
{
private:
    long int accountNO;
    string name;
    double balance;
    int PIN;
    string mobileNO;
public:
    void setData(long int accountNO_a, string name_a, int PIN_a, double balance_a, string mobileNO_a)
    {
        accountNO = accountNO_a;
        name= name_a;
        balance = balance_a;
        mobileNO = mobileNO_a;
        PIN = PIN_a;
    }

    long int getAccountNO()
    {
        return accountNO;
    }

    string getName()
    {
        return name;
    }

    string getMobileNO ()
    {

        return mobileNO;
    }

    int getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }


    void setMobile( string mobNoPrev, string mobNoNew)
    {

        if(mobNoPrev == mobNoNew)
        {
            mobileNO = mobNoNew;
            cout<<endl<<"Successfully Updated Mobile no.";
            _getch();
        }
        else
        {
            cout << endl << "Incorrect !!! Old Mobile no";
            _getch();
        }

    }


    void cashWithdraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance)
        {
            balance -= amount_a;
            cout << endl << "Please Collect Your Cash";
            cout << endl << "Available Balance :" << balance;
            _getch();
        }
        else
        {
            cout << endl << "Invalid Input or Insufficient Balance";
            _getch();
        }
    }




};

int main()
{

    int choice = 0, enterPin ;
    long int enterAccountNo;

    system ("cls");

    ATM User;
    User.setData(123456, "Tim", 1111, 45000.666, "0123456");

    do
    {
        system("cls");

        cout<< endl <<"**** Welcome to My Bank ***** "<<endl;
        cout<< endl <<"Enter Your Account NO : " ;
        cin>> enterAccountNo;

        cout<< endl <<" Enter PIN : " ;
        cin>> enterPin;


        if((enterAccountNo == User.getAccountNO()) && (enterPin ==User.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");

                cout << endl << "**** Welcome to ATM *****" << endl;
                cout << endl << "Select Options ";
                cout << endl << "1. Check Balance";
                cout << endl << "2. Cash withdraw";
                cout << endl << "3. Show User Details";
                cout << endl << "4. Update Mobile no.";
                cout << endl << "5. Exit" << endl;
                cin >> choice;


                switch (choice)
                {
                case 1:
                    cout << endl << "Your Bank balance is :" << User.getBalance();

                    _getch();
                    break;


                case 2:
                    cout << endl << "Enter the amount :";
                    cin >> amount;
                    User.cashWithdraw(amount);

                    break;


                case 3:
                    cout << endl << "*** User Details are :- ";
                    cout << endl << "-> Account no" << User.getAccountNO();
                    cout << endl << "-> Name      " << User.getName();
                    cout << endl << "-> Balance   " << User.getBalance();
                    cout << endl << "-> Mobile No." << User.getMobileNO();

                    _getch();
                    break;


                case 4:
                    cout << endl << "Enter Old Mobile No. ";
                    cin >> oldMobileNo;
                    cout << endl << "Enter New Mobile No. ";
                    cin >> newMobileNo;

                    User.setMobile(oldMobileNo, newMobileNo);
                    break;


                case 5:
                    exit(0);

                default:
                    cout << endl << "Enter Valid Data !!!";
                }

            }
            while (1);
        }
        else
        {
            cout << endl << "User Details are Invalid !!! ";
            _getch();
        }



    }
    while (1);


    return 0;
}
