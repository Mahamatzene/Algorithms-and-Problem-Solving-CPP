

#include <iostream>
#include <string>
using namespace std;

string ReadPassword()
{
    string password;

    cout << "Please enter a 3-Letter Password (all capital)?\n";
    cin >> password;
        
    return password;
}

bool GuessPassword(string Originalpassword)
{
    string word = "";
    int counter = 0;

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word += char(i);
                word += char(j);
                word += char(k);

                counter++;

                cout << "\nTrial [" << counter << "] : " << word << endl;

                if (word == Originalpassword)
                {
                     cout << "\n-------------------------------------\n";
                     cout << "password is : " << word << endl;
                     cout << "Found after " << counter << " trials";
                     cout << "\n-------------------------------------\n";

                     return true;
                }

                word = "";
            }
        }
    }
    return false;

    
}

int main()
{
    GuessPassword(ReadPassword());

    return 0;
}


