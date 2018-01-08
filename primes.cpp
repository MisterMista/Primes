#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

int main(void){

unsigned int amount;
unsigned int number = 2;
vector<unsigned int> primes;
bool numberGood = 1;

cout<<"Calculate n prime numbers:";
cin>>amount;

if (amount >= 1){
	primes.push_back(number);
	number = 3;
}

chrono::time_point<chrono::system_clock> start, end;

if (amount >= 2){
	start = chrono::system_clock::now();
	while(primes.size() < amount){
	//for(unsigned int i = 3; i <= amount; ++i){
		numberGood = 1;
		for (unsigned int j = 0; j < sqrt(double(primes.size())); ++j) {
			if (number % primes[j] == 0){
				numberGood = 0;
				break;
			}
		}
		if (numberGood){
			primes.push_back(number);
		}
		++number;
	}
	end = chrono::system_clock::now();
}
for (unsigned int i = 0; i < primes.size(); ++i){
	cout<<primes[i]<<"\n";
}
chrono::duration<double> elapsed_seconds = end-start;
cout<<"took "<<elapsed_seconds.count()<<"s"<<endl;
return 0;
}
