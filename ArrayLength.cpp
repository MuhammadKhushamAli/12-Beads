#include<iostream>
using namespace std;

int ArrayLength(char Array[])
{
	int Length = 0;
	while (Array[Length] != '\0')
	{
		Length++;
	}
	return Length;
}