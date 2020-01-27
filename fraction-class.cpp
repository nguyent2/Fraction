/* Fraction class
enhancements by Thy H. Nguyen
*/

#include <iostream>
using namespace std;

int gcd(int m, int n) {
	/* Find the gcd of the 2 number m and n, m is the nominator and n is the denominator
	The gcd is the largest natural number that is both divisible by the nominator and denominator
	While the nominator is not divisible by the denominator (which means the remaining is not 0)
	the old denominator will be turned into the new nominator, and the remaining of the modulus between the old nominator and the old denominator 
	will be assigned to n.
	The loop will continue if the new nominator is not divisible by the new denominator.
	This function returns the value of n, which is the largest natural number that is both divisible by the nominator and the denominator
		*/
	while (m%n != 0) {
		int oldm = m;
		int oldn = n;

		m = oldn;
		n = oldm % oldn;
	}
	return n;
}

class Fraction {  // begin declaration of the Fraction class
	/*
	This class creates the fraction
	and then doing the fraction addition
	*/
	public:  // begin public section
		Fraction(int top = 0, int bottom = 1) {  //default constructor
			int common = gcd(top, bottom);			//reduce the top and bottom
			num = top/common; //save the top parameter to the numerator
			den = bottom/common; //save the bottom parameter to the denomerator
		}


		friend ostream &operator<<(ostream &stream, const Fraction &frac); 
		friend bool operator ==(const Fraction &frac1, const Fraction &frac2);
		friend bool operator !=(const Fraction& frac1, const Fraction& frac2);
		friend Fraction operator +(const Fraction &frac1, const Fraction &frac2);
		friend Fraction operator -(const Fraction& frac1, const Fraction& frac2);
		friend Fraction operator *(const Fraction& frac1, const Fraction& frac2); 
		friend Fraction operator /(const Fraction& frac1, const Fraction& frac2);

	private:  // private section
		int num, den;
};

Fraction operator +(const Fraction &frac1, const Fraction &frac2) {
	/*
	this is adding two fractions by getting the common denominator
	*/
	int newnum = frac1.num * frac2.den + frac1.den * frac2.num;
	int newden = frac1.den * frac2.den;
	//int common = gcd(newnum, newden);
	//return Fraction(newnum / common, newden / common);
	//does not need to reduce here anymore since it is already in the constructor
	return Fraction(newnum, newden);
}	

Fraction operator -(const Fraction& frac1, const Fraction& frac2) {
	/*
	this is subtracting two fractions by getting the common denuminator
	*/
	int newnum = frac1.num * frac2.den - frac1.den * frac2.num;
	int newden = frac1.den * frac2.den;
	//int common = gcd(newnum, newden);
	//return Fraction(newnum / common, newden / common);
	//does not need to reduce here anymore since it is already in the constructor
	return Fraction(newnum, newden);
}

Fraction operator *(const Fraction& frac1, const Fraction& frac2) {
	/*
	this is multiplying two fractions by getting multiplying nominators together, and denominators together
	*/
	int newnum = frac1.num * frac2.num;
	int newden = frac1.den * frac2.den;
	//int common = gcd(newnum, newden);
	//return Fraction(newnum / common, newden / common);
	//does not need to reduce here anymore since it is already in the constructor
	return Fraction(newnum, newden);
}
Fraction operator /(const Fraction& frac1, const Fraction& frac2) {
	/*
	this is dividing the two fractions by getting the first fraction multiplying the reciprocal of the second fraction
	*/
	int newnum = frac1.num * frac2.den;
	int newden = frac1.den * frac2.num;
	//int common = gcd(newnum, newden);
	//return Fraction(newnum / common, newden / common);
	//does not need to reduce here anymore since it is already in the constructor
	return Fraction(newnum, newden);
}

bool operator ==(const Fraction &frac1, const Fraction &frac2) {
	/*
	this is comparing the nominator and the denominator
	*/

	return  (frac1.num == frac2.num && frac1.den == frac2.den);
}

bool operator !=(const Fraction& frac1, const Fraction& frac2) {
	/*
	this is comparing the nominator and the denominator
	*/
	return  (frac1.num != frac2.num || frac1.den != frac2.den);
}
	
ostream &operator<<(ostream &stream, const Fraction &frac) { //get the operator reference into the stream, before that get the stream and reference into ostream. 
	// This function just add the slash ("/") between the nominator and the denominator so that they look like fraction, and are in fraction form.
	//constant the fraction class and reference frac.
	stream << frac.num << "/" << frac.den;
	return stream; // return the stream
}

int main() {
	char enterme;
	int numerator, denominator;

	cout << "Demo use of the constructors & operator overloading." << endl;
	Fraction f1; // make the default fraction 0/1
	cout << "f1 = " << f1 << endl;
	Fraction f2(1, 4); // make the fraction with nominator 1 and denominator 4
	cout << "f2 = "<< f2 << endl;
	Fraction f3 = f1 + f2; // add the two fraction
	cout << "f3 is f1 + f2 = " << f3 << endl;
	Fraction f4 = f2 + f2; // add the fraction f2 twice
	cout << "f4 is f2 + f2 = " << f4 << endl;
	
	Fraction f6 = f2 - f2; // testing fraction subtraction
	cout << "f6 is f2 - f2 = " << f6 << endl;
	Fraction f7 = f2 * f2; // testing fraction multiplication
	cout << "f7 is f2 * f2 = " << f7 << endl;
	Fraction f8 = f2 / f2; // testing fraction division
	cout << "f8 is f2 / f2 = " << f8 << endl;
	Fraction f9 = f2 == f2; // testing fraction equality
	cout << "f9 is f2 == f2 = " << f9 << endl;
	Fraction f10 = f2 != f2; // testing fraction inequality
	cout << "f10 is f2 != f2 = " << f10 << endl;

	cout << "Enter numerator: ";
	cin >> numerator;
	cout << "Enter demoninator: ";
	cin >> denominator;
	Fraction f5(numerator, denominator);
	cout << "You entered = " << f5 << endl;

	cin >> enterme; //holds console open in some situations
	return 0;
}

