#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "rwvba.h"
rwvba::rwvba()
{
}

rwvba::~rwvba()
{
}

std::vector<std::vector<int>> rwvba::calrwvba(std::vector<std::vector<int>> & v, std::string expression,int vcount)
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
	v[vcount][0]=min-1;
	v[vcount][1]=min;
	v[vcount][2]=min+1;
	v[vcount][3]=(min+max)/2;
	v[vcount][4]=max-1;
	v[vcount][5]=max;
	v[vcount][6]=max+1;

return v;
}
void rwvba:: gentest_rwvba(std::vector<std::vector<int>> & v,int & count, int & current, std::vector<int> & temp)
{
	//recursive function for testcase generation and printing them
	for (int i = 0; i < 7; i++)
	{
		temp[current]=v[current].at(i);
		current++;
		if (current!=count)
	    {
			gentest_rwvba(v,count,current,temp);
	    }
		else
		{
			for (int j = 0; j < count; j++)
			{
				std::cout<<temp[j]<<" ";
			}
			std::cout<<"\n";
		}
		current--;
	}
}