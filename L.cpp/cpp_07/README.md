## [CPP 07](./ressources/en.subject.pdf)

En C++98, il existe deux principaux types de templates :

- Templates de fonction : Pour créer des fonctions génériques.
- Templates de classe : Pour créer des classes génériques.

> Les templates permettent de définir des paramètres de type. Ces paramètres sont spécifiés à l'aide de la syntaxe template<typename T> ou template<class T>.

---

### Templates de fonction
Les templates de fonction sont utilisés pour écrire une fonction générique qui peut fonctionner avec différents types. Voici un exemple simple :

```cpp
#include <iostream>

// Déclaration d'un template de fonction
template <typename T>
T findMax(T a, T b) {return (a > b) ? a : b;}

int main() {
    // Utilisation avec des types différents
    std::cout << "Max of 10 and 20: " << findMax(10, 20) << std::endl;           // int
    std::cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << std::endl;   // double
    std::cout << "Max of 'a' and 'b': " << findMax('a', 'b') << std::endl;       // char

    return 0;
}
```

Points à noter :

`template <typename T>` introduit un paramètre de type générique T.
Le type de T est déduit automatiquement par le compilateur en fonction des arguments passés à la fonction.

--- 

### Templates de classe
Les templates de classe permettent de définir une classe générique qui peut travailler avec différents types. Voici un exemple :

```cpp
#include <iostream>

// Déclaration d'un template de classe
template <typename T>
class Box {
private:
    T _value;

public:
    // Constructeur
    Box(T v) : _value(v) {}

    // Getter
    T getValue() const {return _value;}

    // Setter
    void setValue(T v) { _value = v;}
};

int main() {
    // Instanciation avec des types différents
    Box<int> intBox(42);
    std::cout << "intBox contains: " << intBox.getValue() << std::endl;

    Box<double> doubleBox(3.14);
    std::cout << "doubleBox contains: " << doubleBox.getValue() << std::endl;

    Box<std::string> stringBox("Hello, Templates!");
    std::cout << "stringBox contains: " << stringBox.getValue() << std::endl;

    return 0;
}
```

Points importants :

`template <typename T>` introduit le paramètre de type générique T.
Lors de l'utilisation de la classe, le type T doit être explicitement spécifié (par exemple, `Box<int>` ou `Box<std::string>`).
Le compilateur génère une version spécifique de la classe pour chaque type utilisé.

---

### Exemple Avancé : Classe avec plusieurs paramètres de type
On peut également utiliser plusieurs paramètres de type avec les templates en C++98. Voici un exemple d'une classe Pair :

```cpp
#include <iostream>

// Template avec deux paramètres de type
template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

int main() {
    Pair<int, std::string> pair(42, "Answer");
    std::cout << "First: " << pair.getFirst() << ", Second: " << pair.getSecond() << std::endl;

    return 0;
}
```

Explications :

Vous pouvez passer plusieurs paramètres de type dans un template en les séparant par des virgules (T1, T2).
Cette approche est utile pour créer des structures de données comme des paires, des tuples, etc.

---

### Points importants à retenir sur les Templates en C++98
- **Génération statique** : Les templates sont instanciés au moment de la compilation. Cela signifie que le compilateur génère une version spécifique du code template pour chaque type utilisé.
- **Spécialisations** : Vous pouvez fournir des implémentations spécifiques pour des types particuliers (comme montré avec std::string).
- **Dépendance des types** : En C++98, la gestion des types peut être plus complexe. Par exemple, vous devez explicitement indiquer si un membre appartient à un type dépendant (typename est nécessaire dans certains cas).
- **Pas de concepts ou de contraintes** : En C++98, il n'y a pas de moyen natif d'imposer des contraintes sur les types (par exemple, exiger que le type ait un opérateur spécifique comme + ou <).

---

### Pourquoi utiliser un fichier .tpp pour les templates ?
Un fichier avec une extension .tpp (ou parfois .ipp) est souvent utilisé dans le cadre des templates en C++ pour stocker les définitions des fonctions membres de classes template. Cela permet de structurer le code tout en respectant les contraintes spécifiques aux templates.

En C++, les templates nécessitent que leur définition complète soit disponible au moment de la compilation. Cela signifie que :

Le compilateur doit connaître à la fois la déclaration et l'implémentation de la classe template lorsque vous l'utilisez avec un type particulier.
Contrairement aux classes normales, il n'est pas possible de simplement déclarer les templates dans un fichier d'en-tête (.hpp) et de définir leurs fonctions membres dans un fichier source séparé (.cpp). Sinon, vous obtiendrez une erreur de "`undefined reference`".

#### => Structure typique avec un fichier .tpp
Pour contourner cette limitation, la définition des méthodes membres des templates est souvent placée dans un fichier .tpp, qui est ensuite inclus à la fin du fichier d'en-tête .hpp. Cela permet de séparer les déclarations et les définitions tout en respectant les besoins du compilateur.

Exemple :
```cpp
// ###### HEADER ###### ./Box.hpp
#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

template<typename T>
class Box {
private:
    T _value;

public:
    // Constructeur
    Box(T v);

    // Getter
    T getValue() const;

    // Setter
    void setValue(T v);
};

// Inclure les définitions du fichier .tpp
#include "Box.tpp"
#endif
```
```cpp
// ###### TEMPLATE ###### ./Box.tpp
// Définir les méthodes du template
template<typename T>
Box<T>::Box(T v) : _value(v) {}

template<typename T>
T Box<T>::getValue() const {
    return _value;
}

template<typename T>
void Box<T>::setValue(T v) {
    _value = v;
}
```
```cpp
// ./main.cpp
#include "Box.hpp"
#include <string>

int main() {
    Box<int> intBox(42);
    std::cout << "intBox contains: " << intBox.getValue() << std::endl;

    Box<std::string> stringBox("Hello, Templates!");
    std::cout << "stringBox contains: " << stringBox.getValue() << std::endl;

    return 0;
}
```
