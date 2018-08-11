/**
	CS_219_HW1
	CS_219_HW1_punzo.cpp
	Purpose: Simple Grocery Counter
	@author Antonio M.H. Punzo
	@version 1.0 2/3/2015
*/

#include <iostream>

using namespace std;

/**
	Class Counter
	Simple counter which increments by 1's, 10's, 100's and 1000's
	Maximum number accepted is 9999
	If number is over the max a message of overflow is given
*/
class Counter

{

public:

	Counter();
	/**
		Constructor for maximum value accepted
		@param m the maximum value accepted
	*/
	Counter(int m);
	
	void reset();	 //resets values to 0
	void incr1();	 //increases counter by 1
	void incr10();	 //increases counter by 10
	void incr100();	 //increases counter by 100
	void incr1000(); //increases counter by 1000

	/**
		used to check overflow
		@return true if overflow, false if no overflow
	*/
	bool overflow(); 
	/**
		Stores total value of counter
		@return value of counter
	*/
	int Value();

private:

	int num;	//times a letter is clicked
	int tot;	//total clicks of all letters
	int max;	//max number of clicks allowed
	bool over;	//condition for overflow check

};






//Controls operation of the program
int main()

{

	char letter;			  //initializes letter as a character
	Counter myCounter(9999);  //Creates new Counter called myCounter that accepts a max of 9999
	/**
		Output of instructions for end user of program
	*/
	cout << "Welcome to Simple Grocery Counter" << endl;
	cout << "This program will mimic a click counter" << endl;
	cout << "Each digit of the counter is represented by a letter" << endl;
	cout << "h=1000, j=100, k=10 and l=1."<< endl;
	cout << " Please click each letter the amount of times you want to count." << endl;
	cout << "For example if you wanted to add 342." << endl;
	cout << " click j 3 times, k 4 times and l 2 times." << endl;
	cout << "To reset the counter click r, when finished click e."<< endl;
	cout << "Once e is clicked your total will be displayed." << endl;
	cout << "If your number is greater than 9999 an overflow message will be displayed"<< endl;
	cout << "The  number displayed will be the amount over 9999 that your count was" << endl;

	/**
		Outputs the initial value of counter
	*/
	cout << myCounter.Value()  << endl;

/**
	Controls which letter is used to increase the count for each digit space
	while letter isn't e program will continue to increase count
	once user clicks e the total value accumulated will be displayed
	exits program when e is clicked
*/	
do
{
	cin >> letter;			//accepts input from user as character letter
	if(letter == 'h')		//increments the 1000's place each time h is clicked
	{
		myCounter.incr1000();
	}
	else if(letter =='j')	//increments the 100's place each time j is clicked
	{
		myCounter.incr100();
	}
	else if(letter == 'k')	//increments the 10's place each time k is clicked
	{
		myCounter.incr10();
	}
	else if(letter == 'l')	//increments the 1's place each time l is clicked
	{
		myCounter.incr1();
	}
	else if(letter == 'r')	//clears all values if r is entered and outputs 0
	{
		myCounter.reset();
		cout << myCounter.Value() << endl;
	}
	else				
	{
		cout << myCounter.Value() << endl;
	}
}
	while(letter != 'e');

	





	return 0;

}




Counter::Counter(int m)

{

	max = m;

	num = 0;
	tot = 0;
	over = false;
	return;

}



void Counter::reset()

{

	num = 0;
	tot = 0;
	return;

}



void Counter::incr1()

{

	if (num +1 >max)

	{
	  over = true;
	  num++;
	}

	else
	{
	   num++;
	}
	return;

}



void Counter::incr10()

{

	if (num + 10 >max)
	{
		over = true;
		num = num + 10;
	}
	else
	{
		num  = num + 10;

	}
	return;

}
void Counter::incr100()
{
	if (num + 100>max)
	{
	  over = true;
	  num = num + 100;
	}
	else
	{
		num  = num + 100;
	}
	return;
}

void Counter::incr1000()
{
	if(num + 1000 >max)
	{
	 over = true;
	 num = num + 1000;
	}
	else
	{
		num = num + 1000;
	}
	return;
}

bool Counter::overflow()

{
	return true;

}



int Counter::Value()

{
	if(over==true) 
	{
	   tot = num - max;
           cout << "Overflow" <<  endl;
	   over = false;
	}
	else
	{
	  tot = num;
	}
	return tot;

}
