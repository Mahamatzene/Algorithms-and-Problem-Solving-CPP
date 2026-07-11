

#include <iostream>
using namespace std;


string ReadPinCode()
{
    string pinCode;

    cout << "please enter your pin code" << endl;
    cin >> pinCode;

    return pinCode;
}

bool login()
{
    string pinCode;

    do
    {
        pinCode = ReadPinCode();

        if (pinCode == "1234")
        {
            return 1; //this will exit the function and return true
        }
        else
        {
            cout << "\n wrong pin code}\n";
            system("color 4F"); //turn scrren to red
        }
        
    } while (pinCode != "1234");

    return 0; //when you reach here this means login faild
}

int main()
{
    if (login())
    {
        system("color 6F");
        cout << "your balance is : " << 7500 << endl;
   }

    return 0;
}


