Cet exercice vous apprend à utiliser des **pointeurs sur fonctions membres** en C++. Vous allez implémenter une classe `Harl` qui se plaint à différents niveaux de gravité : **DEBUG**, **INFO**, **WARNING**, et **ERROR**. L'objectif est d'utiliser des pointeurs sur fonctions pour éviter une structure de type `if/else` ou `switch`, et rendre le code plus modulaire et extensible.

## Objectifs :
1. **Pointeurs sur fonctions membres** : Vous allez découvrir comment associer des niveaux de gravité à des fonctions membres spécifiques.
2. **Gestion des plaintes** : Chaque plainte est liée à un niveau de gravité, et vous devez exécuter la fonction correspondante en fonction de ce niveau.
3. **Modularité et efficacité** : L'utilisation de pointeurs sur fonctions permet d'ajouter facilement de nouveaux niveaux de plaintes sans modifier de longues chaînes conditionnelles.

## Explication du code

### 1. Harl.hpp : Déclaration de la classe `Harl`

```cpp
class Harl {
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    void complain( std::string level );
};
```

- **Méthodes privées** : `debug()`, `info()`, `warning()`, et `error()` sont les méthodes qui correspondent à différents niveaux de plaintes.
- **Méthode publique** : `complain()` prend un `std::string` comme paramètre, et selon le niveau passé, appelle l'une des méthodes privées.

### 2. Harl.cpp : Implémentation de la classe `Harl`

```cpp
#include "Harl.hpp"
#include <iostream>

void Harl::debug( void ) {
    std::cout << "[DEBUG] I love having extra bacon on my burger!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[INFO] Adding extra bacon costs more money." << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[WARNING] I think I deserve extra bacon for free." << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ERROR] This is unacceptable, I want to speak to the manager!" << std::endl;
}

void Harl::complain( std::string level ) {
    void (Harl::*complaints[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*complaints[i])(); // Appel de la fonction via pointeur
            break;
        }
    }
}
```

- Chaque méthode (`debug`, `info`, `warning`, `error`) affiche un message correspondant à son niveau de gravité.
- La méthode `complain()` associe des pointeurs sur les méthodes membres aux niveaux de gravité. Si le niveau passé en paramètre correspond à un des niveaux de la liste, la fonction correspondante est appelée via un pointeur sur fonction membre.

### 3. main.cpp : Test de la classe `Harl`

```cpp
#include "Harl.hpp"

int main() {
    Harl harl;
    
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    return 0;
}
```

- Ce programme crée une instance de `Harl` et appelle la méthode `complain()` avec différents niveaux de gravité pour tester chaque cas.
