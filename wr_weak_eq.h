#ifndef _CS590_WR_WEAK_EQ_H
#define _CS590_WR_WEAK_EQ_H
class wr_weak_eq

{
public:
	/// Default constructor.
	wr_weak_eq();
	/// Default destructor.
	~wr_weak_eq();
	/// function for parsing expression and returns vector of vector
	std::vector<std::vector<int>> cal_wr_weak_eq(std::vector<std::vector<int>> & v, std::string expression,int vcount,int & minminus);
	///function for generating testcase of robust worstcase equivalence class testing
	void gentest_wr_weak_eq(std::vector<std::vector<int>> & v,int & count,  std::vector<int> & temp, size_t & y);

private:

};
#endif  // !defined _CS590_WR_WEAK_EQ_H