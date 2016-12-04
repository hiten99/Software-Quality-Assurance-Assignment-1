#ifndef _CS590_WEAK_EQ_H
#define _CS590_WEAK_EQ_H
class weak_eq

{
public:
	/// Default constructor.
	weak_eq();
	/// Default destructor.
	~weak_eq();
	/// function for parsing expression and returns vector of vector
	std::vector<std::vector<int>> cal_weak_eq(std::vector<std::vector<int>> & v, std::string expression,int vcount);
	///function for generating testcase of equivalence class testing
	void gentest_weak_eq(std::vector<std::vector<int>> & v,int & count, int & current, std::vector<int> & temp,size_t & p);

private:

};
#endif  // !defined _CS590_WEAK_EQ_H