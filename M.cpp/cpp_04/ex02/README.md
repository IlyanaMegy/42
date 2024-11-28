L'objectif de ce module est d'explorer le polymorphisme et les classes abstraites. Ces concepts sont fondamentaux dans la programmation orientée objet et permettent d'écrire du code flexible et extensible.

### Polymorphisme

Le polymorphisme vous permet de **manipuler des objets de classes dérivées** via des pointeurs ou références à leur classe de base. Le comportement des méthodes peut être redéfini dans les classes dérivées tout en utilisant une interface commune.

### Classes abstraites

Les classes abstraites sont des classes qui ne peuvent pas être instanciées. Elles servent de base pour d'autres classes, et contiennent au moins une méthode pure virtuelle. Les classes dérivées doivent implémenter ces méthodes.

### Interfaces

Bien que C++ n'ait pas d'interfaces formelles comme certains langages (Java), les classes purement abstraites (avec uniquement des méthodes virtuelles pures) jouent le rôle d'une interface en fournissant un contrat que les classes dérivées doivent respecter.

### Explication du code

1.  **AAnimal.hpp (classe de base abstraite)**

```cpp
class AAnimal {
    protected:
        std::string type;
    
    public:
        AAnimal();
        virtual ~AAnimal();
    
        virtual void makeSound() const = 0; // Méthode pure virtuelle
        std::string getType() const;
    };
```
 
   -   `AAnimal` est une classe abstraite. Elle ne peut pas être instanciée car la méthode `makeSound()` est pure virtuelle.
   -   Le destructeur est virtuel pour garantir la destruction correcte des objets dérivés.
3.  **Dog.hpp et Dog.cpp (classe dérivée de AAnimal)**

```cpp
class Dog : public AAnimal {
    public:
        Dog();
        ~Dog();
    
        void makeSound() const; // Implémentation de la méthode pure virtuelle
    };
```
    
```cpp
Dog::Dog() {
        type = "Dog";
    }
    
    Dog::~Dog() {}
    
    void Dog::makeSound() const {
        std::cout << "Woof Woof!" << std::endl;
    }
```
   -   La classe `Dog` dérive de `AAnimal` et implémente la méthode `makeSound()`.
   -   Le constructeur initialise le type d'animal à "Dog".
5.  **Cat.hpp et Cat.cpp (classe dérivée de AAnimal)**

```cpp
class Cat : public AAnimal {
    public:
        Cat();
        ~Cat();
    
        void makeSound() const;
    };
```
    
```cpp
    Cat::Cat() {
        type = "Cat";
    }
    
    Cat::~Cat() {}
    
    void Cat::makeSound() const {
        std::cout << "Meow Meow!" << std::endl;
    }
```
    -   Comme `Dog`, la classe `Cat` hérite de `AAnimal` et implémente la méthode `makeSound()`.

6.  **Brain.hpp et Brain.cpp (composition avec les classes Dog et Cat)**
    
```cpp
class Brain {
    private:
        std::string ideas[100];
    
    public:
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
    };
```
```cpp
Brain::Brain() {
        for (int i = 0; i < 100; i++) {
            ideas[i] = "Idea " + std::to_string(i);
        }
    }
    
    Brain::~Brain() {}
    
    Brain::Brain(const Brain& other) {
        *this = other;
    }
    
    Brain& Brain::operator=(const Brain& other) {
        if (this != &other) {
            for (int i = 0; i < 100; i++) {
                ideas[i] = other.ideas[i];
            }
        }
        return *this;
    }
```
    
   -   La classe `Brain` contient un tableau de 100 idées. Elle est utilisée comme un attribut privé dans `Dog` et `Cat`.
   -   Le constructeur par copie et l'opérateur d'affectation garantissent une copie profonde.
7.  **Main.cpp (exemple d'utilisation du polymorphisme et des classes abstraites)**
    
```cpp
int main() {
        const AAnimal* dog = new Dog();
        const AAnimal* cat = new Cat();
    
        std::cout << dog->getType() << " says: ";
        dog->makeSound();
    
        std::cout << cat->getType() << " says: ";
        cat->makeSound();
    
        delete dog;
        delete cat;
    
        return 0;
    }
``` 
 -   Ce code montre comment utiliser le polymorphisme pour manipuler des objets de type `Dog` et `Cat` via des pointeurs à `AAnimal`.
