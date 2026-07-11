#include <iostream>
#include <vector>
using namespace std;

string JoinVeector(vector<string> vName, string delim) {

    string afterJoin = "";

    for (string& name : vName) {

        afterJoin += name + delim;
    }

    return afterJoin.substr(0, afterJoin.length() - delim.length());
}

int main()
{
    vector<string> vName = { "zain", "mohammed", "saleh" };

    cout << "Vector after join" << endl;
    cout << JoinVeector(vName, " ") << endl;

    return 0;
}

