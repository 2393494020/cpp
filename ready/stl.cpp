#include <iostream>

using namespace std;

template<typename T>
void swap_(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
void select_sort(T arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				swap_(arr[i], arr[j]);
			}
		}
	}
}

template<typename T>
void print_arry(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
		if (i < len - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	char char_arr[] = { 'h', 'i', 'k', 'j', 'a', 'b', 'd', 'e', 'f', 'c', 'g' };
	// char char_arr[] = "hijkadbecfg";
	int len = sizeof(char_arr) / sizeof(char);

	select_sort(char_arr, len);
	print_arry(char_arr, len);

	int int_arr[] = { 10, 40, 20, 30, 90, 70, 50, 80, 60 };
	len = sizeof(int_arr) / sizeof(int);

	select_sort(int_arr, len);
	print_arry(int_arr, len);

	return 0;
}