#include <bits/stdc++.h>
using namespace std;

class String {
private:
	char* s;
	int size;

public:
	String(char*); // constructor
	~String(); // destructor
};

String::String(char* c)
{
	size = strlen(c);
	s = new char[size + 1];
	strcpy(s, c);
}
String::~String() { delete[] s; }

int main()
{
	String str = "Hello, World!";
	String myString(str);
	return 0;
}
