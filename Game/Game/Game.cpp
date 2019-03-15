#include "stdafx.h"
#include <string>
#include <iostream>
using namespace System;
bool Guess(int number) {
	static int target = -1;
	if (target == -1) {
		Random r;
		target = r.Next() % 100 + 1;
	}
	if (number == target)return true;
	return false;
}
int main(array<System::String ^> ^args)
{
	int i;
	std::cin >> i;
	if (Guess(i) == true)
		std::cout << "YES";
	else
		std::cout << "NO";
}