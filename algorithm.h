/**
	CS219_HW4
	algorithm.h
	Purpose: Header File for linked list
	@author Antonio M.H. Punzo
	@version 1.0 5/5/2015
	Compiled using g++ -o hw9 -Wall -Wextra CS219_Punzo/hw9/algorithm.h
*/


#include <iostream>
using namespace std;
/**
 * prefix_sum 
 * creates algorithm to recursively sum two sequential numbers 
 * the sums are put into a linked list.
 */
template<class InputIterator, class OutputIterator>
	OutputIterator prefix_sum(InputIterator begin, InputIterator end, OutputIterator result)
	{
		
		
		if(begin != end)
		{
			typename iterator_traits<InputIterator>::value_type data = *begin;
			*result = data;
			while(++begin != end)
			{
				data = data + *begin;
				*++result = data;
			}
			++result;
			
		}
		return result;
	
	};