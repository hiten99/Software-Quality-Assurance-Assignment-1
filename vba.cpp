#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "vba.h"
vba::vba()
{
}

vba::~vba()
{
}

std::vector<std::vector<int>> vba:: calvba(std::vector<std::vector<int>> & v, std::string expression,int vcount)
{
	//loop for removing space		
	for (size_t i = 0; i < expression.length(); i++) {
		if(expression[i] == ' ')
        expression.erase(i, 1);
	}
	
	//splitting in tokens
	std::istringstream ss(expression);
	std::string token;
	int min=0;
	int max=0;

	//loop for removing comma(,)
	while(std::getline(ss, token, ','))
	{
		//considering every token
		for (size_t i = 0; i < token.length(); i++)
		{
			//calculating values of min and max for range
			if (token[i]=='[')
			{
				token.erase(i, 1);
				min=stoi(token);
			}
			else if (token[i]=='(')
			{
				token.erase(i, 1);
				min=stoi(token)+1;
			}
			if (token[i]==']')
			{
				token.erase(i, 1);
				max=stoi(token);
			}
			else if (token[i]==')')
			{
				token.erase(i, 1);
				max=stoi(token)-1;
			}
		}
	}
	//assigning values of minminus,min,minplus,nom,maxminus,max,maxplus.
	v[vcount][0]=min;
	v[vcount][1]=min+1;
	v[vcount][2]=(min+max)/2;
	v[vcount][3]=max-1;
	v[vcount][4]=max;

	return v;
}


void vba::gentest_vba(std::vector<std::vector<int>> & v,int & count, std::vector<int> & temp)
{
	//loop no of variables
	for (int i = 0; i < count; i++)
	{
		//loop for no of testcases
		for (size_t j = 0; j < 5; j++)
		{
			if (j!=2)
			{
				temp[i]=v[i].at(j);
			// loop for taking nom values
			for (int k = 0; k < count; k++)
			{
				if (k!=i)
				{
					temp[k]=v[k].at(2);
				}
			}
			//loop for printing vector
			for (size_t s = 0; s < temp.size(); s++)
			{
				std::cout<<temp[s]<<" ";
				}
			std::cout<<"\n";
			}
		}
	}
	//loop for printing nom nom values
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout<<v[i].at(2)<<" ";
	}
	std::cout<<"\n";

}