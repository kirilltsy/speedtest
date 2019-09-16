#include <chrono>
#include <iostream>
#include <math.h>

using namespace std::chrono;
const int MAXITER = 100000000;
const int COUNT = 7;

template<typename T>
void f(int &a,float &b,int p);
void fp();

int main(){
	fp();
	for(int i=0; i<80;i++){
		std::cout<<"#";
	}
	std::cout<<"\n";
	auto start = high_resolution_clock::now();
	fp();
	auto end = high_resolution_clock::now();
	for(int i=0; i<80;i++){
		std::cout<<"#";
	}
	std::cout<<"\n";
	std::cout<<int(duration_cast<seconds>(end - start).count())<<" sec";	
	return 0;
}

void fp(){
	int a;
	float b;
	f<int>(a,b,1);
	std::cout<<"int     + "<<a<<"\t\t\t"<<b<<"\n";
		f<int>(a,b,2);
	std::cout<<"int     - "<<a<<"\t\t\t"<<b<<"\n";
		f<int>(a,b,3);
	std::cout<<"int     * "<<a<<"\t\t\t"<<b<<"\n";
		f<int>(a,b,4);
	std::cout<<"int     / "<<a<<"\t\t\t"<<b<<"\n";
		f<float>(a,b,1);
	std::cout<<"float   + "<<a<<"\t\t\t"<<b<<"\n";
		f<float>(a,b,2);
	std::cout<<"flaot   - "<<a<<"\t\t\t"<<b<<"\n";
		f<float>(a,b,3);
	std::cout<<"float   * "<<a<<"\t\t\t"<<b<<"\n";
		f<float>(a,b,4);
	std::cout<<"float   / "<<a<<"\t\t\t"<<b<<"\n";
		f<char>(a,b,1);
	std::cout<<"char    + "<<a<<"\t\t\t"<<b<<"\n";
		f<char>(a,b,2);
	std::cout<<"char    - "<<a<<"\t\t\t"<<b<<"\n";
		f<char>(a,b,3);
	std::cout<<"char    * "<<a<<"\t\t\t"<<b<<"\n";
		f<char>(a,b,4);
	std::cout<<"char    / "<<a<<"\t\t\t"<<b<<"\n";
	f<double>(a,b,1);
	std::cout<<"double  + "<<a<<"\t\t\t"<<b<<"\n";
		f<double>(a,b,2);
	std::cout<<"double  - "<<a<<"\t\t\t"<<b<<"\n";
		f<double>(a,b,3);
	std::cout<<"double  * "<<a<<"\t\t\t"<<b<<"\n";
		f<double>(a,b,4);
	std::cout<<"double  / "<<a<<"\t\t\t"<<b<<"\n";
	f<long>(a,b,1);
	std::cout<<"long    + "<<a<<"\t\t\t"<<b<<"\n";
		f<long>(a,b,2);
	std::cout<<"long    - "<<a<<"\t\t\t"<<b<<"\n";
		f<long>(a,b,3);
	std::cout<<"long    * "<<a<<"\t\t\t"<<b<<"\n";
		f<long>(a,b,4);
	std::cout<<"long    / "<<a<<"\t\t\t"<<b<<"\n";

}


template<typename T>
void f(int &a,float &b,int p){
	int res[COUNT];
	for (int j=0; j<COUNT;j++){
	T a = 1;
	int b = MAXITER;
	T c = 4;
	int y;
	if(p==1){	auto start = high_resolution_clock::now();
	for (int i = 1; i<b; i++){
		a = a + c;
	}
	auto end = high_resolution_clock::now();
		y = int(duration_cast<nanoseconds>(end - start).count());}
	else if(p==2){	auto start = high_resolution_clock::now();
	for (int i = 1; i<b; i++){
		a = a - c;
	}
	auto end = high_resolution_clock::now();
y = int(duration_cast<nanoseconds>(end - start).count());}
	else if(p==3){	auto start = high_resolution_clock::now();
	for (int i = 1; i<b; i++){
		a = a * c;
	}
	auto end = high_resolution_clock::now();
y = int(duration_cast<nanoseconds>(end - start).count());}
	else{	auto start = high_resolution_clock::now();
	for (int i = 1; i<b; i++){
		a = a / c;
	}
	auto end = high_resolution_clock::now();
y = int(duration_cast<nanoseconds>(end - start).count());}
	res[j] = (1000000000.0/ y)*MAXITER;
	}
	long long resabs = 0;
	for(int j=0; j<COUNT; j++){
		resabs += res[j];
	}
	resabs /= COUNT;
	int err = 0;
	for(int j=0; j<COUNT; j++){
		if(abs(res[j]-resabs)>err){
			err = abs(res[j]-resabs);
		}
	}
	a = resabs;
	b = (1.0*err)/resabs;
}