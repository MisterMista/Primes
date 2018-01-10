#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

int main(void){

unsigned int amount;	//number of prime numbers to generate
unsigned int number = 2;	//reference of current number
vector<unsigned int> primes;	//vector that holds all the generated prime numbers
bool numberGood = 1;	//boolean that stores if number is prime

cout<<"Calculate n prime numbers:";
cin>>amount;

if (amount >= 1){	//the first prime number is added separately
	primes.push_back(number);
	number = 3;
}

chrono::time_point<chrono::system_clock> start, end;	//timer is initialized

if (amount >= 2){
	start = chrono::system_clock::now();	//timer is started
	while(primes.size() < amount){
	//for(unsigned int i = 3; i <= amount; ++i){	//old code
		numberGood = 1;
		for (unsigned int j = 0; j < sqrt(double(primes.size())); ++j) {
			if (number % primes[j] == 0){	//if the current number can be divided by any other prime, it is not prime
				numberGood = 0;
				break;
			}
		}
		if (numberGood){
			primes.push_back(number);
		}
		++number;
	}
	end = chrono::system_clock::now();	//stops timer
}
for (unsigned int i = 0; i < primes.size(); ++i){
	cout<<primes[i]<<"\n";
}
chrono::duration<double> elapsed_seconds = end-start;
cout<<"took "<<elapsed_seconds.count()<<"s"<<endl;
return 0;
}
