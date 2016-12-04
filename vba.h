#ifndef _CS590_VBA_H
#define _CS590_VBA_H

class vba
{
public:
	/// Default constructor.
	vba();
	/// Default destructor.
	~vba();
	/// function for parsing expression and returns vector of vector
	std::vector<std::vector<int>> calvba(std::vector<std::vector<int>> & v, std::string expression,int vcount);
	///function for generating testcase of bva
	void gentest_vba(std::vector<std::vector<int>> & v,int & count, std::vector<int> & temp);
private:

};
#endif  // !defined _CS590_VBA_H