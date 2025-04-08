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

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src): _rates(src._rates){}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		_rates = src._rates;
	return *this;
}

double BitcoinExchange::getRates(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
    if (it == _rates.end() || it->first != date) {
        if (it == _rates.begin())
            return 0;
        --it;
    }
    return it->second;
}

void BitcoinExchange::readDB(const std::string & filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw InvalidFileException();

	std::string line, date;
	double rate;

	if (std::getline(file, line))
		if (line != "date,exchange_rate")
			throw InvalidColumnFormat();

	std::cout << "date | value" << std::endl;

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		if (getline(ss, date, ',') && (ss >> rate))
			_rates[date] = rate;
	}
}

bool BitcoinExchange::isDateOK(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 4; ++i) {
        if (!isdigit(date[i]))
            return false;
	}

    for (int i = 5; i < 7; ++i) {
        if (!isdigit(date[i]))
            return false;
	}

    for (int i = 8; i < 10; ++i) {
		if (!isdigit(date[i]))
            return false;
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == FEBRUARY)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    	return day <= (isLeap ? 29 : 28);
    } else if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) {
        return day <= 30;
	}

	return true;
}

bool BitcoinExchange::isValueOK(const std::string &value)
{
	std::stringstream ss(value);
    double val;
    if (!(ss >> val) || val < 0)
        return false;
    return true;
}

void BitcoinExchange::multiplyWithQuote(std::string const &date, double price)
{
	std::map<std::string, double>::iterator it = _rates.find(date);
	if (it != _rates.end())
		std::cout << date << " | " << price << " | " << price * it->second << std::endl;
	else
	{
		std::map<std::string, double>::iterator it2 = _rates.lower_bound(date);
		if (it2 == _rates.begin())
			std::cout << date << " | " << price << " | " << price * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " | " << price << " | " << price * it2->second << std::endl;
		}
	}
}

void BitcoinExchange::execute(const std::string &fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file)
		throw InvalidFileException();

	std::string line, date, value;
	bool firstLine = true;

	std::getline(file, line);
	
	trim(line);
	if (firstLine && line != "date,exchange_rate")
		throw InvalidColumnFormat();

	while (std::getline(file, line))
	{
		trim(line);

		size_t separator = line.find('|');
        if (separator == std::string::npos || separator != 10 || line[11] != ' ') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, separator - 1);
        std::string valueStr = line.substr(separator + 2);

        trim(date);
        trim(valueStr);
	
		if (!isDateOK(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isValueOK(valueStr))
		{
			std::cout << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		double value;
		std::stringstream ss(valueStr);
		if (!(ss >> value)) {
			std::cout << "Error: bad input => " << valueStr << std::endl;
			continue;
		}
		
		double rate = getRates(date);
		std::cout << date << " | " << value << " | " << value * rate << std::endl;
	}
}
