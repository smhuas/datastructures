#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class myfile {
	
	std::vector<string> v;
	
public:	
	void readfile(string file);
	void showcontents();
	void search_string(string str);

};

void myfile::readfile(string file)
{
	std::ifstream fb(file, std::ios::in);
	std::string tmp;
	while (std::getline(fb, tmp))
	{
		v.push_back(tmp);
	}      	
    fb.close();	
}

void myfile::showcontents()
{
	cout<<"Displaying contents of vector \n\n";
	for(auto i:v)
	{
		cout<<i<<std::endl;
	}
}


void myfile::search_string(string str)
{
	int count = 0;
	int line = 0;
	for(auto i:v)
	{
		++line;
		size_t found = i.find(str);
		if (found != string::npos)
		{
			++count;
			cout<<"line is "<<line << "found "<<found<<endl;
		}
	}	
	cout<<"count is "<<count<<endl;
}