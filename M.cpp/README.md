| Spécificateur  | Accessible dans la classe | Accessible dans les **classes dérivées** | Accessible dans le code externe |
|----------------|---------------------------|--------------------------------------|----------------------------------|
| `public`       | Oui                       | Oui                                  | Oui                              |
| `protected`    | Oui                       | Oui                                  | Non                              |
| `private`      | Oui                       | Non                                  | Non                              |

> 🤔 **classe dérivées** :

Une classe dérivée hérite des propriétés et des comportements de la classe de base, tout en ayant la possibilité d'ajouter ses propres membres ou de modifier ceux qu'elle hérite.

Cela permet de créer une hiérarchie de classes où certaines classes héritent d'autres, facilitant la réutilisation du code.

**Exemple d'une classe dérivée :**

```cpp
// Classe de base
class Animal {
public:
    void manger() {
        cout << "Cet animal mange." << endl;
    }
};

// Classe dérivée
class Chien : public Animal {
public:
    void aboyer() {
        cout << "Le chien aboie." << endl;
    }
};

int main() {
    Chien monChien;
    monChien.manger();  // Méthode héritée de la classe Animal
    monChien.aboyer();  // Méthode spécifique à la classe Chien
    return 0;
}
```

Types d'héritage :
En C++, il existe plusieurs types d'héritage :

> Héritage **public** :
Les membres public et protected de la classe de base **restent accessibles** dans la classe dérivée selon leur niveau d'accès initial.

> Héritage **protected** : 
Les membres public et protected de la classe de base **deviennent protected** dans la classe dérivée.

> Héritage **private** :
Tous les membres de la classe de base (même public et protected) **deviennent private** dans la classe dérivée.

Dans l'exemple ci-dessus, l'héritage est **public**, ce qui signifie que la méthode manger() est toujours accessible depuis un objet de la classe Chien.


Pour resumer :
- **public** est accessible partout,
- **protected** est accessible seulement dans la classe et les classes dérivées,
- **private** est limité uniquement à la classe elle-même.

---
