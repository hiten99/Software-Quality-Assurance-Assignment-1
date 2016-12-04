#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "wr_weak_eq.h"
wr_weak_eq::wr_weak_eq()
{
}

wr_weak_eq::~wr_weak_eq()
{
}
std::vector<std::vector<int>> wr_weak_eq::cal_wr_weak_eq(std::vector<std::vector<int>> & v, std::string expression,int vcount,int & minminus)
{
	//loop for removing space
	for (size_t i = 0; i < expression.length(); i++)
	{
		if(expression[i] == ' ')
		{
			expression.erase(i, 1);
		}
	}
	//splitting in tokens
	std::istringstream ss(expression);
	std::string token;

	int min=0;
	int max=0;
	int nom=0;
	int k=0;
	int j=0;
	int maxplus=0;
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
				//assign value of minminus
				if(k==0)
				{
					minminus=min-1;
					k++;
				}
				j++;
			}
			else if (token[i]=='(')
			{
				token.erase(i, 1);
				min=stoi(token)+1;
				if(k==0)
				{
					//assign value of minminus
					minminus=min-1;
					k++;
				}
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
	//assign value of maxplus
	maxplus=max+1;
	//pushing values of minminus and maxplus to vector
	v[vcount].push_back(minminus);
	v[vcount].push_back(maxplus);
	
return v;
}
void wr_weak_eq:: gentest_wr_weak_eq(std::vector<std::vector<int>> & v,int & count,  std::vector<int> & temp, size_t & p)
{
	//loop for valid region values 
	//In the end last two values of each row are invalid and hence did two loops for valid and invalid values
	//loop for partitions
	for (int i = 0; i <p; i++)
	{
		//loop for no of variables
		for (int j = 0; j <count ; j++)
		{		
			if (i<=v[j].size()-3)
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

	for (int i = 0; i < count; i++)
	{
		temp[i]=v[i].at(0);
	}
	
//loop for invalid region values

	for (int i = 0; i < count; i++)
	{
		for (size_t j = v[i].size()-2; j <v[i].size() ; j++)
		{
			temp[i]=v[i].at(j);
			for (size_t k = 0; k < temp.size(); k++)
			{
				std::cout<<temp[k]<<" ";
			}
				std::cout<<"\n";
		}
		temp[i]=v[i].at(0);
	}
}
