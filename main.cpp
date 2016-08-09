#include <cstdlib>
#include <stdlib.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct elem
{
    int honnan;
    int hova;
};

vector<elem> split(const string& s)
{
    vector<elem> result;
    bool honnan_ = true;
    string temp = "";
    elem tempelem;
    int i = 0;
    do
    {
	if (s[i] == ' ')
	{
	    if (honnan_)
	    {
		tempelem.honnan = atoi(temp.c_str());
		honnan_ = false;
		temp = "";
	    }
	    else
	    {
		tempelem.hova = atoi(temp.c_str());
		result.push_back(tempelem);
		honnan_ = true;
		temp = "";
	    }
	}else
	{
	    temp = temp + s[i];
	}
	i++;
    } while (i != s.size());
    
    tempelem.hova = atoi(temp.c_str());
    result.push_back(tempelem);
    return result;
}

void feldolgoz(const vector<elem>& e)
{
    static int db;
    for (int i = 0; i< e.size(); i++)
    {
	for(int j = 0; j<e.size(); j++)
	{
	    if (i != j)
	    {
		if (e[i].hova == e[j].hova)
		{
		    cout<< ++db <<": Nem Fa"<<endl;
		    return;
		}
	    }
	}
    }
    cout<< ++db << ": Fa"<<endl;
}

void beolvas(const string& file)
{
    string line;
    ifstream myfile (file.c_str());
    if (myfile.is_open())
    {
	vector<elem> elemek;
	getline (myfile,line);
	int N = atoi(line.c_str());
	for (int i = 0; i<N; i++)
	{
	   getline (myfile,line);
	   int db = atoi(line.c_str());
	   string temp = "";
	   getline (myfile,temp);
	   elemek = split(temp);
	   feldolgoz(elemek);
	}
	myfile.close();
    }
}


int main(int argc, char** argv) 
{
    beolvas("test.txt");
    return 0;
}

