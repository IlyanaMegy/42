
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <cstdio>
# include <cstdlib>
# include <iomanip>
# include <iostream>

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define ORANGE "\033[38;5;208m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

class AAnimal
{
  protected:
	std::string _type;

  public:
	AAnimal(void);
	AAnimal(AAnimal const &copy);
	AAnimal &operator=(AAnimal const &assign);
	virtual ~AAnimal(void);

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
};

#endif