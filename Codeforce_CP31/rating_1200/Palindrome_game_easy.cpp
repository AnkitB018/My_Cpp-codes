#include <iostream>
#include <string>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n ;
        cin >> n;
        string s;
        cin >> s;

        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                zeros++;
        }

        if(zeros%2 == 0 || zeros == 1){
            cout<<"BOB"<<endl;
        }else{
            cout<<"ALICE"<<endl;
        }
        

    }

    return 0;
}