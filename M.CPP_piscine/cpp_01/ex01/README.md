Cet exercice porte sur la gestion de la mémoire en C++, en particulier l'allocation dynamique d'objets et la manipulation des pointeurs. Vous êtes invité à implémenter une fonction qui alloue un tableau d'objets `Zombie` de manière dynamique. Vous devez aussi gérer correctement la libération de cette mémoire afin d'éviter les fuites.

## Objectifs :
- **Allouer un tableau de `Zombie`** : Utiliser la fonction `zombieHorde(int N, std::string name)` pour créer une horde de `N` zombies avec le même nom.
- **Gestion dynamique de la mémoire** : L'allocation des zombies doit se faire en une seule fois avec `new[]`. Vous devez aussi veiller à supprimer la mémoire allouée en utilisant `delete[]`.
- **Test et utilisation des objets** : Après avoir alloué la horde, vous devez appeler la méthode `announce()` pour chaque zombie afin qu'ils se présentent.

## Explication du code

### 1. Zombie.hpp : Déclaration de la classe `Zombie`

```cpp
class Zombie {
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();
    void announce() const;
    void setName(std::string name);
};
```

La classe `Zombie` possède un attribut privé `_name`, et les méthodes publiques incluent le constructeur, le destructeur, la méthode `announce()` et une méthode `setName()` pour initialiser le nom après la création de l'objet.

### 2. Zombie.cpp : Implémentation des méthodes de la classe `Zombie`

```cpp
Zombie::Zombie() {}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    _name = name;
}
```

- Le destructeur affiche un message indiquant que le zombie est détruit. 
- `announce()` fait que le zombie se présente en affichant son nom et le message "BraiiiiiiinnnzzzZ...".
- `setName()` permet de définir le nom du zombie après sa création.

### 3. zombieHorde.cpp : Implémentation de la fonction `zombieHorde()`

```cpp
Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return horde;
}
```

Cette fonction crée un tableau dynamique de `N` objets `Zombie` en utilisant `new[]`.
- Chaque zombie est initialisé avec le même nom en utilisant la méthode `setName()`.
- Un pointeur vers le premier élément de la horde est retourné.

### 4. main.cpp : Test de la horde de zombies

```cpp
int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde; // Libération de la mémoire allouée
    return 0;
}
```

Ce code crée une horde de 5 zombies avec le nom "Zombie".
- Il appelle `announce()` pour chaque zombie dans la boucle afin qu'ils se présentent.
- Après utilisation, la mémoire allouée pour la horde est libérée avec `delete[]`.
