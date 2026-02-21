L'héritage est un concept fondamental en programmation orientée objet. Il permet à une classe dérivée d'hériter des attributs et méthodes d'une classe de base, ce qui favorise la réutilisation du code et la spécialisation des classes dérivées sans dupliquer le code de base.

### Objectifs des exercices

1.  **Exercice 00 : Aaaaand... OPEN!**  
    Vous implémentez la classe `ClapTrap` avec les attributs suivants :
    
    -   `Name` : Nom du robot.
    -   `Hit points` (10) : Points de vie.
    -   `Energy points` (10) : Points d'énergie.
    -   `Attack damage` (0) : Dommages causés lors des attaques.
    
    La classe doit avoir des méthodes publiques pour attaquer (`attack()`), subir des dégâts (`takeDamage()`) et se réparer (`beRepaired()`). Chaque méthode affiche un message indiquant l'action effectuée.
    
2.  **Exercice 01 : Serena, my love!**  
    Cet exercice introduit la classe dérivée `ScavTrap` qui hérite de `ClapTrap`. Les attributs de `ScavTrap` sont modifiés comme suit :
    
    -   `Hit points` (100).
    -   `Energy points` (50).
    -   `Attack damage` (20).
    
    `ScavTrap` possède également une méthode spéciale `guardGate()` qui affiche un message indiquant que le robot est en mode "gardien de la porte". Cet exercice met l'accent sur la spécialisation des classes dérivées.
    
3.  **Exercice 02 : Repetitive work**  
    Vous créez une autre classe dérivée appelée `FragTrap` qui hérite également de `ClapTrap`. Les attributs de `FragTrap` sont :
    
    -   `Hit points` (100).
    -   `Energy points` (100).
    -   `Attack damage` (30).
    
    `FragTrap` a une méthode spéciale `highFivesGuys()` qui demande un "high five". Ce programme introduit une nouvelle spécialisation via l'héritage multiple.

### Exemple de code pour l'Exercice 00 : ClapTrap

#### 1. **ClapTrap.hpp**

```cpp
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif
```

#### 2. **ClapTrap.cpp**

```cpp
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " took " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't be repaired due to low energy or hit points!" << std::endl;
    }
}
```
Ce code implémente la classe `ClapTrap` avec les méthodes associées pour attaquer, subir des dégâts et se réparer. Chaque action est accompagnée d'un message d'information.