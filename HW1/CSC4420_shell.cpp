#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

using namespace std;

int main(){

string input;

do{
	
	cin>>input;
	
		if(input == "url"){

		cout<<"http://www.cs.wayne.edu/~lihao/Courses/CSC4420/"<<endl;

		}

		if(input == "hour"){
			
		cout<<"Time: 10:00am to 11:15am, Mon. Wed."<<endl;
		
		}
		
		if(input == "room"){
			
		cout<<"Classroom: State Hall 0125"<<endl;
		
		}
		
		if(input == "desp"){
			
		cout<<"Operating system is an essential sofeware layer to use various various computing devices. This course covers the basic components and design principles of modern operating systems, including process and thread, CPU scheduling, memory management, file system and others. This course also provides hand-on programming experiences of using Linux system calls, and design and implementation of a cloud-based file system."<<endl;
		
		}
		
		if(input == "text"){
			
		cout<<"Modern Operating Systems, 4/E , 4th Edition, Pearson, 2015."<<endl;
		
		}
		
		if(input == "ref"){
			
		cout<<"Operating System Concepts, 8th Edition, Wiley, 2008."<<endl;
		cout<<"Understanding the Linux Kernel, , 3rd Edition, O'Reilly Media, 2005."<<endl;
		cout<<"Advanced UNIX Programming , 2nd Edition, Addison-Wesley, 2004."<<endl;
		cout<<"Advanced Programming in the UNIX Environment 1st Edition , Addison-Wesley, 1992 or 3rd edition, 2013."<<endl;
		
		}
		
		if(input == "prof"){
			
		cout<<"Instructor: Lihao Xu"<<endl;
		
		}
		
		if(input == "pol"){
		
		cout<<"Office: Woodward 5057, Room 1401.1"<<endl;
		
		}
		
		if(input == "poh"){
		
		cout<<"Office Hours: 1:00pm to 2:00pm, Mon. and Wed."<<endl;
		
		}
		
		if(input == "pma"){
		
		cout<<"Email: lihao@wayne.edu"<<endl;
		
		}
		
		if(input == "ta"){
			
		cout<<"TAs: Sumukhi Chandrashekar, Rui Chen"<<endl;
		
		}
		
		if(input == "tol"){
		
		cout<<"Sumukhi Chandrashekar Office: 5057 Woodward, Room 3211"<<endl;
		cout<<"Rui Chen Office: 5057 Woodward, Room 2221 "<<endl;
		
		}
		
		if(input == "toh"){
		
		cout<<"Sumukhi Chandrashekar Office Hours: 11:15am to 12:15pm, Mon. and Wed. "<<endl;
		cout<<"Rui Chen Office Hours: 11:00AM -- 12:00PM, Tue., Thu., and Fri. "<<endl;
		}
		
		if(input == "tma"){
		
		cout<<"Sumukhi Chandrashekar Email: sumukhic@wayne.edu"<<endl;
		cout<<"Rui Chen Email: fb4138@wayne.edu"<<endl;
		
		}
		
		if(input == "history"){
			system("./history.sh");
		}
		
		if(input == "help"){
		
		cout<<"prompt"<<endl;
		cout<<"url"<<endl;
		cout<<"hour"<<endl;
		cout<<"room"<<endl;
		cout<<"desp"<<endl;
		cout<<"text"<<endl;
		cout<<"ref"<<endl;
		cout<<"prof"<<endl;
		cout<<"pol"<<endl;
		cout<<"poh"<<endl;
		cout<<"pma"<<endl;
		cout<<"ta"<<endl;
		cout<<"tol"<<endl;
		cout<<"toh"<<endl;
		cout<<"tma"<<endl;
		cout<<"history"<<endl;
		cout<<"help"<<endl;
		cout<<"exit"<<endl;
		
		}

}while (input != "exit");


return 0;

}

