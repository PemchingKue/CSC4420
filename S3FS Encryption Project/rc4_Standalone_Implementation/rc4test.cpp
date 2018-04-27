#include <iostream>
#include <string>
#include <fstream>
#include "rc4_enc.c"
#include "rc4_skey.c"
using namespace std;

void rc4Implementation(int argc, char* argv[]){
	
	string Key = argv[3];

	ifstream inFile(argv[1]);
	string data((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));
	
	//outfile implementation
	ofstream outFile;
	outFile.open(argv[2], ios::binary);

	RC4_KEY pkey;
	int dLength = data.size();
	unsigned char *buffer = (unsigned char*)malloc(dLength + 1);
	memset(buffer, 0, dLength + 1);

	RC4_set_key(&pkey, Key.length(), (const unsigned char*)Key.c_str());
	RC4(&pkey, dLength, (const unsigned char*)data.c_str(), buffer);

	string ret((char*)buffer, dLength);
	free(buffer);
	
	outFile.clear(); 
	outFile << ret;
	outFile.close();

	}

int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "Usage: [IN FILE] [OUT FILE] [PASSWORD]" << endl;
	}
	else if(argc == 2)
	{
		cout << "Sorry, please enter the output file name." << endl;
	}
	else if(argc == 3)
	{
		cout << "Sorry, you have to enter a password." << endl;
	}
	else if(argc > 4)
	{
		cout << "Sorry, you have entered too many arguments." << endl;
	}
	else
	{
		rc4Implementation(argc, argv);
		return 0;
	}
}


