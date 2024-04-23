
#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
  private:
	Brain *_brain;

  public:
	Cat(void);
	Cat(Cat const &copy);
	Cat &operator=(Cat const &assign);
	~Cat(void);

	void makeSound(void) const;
	void addIdeas(std::string idea);
	void expressIdeas(void) const;
};

#endif
