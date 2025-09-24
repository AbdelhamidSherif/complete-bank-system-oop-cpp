
#include <iostream>
#include "clsLoginScreen.h"

using namespace std;

int main()
{

	//This link to explain why make this(https://programmingadvices.com/courses/1960017/lectures/44637161)
	
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }

  

	//system("pause > 0");

	return 0;


}
