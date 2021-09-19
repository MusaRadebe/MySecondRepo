// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	auto myScreen = Screen{6,6};

	myScreen.move(6,1);

	for(int i=0;i<6;i++)
    {
        myScreen.set('*');
        if(i==5)               ///On the last iteration, do not move the cursor up
            break;
        myScreen.up();
    }

    for(int i=0;i<2;i++)
    {
        myScreen.forward();
        myScreen.down();
        myScreen.set('*');
    }
     myScreen.forward();

    for(int i=0;i<2;i++)
    {
        myScreen.set('*');
        myScreen.up();
        myScreen.forward();
    }

    for(int i=0;i<6;i++)
    {
        myScreen.set('*');
        if(i==5)               ///On the last iteration, do not move the cursor down
            break;
        myScreen.down();
    }

	myScreen.display();
	cout << endl;

return 0;
}
