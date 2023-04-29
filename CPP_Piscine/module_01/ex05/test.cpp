#include <string>
#include <iostream>

std::string test()
{
	return "My first pointer";
}

std::string test1()
{
	return "My second pointer";
}

void ShowPointer(std::string(*ptr)())
{
	std::cout << ptr() << std::endl;
}

void setPointer(std::string level)
{
	std::string newstr = level;
	ShowPointer(test);

}

int main()
{
	setPointer("test");

}