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

### Les conteneurs séquentiels en détail
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

#### 2. `std::deque`
Un `deque` (double-ended queue) est un tableau dynamique où l'ajout/suppression d'éléments est rapide aux deux extrémités.

**Caractéristiques** :
- Accès rapide aux éléments par index.
- Croissance dynamique des deux côtés.
- Moins efficace en termes de mémoire que vector.

Exemple :
```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    // Ajouter des éléments aux deux extrémités
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);

    // Afficher les éléments
    for (size_t i = 0; i < dq.size(); ++i) {
        std::cout << dq[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### 3. `std::list`
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