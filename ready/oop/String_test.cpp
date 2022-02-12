#include <iostream>
#include <string.h>
#include "String.h"

using namespace std;


int main()
{
	{
		String sa("hello");
		String sb(sa);
		
		String sc;
		sc = sb;

		cout << sa.get_c_str() << endl;
		cout << sb.get_c_str() << endl;
		cout << sc.get_c_str() << endl;
	}
	return 0;
}
