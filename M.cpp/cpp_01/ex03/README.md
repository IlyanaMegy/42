Cet exercice vous apprend à gérer des relations entre classes en C++, en particulier l'utilisation de références et de pointeurs sur objets dans le cadre de l'orientation objet. Vous allez créer des objets de type `HumanA` et `HumanB` qui utilisent une arme (`Weapon`). L'exercice met l'accent sur les différences entre les références et les pointeurs dans les classes, ainsi que sur la gestion des objets et des attributs associés.

## Objectifs :
1. **Gestion des objets et des attributs** : Vous devez gérer des classes comme `Weapon`, qui a un type d'arme, et des classes comme `HumanA` et `HumanB`, qui utilisent ces armes.
2. **Références vs Pointeurs** : Vous allez explorer les différences entre l'utilisation de références et de pointeurs pour gérer les relations entre objets.
3. **Gestion des fuites de mémoire** : Assurez-vous que chaque instance d'arme ou de personnage est bien gérée et que la mémoire est correctement libérée si nécessaire.

## Explication du code

### 1. Weapon.hpp : Déclaration de la classe `Weapon`

```cpp
class Weapon {
private:
    std::string type;

public:
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(std::string newType);
};
```

- **Attribut privé** : `type` représente le type d'arme (ex. : "épée", "fusil").
- **Méthodes publiques** :
  - `getType()` : Renvoie le type d'arme (référence constante).
  - `setType()` : Permet de changer le type d'arme.

### 2. Weapon.cpp : Implémentation de la classe `Weapon`

```cpp
Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(std::string newType) {
    type = newType;
}
```

- Le constructeur initialise l'arme avec un type.
- `getType()` renvoie une référence constante pour éviter que l'utilisateur modifie directement le type.
- `setType()` modifie le type de l'arme.

### 3. HumanA.hpp : Déclaration de la classe `HumanA`

```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
};
```

- `HumanA` possède un nom et une référence sur une arme (weapon).
- La référence sur `Weapon` est initialisée via le constructeur et ne peut pas être modifiée par la suite, garantissant que `HumanA` a toujours une arme.

### 4. HumanA.cpp : Implémentation de la classe `HumanA`

```cpp
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
```

- Le constructeur initialise `name` et la référence sur `weapon`.
- La méthode `attack()` affiche une phrase indiquant que `HumanA` attaque avec son arme.

### 5. HumanB.hpp : Déclaration de la classe `HumanB`

```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};
```

- `HumanB` possède un nom et un pointeur sur une arme. Contrairement à `HumanA`, `HumanB` peut commencer sans arme et en changer plus tard.
- `setWeapon()` permet de donner une arme à `HumanB`.

### 6. HumanB.cpp : Implémentation de la classe `HumanB`

```cpp
HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon" << std::endl;
    }
}
```

- `HumanB` peut ne pas avoir d'arme au départ (`weapon` est un pointeur nul).
- `setWeapon()` affecte une arme à `HumanB`.
- La méthode `attack()` vérifie si `HumanB` a une arme avant d'attaquer.

### 7. main.cpp : Test des classes `HumanA` et `HumanB`

```cpp
int main() {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();

    return 0;
}
```

- Ce programme crée une arme et deux personnages (`HumanA` et `HumanB`).
- `HumanA` attaque toujours avec une arme donnée lors de la création.
- `HumanB` peut changer d'arme en cours d'exécution.
- Les types d'armes peuvent être modifiés à l'aide de `setType()`.
