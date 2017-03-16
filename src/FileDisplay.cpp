#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv)
{
	string path;
	char buf[256];
	if(1 == argc)
		path = "input/result.csv";
	else
		path = argv[1];

	cout<<path<<endl;

	if(0 != access(path.data(), 0))
	{
		cout<<path<<" does not exist."<<endl;
		return 1;
	}

	ifstream input_file(path.data(), ifstream::in);


	while(!input_file.eof())
	//while(input_file.get(buf, '\n'))
	{
		input_file.get(buf, 256, '\n');
		cout<<buf<<endl;
	}

	//input_file.get(buf, 256, '\n');
	//cout<<buf<<endl;
/*
	char ch[256];
	while(input_file.get(ch, 256, '\n'))
	{
		cout<<ch<<end;
	}
*/
	input_file.close();
	return 0;
}
