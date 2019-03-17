// Chapter01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <boost/type_index.hpp>

using std::cout;
using boost::typeindex::type_id_with_cvr;

template<typename T>
void f(T param)
{
	cout << "T = "
		<< type_id_with_cvr<T>().pretty_name()
		<< "\n";

	cout << "parame = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< "\n";

	cout << "func = "
		<< __FUNCSIG__
		<< "\n";

	cout << "value = "
		<< param
		<< "\n\n";
}

template<typename T>
void c_f(const T param)
{
	cout << "T = "
		<< type_id_with_cvr<T>().pretty_name()
		<< "\n";

	cout << "parame = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< "\n";

	cout << "func = "
		<< __FUNCSIG__
		<< "\n";

	cout << "value = "
		<< param
		<< "\n\n";
}

template<typename T>
void r_f(T& param)
{
	cout << "T = "
		<< type_id_with_cvr<T>().pretty_name()
		<< "\n";

	cout << "parame = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< "\n";

	cout << "func = "
		<< __FUNCSIG__
		<< "\n";

	cout << "value = "
		<< param
		<< "\n\n";
}

template<typename T>
void c_r_f(const T& param)
{
	cout << "T = "
		<< type_id_with_cvr<T>().pretty_name()
		<< "\n";

	cout << "parame = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< "\n";

	cout << "func = "
		<< __FUNCSIG__
		<< "\n";

	cout << "value = "
		<< param
		<< "\n\n";
}

template<typename T>
void p_f(T* param)
{
	cout << "T = "
		<< type_id_with_cvr<T>().pretty_name()
		<< "\n";

	cout << "parame = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< "\n";

	cout << "func = "
		<< __FUNCSIG__
		<< "\n";

	cout << "value = "
		<< param
		<< "\n\n";
}

template<typename T>
void c_p_f(const T* param)
{
	cout << "T = "
		<< type_id_with_cvr<T>().pretty_name()
		<< "\n";

	cout << "parame = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< "\n";

	cout << "func = "
		<< __FUNCSIG__
		<< "\n";

	cout << "value = "
		<< param
		<< "\n\n";
}

template<typename T>
void u_r_f(T&& param)
{
	cout << "T = "
		<< type_id_with_cvr<T>().pretty_name()
		<< "\n";

	cout << "parame = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< "\n";

	cout << "func = "
		<< __FUNCSIG__
		<< "\n";

	cout << "value = "
		<< param
		<< "\n\n";
}

template<typename T, size_t N>
constexpr size_t arraySize(T (&)[N]) noexcept
{
	return N;
}

int main(int argc, char* argv[])
{
	int x = 10;
	const int cx = x;
	const int& rx = x;
	f(x);
	f(cx);
	f(rx);

	const char* const ptr = "const char const ptr";
	f(ptr);
	c_f(ptr);
	const char name[] = "const char const ptr";
	f(name);
	r_f(name);

	c_f(x);
	c_f(cx);
	c_f(rx);

	r_f(x);
	r_f(cx);
	r_f(rx);

	c_r_f(x);
	c_r_f(cx);
	c_r_f(rx);

	const int* px = &x;
	p_f(px);
	c_p_f(px);

	u_r_f(x);
	u_r_f(rx);
	u_r_f(cx);
	u_r_f(27);

	int keyValues[] = {0, 1, 2, 3};
	std::cout << "keyValues size:"
		<< arraySize(keyValues)
		<< std::endl;

	int mappedValues[arraySize(keyValues)];
	std::cout << "mappedValues size:"
		<< sizeof(mappedValues) / sizeof(mappedValues[0])
		<< std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
