#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN {
   private:
	std::string _input;
	std::stack<int> _stack;
	int _result;
	void inputCheck(void);

   public:
	RPN(void);
	RPN(std::string input);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN(void);

	int calculate(void);
};
#endif
