#pragma once
#include <iostream>
#include <string>
using namespace std;

class FullException
{
private:
	string msg;
public:
	FullException(string);
	string what();
};

