#include "prime.h"

Prime::Prime() {
	this->name = name;
}

string Prime::genPrimes(const char* primeLimit)
{
	std::vector<int> primes;
    primes.push_back(2);
    for(int i=3; i < atoi(primeLimit); i++)
    {
        bool prime = true;
        for(unsigned int j = 0; j < primes.size() && primes[j]*primes[j] <= i; j++)
        {
            if(i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime) 
            primes.push_back(i);
    }

	string primeString;
	for (int x: primes) {
		primeString += to_string(x);
		primeString += ",";
	}
	cout << primeString;
	return primeString;
}
