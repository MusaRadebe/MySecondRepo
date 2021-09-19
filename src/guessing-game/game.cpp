#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    auto recorded_num = ((rand()%100)+1);
    auto input = 0;

    cout << "Enter a number: "<<endl;

    for(int i=0; i<5; i++)
    {
        cin >> input;

        if(input > recorded_num && i != 4)
            cout << "Guess Lower" <<endl;
        else if(input < recorded_num && i != 4)
            cout << "Guess Higher" <<endl;
        else if (input == recorded_num)
        {
            cout << "You Win!" << endl;
            return 0;                       ///If the user wins, terminate the program here.
        }
    }

    cout << "You Lose! " << endl;

    return 0;
}