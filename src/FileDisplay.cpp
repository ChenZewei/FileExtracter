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
	string buf;
	if(1 == argc)
		path = "input/result-logs.csv";
	else
		path = argv[1];

	cout<<path<<endl;

	if(0 != access(path.data(), 0))
	{
		cout<<path<<" does not exist."<<endl;
		return 1;
	}

	ifstream input_file(path.data(), ifstream::in);

	while(getline(input_file, buf))
	{
		cout<<buf<<endl;
	}


	input_file.close();
	return 0;
}
