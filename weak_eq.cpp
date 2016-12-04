#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include"weak_eq.h"
weak_eq::weak_eq()
{
}

weak_eq::~weak_eq()
{
}


std::vector<std::vector<int>> weak_eq::cal_weak_eq(std::vector<std::vector<int>> & v, std::string expression,int vcount)
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
	int nom=0;
	
	int j=0;
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
				j++;
			}
			else if (token[i]=='(')
			{
				token.erase(i, 1);
				min=stoi(token)+1;
				j++;
			}
			if (token[i]==']')
			{
				token.erase(i, 1);
				max=stoi(token);
				j++;
			}
			else if (token[i]==')')
			{
				token.erase(i, 1);
				max=stoi(token)-1;
				j++;
			}
			// when min and max exists considering the middle value of range
			if(j%2==0 && min!=0 && max!=0)
			{
				nom=(min+max)/2;
				//pushing middle value of range to vector
				v[vcount].push_back(nom);
			}	
		}
	}
	
	
return v;

}
	
	
	
	
	
	
	
void weak_eq :: gentest_weak_eq(std::vector<std::vector<int>> & v,int & count, int & current, std::vector<int> & temp,size_t & p)
{
		
	//loop for partition	 
	for (size_t i = 0; i <p; i++)
	{
		//loop for no of variables and prints the outputs
		for (int j = 0; j <count ; j++)
		{
			if (i<=v[j].size()-1)
			{
				std::cout<<v[j].at(i)<<" ";
			}
			else
			{
				std::cout<<v[j].at(0)<<" ";
			}
		}
		std::cout<<"\n";
	}
	
	}