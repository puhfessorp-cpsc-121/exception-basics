#include <iostream>
#include <string>
#include "MyException.h"

using std::cout, std::cin, std::endl;
using std::string;

//Proto
bool f1_badWay(int i, string& error);
bool f2_badWay(int i, string& error);
bool f3_badWay(int i, string& error);
void f1_goodWay(int i);
void f2_goodWay(int i);
void f3_goodWay(int i);

int main()
{
	//
	bool success;
	string error;
	
	//	Try the bad way with 1
	error = "";
	success = f1_badWay(1, error);
	cout << "Bad way; Result with 1: " << (success ? "Success" : "Fail ==> " + error) << endl;
	
	//	Try the bad way with 4
	error = "";
	success = f1_badWay(4, error);
	cout << "Bad way; Result with 4: " << (success ? "Success" : "Fail ==> " + error) << endl;
	
	//	Try the good way with a few different values
	for ( int i = 0; i < 10; i++ )
	{
		cout << "Good way; Result with " << i << ": ";
		try
		{
			f1_goodWay(i);
			cout << "Success!";
		}
		catch(const std::runtime_error& e)
		{
			cout << "Runtime error ==> " << e.what();
		}
		catch(const MyException& e)
		{
			cout << "!!!MyException!!! ==> " << e.what();
		}
		cout << endl;
	}
	
	return 0;
}

bool f1_badWay(int i, string& error)
{
	if ( !f2_badWay(i + 1, error) ) {
		error = "f1_badWay failed to call f2_badWay :: " + error;
		return false;
	}
	
	return true;
}

bool f2_badWay(int i, string& error)
{
	if ( !f3_badWay(i + 1, error) ) {
		error = "f2_badWay failed to call f3_badWay :: " + error;
		return false;
	}
	
	return true;
}

bool f3_badWay(int i, string& error)
{
	if ( i > 5 ) {
		error = "f3_badWay doesn't work with a value over 5";
		return false;
	}
	
	return true;
}

void f1_goodWay(int i)
{
	f2_goodWay(i + 1);
}

void f2_goodWay(int i)
{
	f3_goodWay(i + 1);
}

void f3_goodWay(int i)
{
	if ( i > 7 ) {
		throw MyUncaughtException("I can't even believe you", i);
	}
	else if ( i > 6 ) {
		throw MyException("You are seriously out of control!", i);
	}
	else if ( i > 5 ) {
		throw std::runtime_error("f3_goodWay doesn't work with a value over 5");
	}
}




