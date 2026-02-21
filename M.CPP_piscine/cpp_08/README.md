## [CPP 08](./ressources/fr.subject.pdf)

En C++98, les conteneurs (containers) sont des structures de données génériques fournies par la **STL** (Standard Template Library).
Ils permettent de stocker, gérer et manipuler des collections d'objets de manière efficace, tout en fournissant des interfaces génériques.

### Catégories principales de conteneurs
Les conteneurs en C++98 peuvent être divisés en trois grandes catégories :

#### 1. Conteneurs séquentiels
Ces conteneurs organisent les éléments dans un ordre spécifique. Les éléments sont stockés et accessibles séquentiellement.

| Conteneur     | Description                                                              |
|---------------|--------------------------------------------------------------------------|
| `std::vector` | Tableau dynamique qui peut changer de taille.                           |
| `std::deque`  | Tableau dynamique à double extrémité (ajout/suppression rapide).         |
| `std::list`   | Liste chaînée doublement chaînée (accès séquentiel uniquement).          |

#### 2. Conteneurs associatifs
Ces conteneurs organisent les éléments en fonction de clés, généralement dans un ordre trié. Ils permettent une recherche rapide.

| Conteneur       | Description                                                              |
|-----------------|--------------------------------------------------------------------------|
| `std::set`      | Collection d'éléments uniques, ordonnés.                                 |
| `std::multiset` | Comme `set`, mais permet des doublons.                                   |
| `std::map`      | Tableau associatif (clé-valeur), avec des clés uniques, ordonné.         |
| `std::multimap` | Comme `map`, mais permet plusieurs paires avec la même clé.             |

#### 3. Conteneurs adaptatifs
Ce sont des conteneurs qui offrent des interfaces restreintes basées sur des structures de données sous-jacentes.

| Conteneur          | Description                                                          |
|--------------------|----------------------------------------------------------------------|
| `std::stack`       | Implémentation LIFO (Last-In-First-Out) basée sur un autre conteneur. |
| `std::queue`       | Implémentation FIFO (First-In-First-Out) basée sur un autre conteneur.|
| `std::priority_queue` | Queue avec priorités (éléments sortis selon un ordre défini).      |

### Les conteneurs en détail
#### 1. `std::vector`
Un `vector` est un tableau dynamique qui peut croître ou rétrécir dynamiquement. Les éléments sont contigus en mémoire.

**Caractéristiques** :
- Accès rapide aux éléments par index.
- Croissance automatique du tableau lorsque la capacité est dépassée.
- Les insertions/suppressions à la fin sont rapides, mais lentes ailleurs.

Exemple :
```cpp
#include <iostream>
#include <vector>

int main() {
    //  Creation d'un tableau de int
    std::vector<int> vec;

    // Ajouter des éléments
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Afficher les éléments
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### 2. `std::list`
Un `list` est une liste doublement chaînée, où chaque élément est lié aux éléments précédent et suivant.

**Caractéristiques** :
- Insertion et suppression rapides n'importe où dans la liste.
- Pas d'accès direct par index.
- Consomme plus de mémoire que vector ou deque.

Exemple :
```cpp
#include <iostream>
#include <list>

int main() {
    // Creation d'un tableau de int
    std::list<int> lst;

    // Ajouter des éléments
    lst.push_back(10);
    lst.push_back(20);
    lst.push_front(5);

    // Afficher les éléments
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### 3. `std::map`
Un `map` est un tableau associatif qui stocke des paires clé-valeur, avec des clés uniques.

Caractéristiques :

Les paires sont automatiquement triées par clé.
Accès rapide aux valeurs via les clés.
Exemple :

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap;           //  equivalent a un dictionnaire ou la cle sera de type string 
                                                //  et la valeur associee est un int.

    myMap["Alice"] = 30;
    myMap["Bob"] = 25;

    for (std::map<std::string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```
---

### Résumé des Conteneurs

| **Conteneur**       | **Caractéristique principale**            | **Accès direct** | **Tri automatique** | **Doublons autorisés** |
|---------------------|-------------------------------------------|------------------|---------------------|------------------------|
| `std::vector`       | Tableau dynamique                        | Oui              | Non                 | Oui                    |
| `std::deque`        | Tableau doublement dynamique             | Oui              | Non                 | Oui                    |
| `std::list`         | Liste doublement chaînée                 | Non              | Non                 | Oui                    |
| `std::set`          | Collection triée d'éléments uniques      | Non              | Oui                 | Non                    |
| `std::multiset`     | Collection triée avec doublons permis    | Non              | Oui                 | Oui                    |
| `std::map`          | Table associée clé-valeur, clés uniques  | Non              | Oui                 | Non                    |
| `std::multimap`     | Table associée clé-valeur avec doublons  | Non              | Oui                 | Oui                    |
| `std::stack`        | Pile LIFO                                | Non              | Non                 | N/A                    |
| `std::queue`        | File FIFO                                | Non              | Non                 | N/A                    |
| `std::priority_queue` | File triée par priorité                | Non              | Oui (selon priorité)| N/A                    |
