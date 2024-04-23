
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int	main(void)
{
	std::cout << std::endl
				<< "--- PDF: ---" << std::endl
				<< std::endl;
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	delete dog;
	delete cat;

	std::cout << std::endl
				<< GREEN << "--- Array of animals ---" << std::endl
				<< std::endl;

	AAnimal *array_animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			array_animals[i] = new Dog();
		else
			array_animals[i] = new Cat();
	}
	std::cout << std::endl
				<< YELLOW;

	for (int i = 0; i < 10; i++)
		array_animals[i]->makeSound();

	std::cout << std::endl
				<< RED;

	for (int i = 0; i < 10; i++)
		delete array_animals[i];

	std::cout << std::endl
				<< BLUE << "--- Test for deep copy ---" << std::endl
				<< std::endl;
	Cat *cat2 = new Cat();
	cat2->addIdeas("Hmm... fish!");
	cat2->addIdeas("I wanna play...");
	cat2->expressIdeas();

	std::cout << std::endl
				<< MAGENTA << "--- Making a deep copy ---" << std::endl
				<< std::endl;

	Cat *cat3 = new Cat(*cat2);
	cat2->addIdeas("Gotta sleep now...");
	std::cout << std::endl;
	cat2->expressIdeas();
	std::cout << std::endl;
	cat3->expressIdeas();
	std::cout << std::endl;

	std::cout << std::endl
				<< CYAN << "--- Copy assignment operator ---" << std::endl
				<< std::endl;

	std::cout << "New Cat" << std::endl
				<< std::endl;
	Cat *cat4 = new Cat();
	std::cout << std::endl
				<< "Assigning cat 3 to cat 4" << std::endl
				<< std::endl;
	*cat4 = *cat3;
	std::cout << std::endl;
	cat4->expressIdeas();
	std::cout << std::endl;
	cat3->addIdeas("No sleeping now!!!");
	cat3->expressIdeas();
	std::cout << std::endl;
	cat4->expressIdeas();
	std::cout << std::endl;

	std::cout << std::endl
				<< RED << "--- Destruction ---" << std::endl
				<< std::endl;

	delete cat2;
	delete cat3;
	delete cat4;
	return (0);
}