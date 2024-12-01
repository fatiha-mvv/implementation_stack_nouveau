#pragma once
#include <iostream>
#include <string>
using namespace std;

class EmptyException
{
private:
	 string msg;
public:
	EmptyException(string msg);
	string what();
};

