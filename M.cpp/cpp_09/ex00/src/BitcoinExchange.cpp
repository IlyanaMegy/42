#include "../inc/BitcoinExchange.hpp"

std::string trim(const std::string &s) {
	std::string::const_iterator start = s.begin();
    while (start != s.end() && std::isspace(*start))
        start++;

    std::string::const_iterator end = s.end();
    do
        end--;
    while (std::distance(start, end) > 0 && std::isspace(*end));
    return std::string(start, end + 1);
}

BitcoinExchange::BitcoinExchange(){ addDB(); }

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src): _dB(src._dB){}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		_dB = src._dB;
	return *this;
}

void BitcoinExchange::addDB(void)
{
	std::ifstream dataBase("data.csv");
	if (!dataBase.is_open())
		throw std::runtime_error("Error: could not open database.");
	if (dataBase.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: database is empty.");
	std::string dB_line;
	while (getline(dataBase, dB_line))
	{
		if (dB_line.size() < 12)
			throw std::runtime_error("Error: bad database format.");
		std::stringstream ss(dB_line.substr(11));
		double val;
		ss >> val;
		_dB.insert(std::pair<std::string, double>(dB_line.substr(0, 10), val));
	}
	dataBase.close();
}

void BitcoinExchange::readInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw InvalidFileException();
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: input file is empty.");

	std::string line;
	int i = 0;

	if (std::getline(file, line)){
		if (line != "date | value")
			throw InvalidColumnFormat();
		_input.insert(std::pair<int, std::string>(i, line));
		i++;
	}

	while (std::getline(file, line)) {
		if (line.size() < 12)
			throw std::runtime_error("Error: bad database format. " + line);
		_input.insert(std::pair<int, std::string>(i, line));
		i++;
	}
	file.close();
}

bool BitcoinExchange::isDateOK(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == FEBRUARY && day <= (isLeap ? 29 : 28))
		return false;
	
    if ((month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) && day > 30)
		return false;

	return true;
}

int BitcoinExchange::checkValue(const std::string &value)
{
	std::stringstream ss(value);
    if (!(ss >> _value) || _value < 0)
        return 1;
	else if (_value > 1000)
		return 2;
    return 0;
}

void	BitcoinExchange::calculate(std::map<int, std::string>::iterator &it_input)
{
	std::string inputDate = it_input->second.substr(0, 10);
	std::map<std::string, double>::iterator it_dB = _dB.lower_bound(inputDate);
	if (it_dB->first != inputDate)
		it_dB--;
	_result = it_dB->second * _value;
	it_input->second.replace(11, 1, "=>");
	std::stringstream ss;
	ss << _result;
	it_input->second.append(" = " + ss.str());
}

void BitcoinExchange::execute(void)
{
	std::map<int, std::string>::iterator it = _input.begin();
	it++;

	while (it != _input.end())
	{
		std::string date = it->second.substr(0, 10);
		std::string value = it->second.substr(13);
		int resValueCheck = checkValue(value);
		if (!isDateOK(date))
			it->second.replace(0, it->second.size(), ("Error: invalid date : " + date));
		else if (resValueCheck)
		{
			if (resValueCheck == 1)
				it->second.replace(0, it->second.size(), "Error: not positive number : " + value);
			else if (resValueCheck == 2)
				it->second.replace(0, it->second.size(), "Error: too large a number : " + value);
		}
		else
			calculate(it);
		it++;
	}
}

void	BitcoinExchange::printResult()
{
	std::map<int, std::string>::iterator it = _input.begin();
	it++;
	while (it != _input.end())
	{
		if (it->second.find("Error") != std::string::npos)
			std::cout << RED1 <<  "/!\\ line " << it->first << " " << it->second << RESET << std::endl;
		else
			std::cout << LIME << it->second << RESET << std::endl;
		it++;
	}
}
