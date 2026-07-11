

#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber() {
    int number = 0;

    cout << "Please enter number : ";
    cin >> number;

    return number;
}

string ConvertNumberToText(long long int number)
{
    if (number == 0)
        return "";

    if (number >= 1 && number <= 19) {
        string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

        return arr[number] + " ";
    }

    if (number >= 20 && number <= 99) {
        string arr[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

        return arr[number / 10] + " " + ConvertNumberToText(number % 10);
    }

    if (number >= 100 && number <= 199) {
        return "One Hundred " + ConvertNumberToText(number % 100);
    }

    if (number >= 200 && number <= 999) {
        return ConvertNumberToText(number / 100) + "Hundreds " + ConvertNumberToText(number % 100);
    }

    if (number >= 1000 && number <= 1999) {
        return "One Thousand " + ConvertNumberToText(number % 1000);
    }

    if (number >= 2000 && number <= 999999) {
        return ConvertNumberToText(number / 1000) + "Thousands " + ConvertNumberToText(number % 1000);
    }

    if (number >= 1000000 && number <= 1999999) {
        return "One Million " + ConvertNumberToText(number % 1000000);
    }

    if (number >= 2000000 && number <= 999999999) {
        return ConvertNumberToText(number / 1000000) + "Millions " + ConvertNumberToText(number % 1000000);
    }

    if (number >= 1000000000 && number <= 1999999999) {
        return "One Billion " + ConvertNumberToText(number % 1000000000);
    }
    else {
        return ConvertNumberToText(number / 1000000000) + "Billions " + ConvertNumberToText(number % 1000000000);
    }
}

int main()
{
    long long int number = ReadPositiveNumber();
    cout << ConvertNumberToText(number) << endl;

    return 0;
}