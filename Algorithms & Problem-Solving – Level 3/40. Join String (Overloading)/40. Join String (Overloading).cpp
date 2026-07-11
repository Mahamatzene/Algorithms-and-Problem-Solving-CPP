#include <iostream>
#include <vector>
using namespace std;

string JoinString(vector<string> vName, string delim) {

    string afterJoin = "";

    for (string& name : vName) {

        afterJoin += name + delim;
    }

    return afterJoin.substr(0, afterJoin.length() - delim.length());
}

string JoinString(string arrNames[], short arrlength, string delim) {
    string afterJoin = "";

    for (short i = 0; i < arrlength; i++) {

        afterJoin += arrNames[i] + delim;
    }

    return afterJoin.substr(0, afterJoin.length() - delim.length());
}

int main()
{
    vector<string> vName = { "zain", "mohammed", "saleh" };
    string arrNames[] = { "zain", "mohammed", "saleh" };

    cout << "Vector after join :" << endl;
    cout << JoinString(vName, " ") << endl;

    cout << "\nArray after join :" << endl;
    cout << JoinString(arrNames, 3, " ") << endl;

    return 0;
}

