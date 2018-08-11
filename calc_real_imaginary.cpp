/**
	CS_219_HW1
	CS_219_HW2_punzo.cpp
	Purpose: Add, Subtract, Mutiply real and imaginary numbers
	@author Antonio M.H. Punzo
	@version 1.0 2/17/2015
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
/**
	Class for complex numbers 
*/
class Complex
{
/**
	Uses friend function to implement 
	overloading of operator +, -, *, ==, << and >>
*/
public:
	Complex( );
	Complex(double amount);
	Complex(double theReal, double theImag);
	double getAmount( ) const;
	double getReal( ) const;
	double getImag( ) const;
	void input( ); 
	void output( ) const;
	friend const Complex operator +( const Complex& amount1, const Complex& amount2);
	friend const Complex operator -( const Complex& amount1, const Complex& amount2);
	friend const Complex operator *( const Complex& amount1, const Complex& amount2);
	friend bool operator ==( const Complex& amount1, const Complex& amount2);
	friend const Complex operator -( const Complex& amount);
	friend ostream& operator << (ostream& outputStream,
							 const Complex& amount);
	friend istream& operator >> (istream& inputStream,
							 Complex& amount);
							 
private:
	double real; //real numbers
	double imag; //Imaginary numbers
	double realPart( double amount) const;
	double imagPart( double amount) const;

};
/**
	Calls Constructor Complex
	Runs test program using two predetermined complex numbers
	Test program calls overloaded +, -, *, ==, << and >> operators
	Displays the final complex number after it undergoes addition,
	subtraction, multiplication and comparison.
	Input program
	Accepts user input of 2 complex numbers
	Allows user to input operator to perform arithmetic
	Outputs the final complex number
*/
int main( )
{
	double c1, c2, c3, c4; //variables for user input
	char op;
	
	Complex complAmount1(3.3,-4.4), complAmount2(5.5, 6);

	//test program
	cout << "Complex number x =" << complAmount1 << endl;
	cout << "Complex number y =" << complAmount2 << endl;

	Complex complAmountTot = complAmount1 + complAmount2;
	cout << "x + y =" << complAmountTot << endl;

	Complex complAmountDiff = complAmount1 - complAmount2;
	cout << "x - y =" << complAmountDiff << endl;

	Complex complAmountMult = complAmount1 * complAmount2;
	cout << "x * y =" << complAmountMult << endl;

	if (complAmount1 == complAmount2)
		cout << "These are equal" << endl;
	else
		cout << "These are not equal" << endl;

//User Input program
	cout << "Enter a real number ";
	cin >> c1 ;
	cout << "Enter an imaginary number:";
	cin >> c2 ;
	cout << "Enter a real number:";
	cin >> c3 ;
	cout << "Enter an imaginary number:";
	cin >> c4 ;
	Complex complAmount3(c1,c2), complAmount4(c3,c4);
	cout << "Complex number a = " << complAmount3 << endl;
	cout << "Complex number b = " << complAmount4 << endl;
	cout << "Select an operator" << endl;
	cin >> op;
	if (op == '+')
	{
  		Complex complTot = complAmount3 + complAmount4;
		cout << "a + b =" << complTot << endl;
	}
	else if (op == '-')
	{
		Complex complTot = complAmount3 - complAmount4;
		cout << "a - b =" << complTot << endl;
	}
	else if (op == '*')
	{
		Complex complTot = complAmount3 * complAmount4;
		cout << "a * b =" << complTot << endl;
	}
	else
	{
		cout << "Not a valid operator" << endl;
	}
//if (complAmount3 == complAmount4)
//cout << "We have the same amounts.\n";
//else
//cout << "One of us is richer.\n";


return 0;
}

/**
	definition for overloaded operator <<
	responsible for output stream
*/
ostream& operator << (ostream& outputStream, const Complex& amount)
{
	outputStream << amount.real << "+" << amount.imag << "*i";	
	return outputStream;
}
/**
	definition for overloaded operator >>
	responsible for input stream
*/
istream& operator >> (istream& inputStream, Complex& amount)
{
	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.real = amount.realPart(amountAsDouble);
	amount.imag = amount.imagPart(amountAsDouble);
	return inputStream;
}
/**
	definition for overloaded operator +
	responsible for addition
*/
const Complex operator +( const Complex& amount1, const Complex& amount2)
{
	double allImag1 = amount1.getImag( );
	double allImag2 = amount2.getImag( );
	double finalImag = allImag1 + allImag2;
	double allReal1 = amount1.getReal( );
	double allReal2 = amount2.getReal( );
	double finalReal = allReal1 + allReal2;

	return Complex(finalReal, finalImag);
}

/**
	definition for overloaded operator -
	responsible for subtraction
*/
const Complex operator -( const Complex& amount1, const Complex& amount2)
{
	double allImag1 = amount1.getImag( );
	double allImag2 = amount2.getImag( );
	double finalImag = allImag1 - allImag2;
	double allReal1 = amount1.getReal( );
	double allReal2 = amount2.getReal( );
	double finalReal = allReal1-allReal2;

	
	return Complex(finalReal, finalImag);
}
/**
	definition for overloaded operator *
	responsible for multiplication
*/
const Complex operator *( const Complex& amount1, const Complex& amount2)
{
	double allImag1 = amount1.getImag( );
	double allImag2 = amount2.getImag( );
	double realNum2 = allImag1 * allImag2;//b*d
	double allReal1 = amount1.getReal( );
	double allReal2 = amount2.getReal( );
	double realNum1 = allReal1 * allReal2;//a*c
	

	double imagNum1 = allReal1 * allImag2;//a*d
	double imagNum2 = allReal2 * allImag1;//b*c
	double finalReal = realNum1 - realNum2;
	double finalImag = imagNum1 + imagNum2;
	return  Complex (finalReal, finalImag);
	 
	
}

/**
	definition for overloaded operator ==
	responsible for comparison
*/
bool operator ==( const Complex& amount1, const Complex& amount2)
{
	return ((amount1.getReal( ) == amount2.getReal( ))
	&& (amount1.getImag( ) == amount2.getImag( )));
}

const Complex operator -( const Complex& amount)
{
	return Complex(-amount.getReal( ), -amount.getImag( ));
}

Complex::Complex( ): real(0), imag(0)
{ /*Body intentionally empty.*/}

Complex::Complex (double amount)
: real(realPart(amount)), imag(imagPart(amount))
{ /*Body intentionally empty.*/	}


Complex::Complex(double theReal, double theImag)
{
	real=theReal;
	imag=theImag;
}

double Complex::getAmount( ) const
{
	return (real + imag);
}

double Complex::getReal( ) const
{
	return real;
}

double Complex::getImag( ) const
{
	return imag;
}

double Complex::realPart(double amount) const
{
	return real;
}

double Complex::imagPart(double amount) const
{
	return imag;
}
