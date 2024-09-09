L'objectif de cet exercice est de vous apprendre à utiliser des objets alloués dynamiquement (sur le tas) et statiquement (sur la pile) dans C++. Vous devez comprendre dans quel cas il est judicieux d'utiliser l'une ou l'autre méthode d'allocation de mémoire. Les concepts abordés incluent :

-   **Création d'objets sur la pile** : L'allocation mémoire se fait automatiquement lorsque la fonction dans laquelle l'objet est déclaré se termine.
-   **Création d'objets sur le tas** : Utilisation de `new` pour allouer de la mémoire de manière dynamique, avec la responsabilité de libérer cette mémoire avec `delete` pour éviter les fuites de mémoire.

### Explication du code :

1.  **Zombie.hpp** : Ce fichier contient la déclaration de la classe `Zombie`.

```
class Zombie {
    private:
        std::string _name;
    
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
    };
```
   -   Le nom du zombie est un attribut privé, et la fonction `announce()` permet à chaque zombie de se présenter.
   -   Le constructeur reçoit un nom, et le destructeur libère les ressources associées.

2.  **Zombie.cpp** : Ce fichier contient l'implémentation de la classe `Zombie`.

```
Zombie::Zombie(std::string name) : _name(name) {
        // Constructor code
    }
    
    Zombie::~Zombie() {
        std::cout << _name << " has been destroyed." << std::endl;
    }
    
    void Zombie::announce() {
        std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
```
   -   Le constructeur initialise le nom du zombie, et le destructeur affiche un message quand un zombie est détruit.
   -   `announce()` permet au zombie d'afficher son nom suivi de "BraiiiiiiinnnzzzZ...".
3.  **newZombie.cpp** : Ce fichier implémente une fonction qui crée un zombie sur le tas.
```
Zombie* newZombie(std::string name) {
        return new Zombie(name);
    }
```
    
   -   Cette fonction alloue dynamiquement un zombie avec `new` et le retourne sous forme de pointeur.
4.  **randomChump.cpp** : Cette fonction crée un zombie sur la pile et le fait immédiatement s'annoncer.
```
void randomChump(std::string name) {
        Zombie zombie(name);
        zombie.announce();
    }
```
   -   Ici, le zombie est créé sur la pile et s'annonce immédiatement avant que l'objet ne soit détruit à la fin de la fonction.
   
5.  **main.cpp** : Ce fichier contient la fonction principale qui teste les zombies créés à la fois sur la pile et sur le tas.

```
int main() {
        Zombie* heapZombie = newZombie("HeapZombie");
        heapZombie->announce();
        delete heapZombie;  // Don't forget to delete dynamically allocated memory!
        randomChump("StackZombie");
    
        return 0;
    }
```

   -   Un zombie est créé sur le tas avec `newZombie()`, et un autre est créé sur la pile avec `randomChump()`.
   -   L'objet alloué dynamiquement est explicitement détruit avec `delete`.