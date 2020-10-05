/*
 * Program to check is give number is prime or not
 */
#include<iostream>
#include<bits/stdc++.h>
std::string isPrime(int n) {
	std::string notPrime = "not prime number";
	std::string prime = "prime number";
	for(int i=2;i<=sqrt(n);i++) {
		if(n%i  == 0) return notPrime;
	}
	return prime;
}
			
int main() {

	int n;
	std::cin>>n;

	std::cout<<"\n Given number "<<n <<" is "<<isPrime(n)<<"\n";

	return 0;
}
