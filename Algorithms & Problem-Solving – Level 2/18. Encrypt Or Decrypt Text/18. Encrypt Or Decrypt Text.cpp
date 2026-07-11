
#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
    string text;


    cout << "please enter your name" << endl;
    getline(cin, text);

    return text;
}

string EncryptText(string text, short encryptionKey)
{
    for (int i = 0; i <= text.length(); i++)
    {
        text[i] = char((int)text[i] + encryptionKey);
    }

    return text;
}

string DecryptText(string text, short encryptionKey)
{
    for (int i = 0; i <= text.length(); i++)
    {
        text[i] = char((int)text[i] - encryptionKey);
    }

    return text;
}

int main()
{
    const short encryptionKey = 2;
    string text, textAfterEncryption, textAfterDecryption;

    text = ReadText();
    textAfterEncryption = EncryptText(text, encryptionKey);
    textAfterDecryption = DecryptText(textAfterEncryption, encryptionKey);

    cout << "\nText befor encryption : " << text << endl;
    cout << "\nText after encryption : " << textAfterEncryption << endl;
    cout << "\nText after decryption : " << textAfterDecryption << endl;

    return 0;

}


