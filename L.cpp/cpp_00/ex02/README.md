L'exercice se concentre sur l'introduction aux bases de la programmation orientée objet, les **namespaces**, les **classes**, les **fonctions membres**, les **flux de données standard** (stdio streams), les **listes d'initialisation**, les **membres** `static`, `const`, et d'autres concepts fondamentaux.

L'objectif est de recréer un fichier manquant (Account.cpp) à partir de l'observation du fichier d'en-tête (Account.hpp) et des tests fournis (tests.cpp).

### La notion clé :

Cet exercice introduit plusieurs concepts de base en programmation orientée objet et en conception de classes en C++.

-   **Classes et En-têtes** : Vous travaillez avec des classes, en utilisant un fichier d'en-tête (Account.hpp) pour déclarer la structure de la classe, et un fichier source (Account.cpp) pour implémenter les fonctions membres. Ce découpage en fichiers d'en-tête et de code source est une pratique courante en C++ pour organiser le code.
    
-   **Membres `static` et `const`** : L'utilisation des membres `static` permet de partager des variables ou des méthodes entre toutes les instances de la classe. Les membres `const`, quant à eux, garantissent que leurs valeurs ne peuvent pas être modifiées après initialisation.
    
-   **Gestion de la mémoire** : L'exercice souligne également l'importance de la gestion de la mémoire, notamment l'absence de fuites de mémoire lorsque vous allouez dynamiquement des ressources (via `new`/`delete`).
    

### Le code fourni :

Le fichier **Account.cpp** que vous avez fourni met en œuvre plusieurs concepts clés de la programmation orientée objet en C++. Voici une explication du code, étape par étape :

### Déclarations des variables membres statiques

```
int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
```

Ces variables statiques appartiennent à la classe `Account`, et non aux instances individuelles. Elles sont utilisées pour suivre le nombre total de comptes, les dépôts, les retraits et le montant total détenu par tous les comptes. Elles sont partagées entre toutes les instances de la classe.

### Constructeur

```
Account::Account(int initial_deposit)
{
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = this->getNbAccounts();
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created"<< std::endl;
    Account::_nbAccounts++;
}
```

Le constructeur initialise les attributs d'un compte. Chaque nouveau compte est créé avec un dépôt initial. Il met à jour le montant total de tous les comptes et affiche un message indiquant la création du compte.

### Fonction d'affichage de l'horodatage

```
void Account::_displayTimestamp(void)
{
    time_t now = time(NULL);
    struct tm timenow = *localtime(&now);

    std::cout << "[" << timenow.tm_year + 1900 <<
    std::setfill('0') << std::setw(2) << timenow.tm_mon + 1 <<
    std::setfill('0') << std::setw(2) << timenow.tm_mday << "_" <<
    std::setfill('0') << std::setw(2) << timenow.tm_hour <<
    std::setfill('0') << std::setw(2) << timenow.tm_min <<
    std::setfill('0') << std::setw(2) << timenow.tm_sec << "] ";
}
```

Cette fonction statique affiche l'heure actuelle sous un format personnalisé. Cela est utile pour afficher des horodatages dans les journaux ou les actions des comptes.

### Affichage des informations sur les comptes
```
void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}
```

Cette fonction statique affiche des informations sur l'état global de la banque, comme le nombre total de comptes, le montant total détenu, et le nombre total de dépôts et retraits.

### Fonction `makeDeposit`

```
void Account::makeDeposit(int deposit) {
    this->_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}
```

Cette fonction permet de faire un dépôt. Elle met à jour les informations sur le compte individuel (montant du compte et nombre de dépôts) ainsi que les statistiques globales de la banque (montant total et nombre total de dépôts).

### Fonction `makeWithdrawal`

```
bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (withdrawal > this->checkAmount())
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    Account::_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}
```

Cette fonction permet de faire un retrait. Elle vérifie si le compte dispose de suffisamment de fonds avant de traiter le retrait. Si le retrait est possible, elle met à jour les informations du compte et les statistiques globales.

### Destructeur

```
Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
    Account::_nbAccounts--;
}
```

Le destructeur est appelé lorsque l'objet `Account` est supprimé. Il affiche un message indiquant que le compte est fermé et met à jour le nombre total de comptes.