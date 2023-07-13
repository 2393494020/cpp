#include <iostream>
#include <string>

using namespace std;

// 泛型编程

#if 0
// 模板函数
template<typename T> // 等价于 template<class T>
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
	int x = 10;
	int y = 30;
	swap_<int>(x, y); // 自动推导数据类型 swap_(x, y);

	cout << "x = " << x << ", y = " << y << endl;

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

#endif


#if 0

class Stu
{
public:
	Stu(string id, int age) : _id(id), _age(age) {}
	// 1.操作符重载
	// bool operator == (Stu& y)
	// {
	// 	if (_id == y._id && _age == y._age)
	// 		return true;
	// 	else
	// 		return false;
	// }
	string _id;
	int _age;
};

template<typename T>
bool equals(T& x, T& y)
{
	if (x == y)
		return true;
	else
		return false;
}

// 2.为比较 Stu 单独写
template<> bool equals(Stu& x, Stu& y)
{
	if (x._id == y._id && x._age == y._age)
		return true;
	else
		return false;
}


int main(int argc, char const *argv[])
{
	Stu stu_x("1001", 18);
	Stu stu_y("1001", 18);
	bool result = equals(stu_x, stu_y);
	if (result)
		cout << "stu_x == stu_y" << endl;
	else
		cout << "stu_x != stu_y" << endl;
	return 0;
}

#endif


#if 0
// 模板类
template <class idType, class ageType = int>
class Stu
{
public:
	Stu(idType id, ageType age) : _id(id), _age(age) {}

	void dis()
	{
		cout << "id = " << _id << ", age = " << _age << endl;
		cout << "idType = " << typeid(_id).name() << ", ageType = " << typeid(_age).name() << endl;
	}
	
	idType _id;
	ageType _age;
};

int main(int argc, char const *argv[])
{
	Stu<int, int> stu_x(1001, 19);
	stu_x.dis();
	
	
	Stu<string> stu_y("小明", 19);
	stu_y.dis();
	
	return 0;
}

#endif

#if 0
class ElectricVehicle
{
public:
	void electricity_drive()
	{
		cout << "drived by electricity" << endl;
	}
};

class GasolineVehicle
{
public:
	void gasoline_drive()
	{
		cout << "drived by gasoline" << endl;
	}
};

// 模板类的成员函数到使用时才创建
template <class T>
class Vehicle
{
public:
	void electricity_drive()
	{
		obj.electricity_drive();
	}

	void gasoline_drive()
	{
		obj.gasoline_drive();
	}

	T obj;
};

int main(int argc, char const *argv[])
{
	Vehicle<ElectricVehicle> ev;
	ev.electricity_drive();
	
	Vehicle<GasolineVehicle> gv;
	gv.gasoline_drive();
	return 0;
}

#endif


#if 1
// 类模板对象做函数参数
template <class idType, class ageType = int>
class Stu
{
public:
	Stu(idType id, ageType age) : _id(id), _age(age) {}

	void dis()
	{
		cout << "id = " << _id << ", age = " << _age << endl;
		cout << "idType = " << typeid(_id).name() << ", ageType = " << typeid(_age).name() << endl;
	}
	
	idType _id;
	ageType _age;
};

// 1. 指定传入类型
void print_stu_str_int(Stu<string, int>& stu)
{
	stu.dis();
}

// 2. 参数模板化
template<typename idType, typename ageType>
void print_stu_t_t(Stu<idType, ageType>& stu)
{
	stu.dis();
}

// 3. 整个类模板化
template<typename T>
void print_stu_t(T& stu)
{
	stu.dis();
}

int main(int argc, char const *argv[])
{
	Stu<string, int> stu_a("小锋", 20);
	print_stu_str_int(stu_a);

	Stu<int> stu_b(1001, 21);
	print_stu_t_t(stu_b);
	
	Stu<string, string> stu_c("1002", "22");
	print_stu_t<Stu<string, string>>(stu_c);
	return 0;
}

#endif
