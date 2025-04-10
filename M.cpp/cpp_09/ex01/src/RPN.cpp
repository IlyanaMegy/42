#include "../inc/RPN.hpp"

RPN::RPN(void)
{
	throw std::invalid_argument("Error: please provide an argument");
}
RPN::RPN(std::string input) : _input(input), _result(0) { inputCheck(); }
RPN::RPN(const RPN &copy) { *this = copy; }
RPN &RPN::operator=(const RPN &copy) {
	if (this != &copy)
	{
		_input = copy._input;
		_result = copy._result;
	}
	return (*this);
}
RPN::~RPN() {}

void RPN::inputCheck(void) {
	int nbCount = 0;
	int opCount = 0;

	for (size_t i = 0; i < _input.length(); i++)
	{
		char c = _input[i];
		if (c == ' ')
			continue;
		if (isdigit(c))
		{
			nbCount++;
			while (i < _input.size() && isdigit(_input[i]))
				i++;
			i--;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			opCount++;
			if (nbCount < 2)
				throw std::invalid_argument("Error: too many operators");
			nbCount--;
		}
		else
			throw std::invalid_argument("Error: invalid character");
	}

	if (nbCount != 1 || opCount == 0)
		throw std::invalid_argument("Error: Invalid RPN expression");
}

int RPN::calculate(void) {
	for (std::string::iterator it = _input.begin(); it != _input.end(); it++) {
		if (*it == ' ')
			continue;
		if (isdigit(*it)) {
			int num = 0;
			while (isdigit(*it)) {
				num = num * 10 + *it - '0';		// ? Convert to int (atoi remember ?)
				it++;
			}
			_stack.push(num);
		}
		else {
			int a = _stack.top(); _stack.pop();	// ? Pop the top two elements
			int b = _stack.top(); _stack.pop();

			switch (*it)
            {
                case '+': _stack.push(b + a); break;
                case '-': _stack.push(b - a); break;
                case '*': _stack.push(b * a); break;
                case '/':
                    if (a == 0)
                        throw std::invalid_argument("Error: Division by zero");
                    _stack.push(b / a);
                    break;
                default:
                    throw std::invalid_argument("Error: Invalid operator in RPN expression");
            }
		}
	}
	_result = _stack.top();
	return _result;
}
