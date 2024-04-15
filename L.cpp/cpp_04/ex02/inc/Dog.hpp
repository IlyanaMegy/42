
#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
  private:
	Brain *_brain;

  public:
	Dog(void);
	Dog(Dog const &copy);
	Dog &operator=(Dog const &assign);
	~Dog(void);

	void makeSound(void) const;
	void addIdea(std::string idea);
	void expressIdeas(void) const;
};

#endif
