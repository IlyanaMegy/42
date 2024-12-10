#include <iostream>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock const &src);
		Warlock &operator=(Warlock const &src);
	public:
		Warlock(std::string n, std::string t);
		~Warlock();

		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string &t);
		void introduce() const;
};
