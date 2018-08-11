/**
	CS219_HW4
	hw9_driver_punzo.cpp
	Purpose: Driver file for linked list program
	@author Antonio M.H. Punzo
	@version 1.0 5/5/2015
	Compiled using g++ -o hw9 -Wall -Wextra CS219_Punzo/hw9/hw9_driver_punzo.cpp
*/

#include <iostream>
#include "inkisthw8_punzo.h"
#include <string>
#include <list>
#include <numeric>
#include "algorithm.h"
using namespace std;
int main()
{
	
	
	inkist<int>::Iterator iter;
	inkist<int> redfish;
	list<int>::iterator iter1;
	list<int> stlList;
	
	for (int i=1; i<10; i++) 
	{redfish.push_back(i);}
	cout << "redfish list before sum" << endl;
	
	//List before sum algorithm
	for(iter=redfish.begin(); iter!=redfish.end();iter++)
	{
		cout << *iter << endl;
	}
	//List after using STL partial sum algorithm
	partial_sum(redfish.begin(), redfish.end(), redfish.begin());
	cout << "redfish using STL partial sums" << endl;
	for(iter=redfish.begin(); iter!=redfish.end();iter++)
	{
		cout << *iter << endl;
	}
	
	for (int j=1; j<10; j++) 
	{stlList.push_back(j);}
	//STL list before prefix sum algorithm
	cout << "STL before prefix_sum" << endl;
	for(iter1=stlList.begin(); iter1!=stlList.end();iter1++)
	{
		cout << *iter1 << endl;
	}
	//STL after prefix sum algorithm
	prefix_sum(stlList.begin(), stlList.end(), stlList.begin());
	cout << "STL after prefix_sum" << endl;
	for(iter1=stlList.begin(); iter1!=stlList.end();iter1++)
	{
		cout << *iter1 << endl;
	}
	
	
	
	
	
	return 0;
}