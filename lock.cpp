l#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const char KEY = 'K';

void encrypt(string file) {
	ifstream in(file, ios::binary);	
	if (in.fail()) {
		cout << "\nCannot read file.";
		return;
	}
	vector<char> buf((istreambuf_iterator<char>(in)), (istreambuf_iterator<char>()));
	in.close();

	ofstream out(file, ios::binary);	
	if (out.fail()) {
		cout << "\nCannot create file.";
		return;
	}
	
		
	for (auto it = buf.begin(); it != buf.end(); ++it)
	{	
		out << (char)((*it) ^ KEY);	
	}

	out.close();
}

int main(int argc, char** argv)
{			
	if (!argv[1]) cout << "\nPlease enter the file name.";
	else encrypt(argv[1]);		
	cout << "\nDone" << endl;	
    return 0;
}

