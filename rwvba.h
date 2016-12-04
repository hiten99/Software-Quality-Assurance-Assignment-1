#ifndef _CS590_RWVBA_H
#define _CS590_RWVBA_H
class rwvba

{
public:
	/// Default constructor.
	rwvba();
	/// Default destructor.
	~rwvba();
	/// function for parsing expression and returns vector of vector
	std::vector<std::vector<int>> calrwvba(std::vector<std::vector<int>> & v, std::string expression,int vcount);
	///function for generating testcase of robust worstcase bva
	void gentest_rwvba(std::vector<std::vector<int>> & v,int & count, int & current, std::vector<int> & temp);
private:

};
#endif  // !defined _CS590_RWVBA_H