#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "vba.h"
#include "rwvba.h"
#include "weak_eq.h"
#include "wr_weak_eq.h"

int main()
{
	int d=0;
	int b=0;
	//input type
	std::cin>>b;
	//input variables
	std::cin>>d;
	int n =0;
	//for bva
	if(b==1)
	{
		n=5;
	}
	//for worstcase robust bva
	if(b==2)
	{
		n=7;
	}
	//counters
	int current=0;
	int minminus=0;
	// vector of vector initialization for bva and worstcase robust bva
	std::vector<std::vector<int>> v(d, std::vector<int>(n));
	//temporary vector
	std::vector<int>  temp(d);
	//vector of vectors for both equivalence class testing
	std::vector <std::vector<int>>w(d);
	std::string expression;
	std::cin.ignore();
	//Loop for iterating over variables
	for(int i=0;i<d;i++)
	{
		//taking expression from getline
		std::getline(std::cin,expression);
		if(b==1)
		{
			vba a;
			//call for vector generation
			v=a.calvba(v,expression,i);
			
			if(i==d-1)
			{
				//call for generation of testcases
				a.gentest_vba(v,d,temp);
			}
		}
		if(b==2)
		{
			rwvba a;
			//call for vector generation
			v=a.calrwvba(v,expression,i);
			if(i==d-1)
			{
				//call for generation of testcases
				a.gentest_rwvba(v,d,current,temp);
			}
		}
		if(b==3)
		{
			weak_eq a;
			//call for vector generation
			w=a.cal_weak_eq(w,expression,i);
			if(i==d-1)
			{
				//loop for counting regions
				size_t y=0;
				for (size_t k = 0; k < w.size(); k++)
				{
					if(w[k].size()>y)
					{
						y=w[k].size();
					}
				}
				//call for generation of testcases
				a.gentest_weak_eq(w,d,current,temp,y);
			}
		}
		if(b==4)
		{
			wr_weak_eq a;
			//call for vector generation
			w=a.cal_wr_weak_eq(w,expression,i,minminus);
		
			if(i==d-1)
			{
				//loop for counting regions
				size_t y=0;
				for (size_t k = 0; k < w.size(); k++)
				{
					if(w[k].size()>y)
					{
						y=w[k].size();
					}
				}
				y=y-2;
				//call for generation of testcases
				a.gentest_wr_weak_eq(w,d,temp,y);
			}
		}
	}
	return 0;
}
