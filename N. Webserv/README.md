# Projet WEBSERV

<p>&nbsp;</p>

<p align="center">
  <img src="./ressources/CGI-and-Web-Server-connection-with-Database.png" alt="webserv_schema"/>
</p>

## Sommaire :
- [I. Objectif](#i-objectif)
- [II. Parties principales](#ii-parties-principales)
  - **☀️ Partie obligatoire**
  - **☀️ Prérequis techniques**
  - **Bonus**
- [III. Criteres de reussite](#iii-criteres-de-reussite)
- [IV. Grandes Etapes](#iv-grandes-etapes)
- [V. CGI](#v-cgi)
	- **Fonctionnement de CGI**
	- **Exemple de flux CGI**
	- **Importance et Utilisation**
	- **Limites**

<p>&nbsp;</p>

# I. Objectif

Le but du projet [Webserv](./ressources/fr.subject.pdf) est de créer un serveur HTTP conforme au protocole HTTP/1.1. Ce serveur devra pouvoir être testé dans un véritable navigateur et respecter certaines contraintes spécifiques liées à la gestion des entrées/sorties non bloquantes.

<p>&nbsp;</p>

# II. Parties principales

1.  **Partie obligatoire**
    
    -   Développement du serveur HTTP avec C++98.
    -   Gestion des requêtes HTTP (GET, POST, DELETE).
    -   Le serveur doit être capable de traiter plusieurs connexions et rester performant sous pression (tests de charge).
    -   Il doit supporter le téléversement de fichiers et offrir une compatibilité avec les méthodes CGI pour l'exécution de scripts dynamiques (comme PHP).
    -   Un fichier de configuration permet de spécifier les hôtes, les ports, les routes, les pages d’erreur, etc.
2.  **Prérequis techniques**
    
    -   Utilisation de **poll()** ou équivalents (epoll, kqueue) pour la gestion des entrées/sorties non bloquantes.
    -   Limitation à certaines fonctions système pour les opérations réseau et de gestion des processus (ex : `execve`, `socket`, `bind`, etc.).
    -   Respect strict des normes C++98 et interdiction de l’utilisation de bibliothèques externes comme Boost.
3.  **Bonus (optionnel)**
    
    -   Gestion avancée des sessions et des cookies.
    -   Prise en charge de plusieurs CGI.

<p>&nbsp;</p>

# III. Criteres de reussite

-   Le serveur doit être capable de fonctionner sans interruption et être compatible avec un navigateur web. En cas de plantage ou de comportement inattendu, le projet sera invalidé.
-   La partie bonus n’est prise en compte que si toutes les fonctionnalités obligatoires sont parfaitement réalisées.

Ce projet nécessite une bonne compréhension des protocoles réseau, de la gestion des fichiers et des processus sous Unix, ainsi que des concepts de développement non bloquant.

<p>&nbsp;</p>

# IV. Grandes Etapes
Pour réaliser un projet comme **Webserv** (un serveur HTTP en C++98), il faut suivre plusieurs étapes structurées, allant de la conception initiale à l'implémentation et aux tests. Voici les grandes étapes de code pour ce projet :

### Compréhension des Spécifications

-   Lire et comprendre le sujet du projet, notamment les fonctionnalités obligatoires et les exigences techniques (utilisation de C++98, gestion des entrées/sorties non bloquantes, etc.).
-   Étudier le protocole HTTP/1.1 et ses spécifications, en particulier les méthodes GET, POST, DELETE, les codes de statut, et la gestion des en-têtes.

### Architecture du Serveur

-   **Décomposition en modules** : Découper le projet en modules ou classes, tels que :
    -   **Socket Server** : Gérer la création, l'écoute, et l'acceptation des connexions.
    -   **HTTP Request** : Analyser et comprendre les requêtes HTTP entrantes.
    -   **HTTP Response** : Générer les réponses HTTP appropriées.
    -   **CGI Handler** : Gérer l'exécution des scripts CGI.
    -   **Configuration Parser** : Lire et interpréter le fichier de configuration.
-   **Conception des classes** : Définir les classes avec leurs attributs et méthodes. Par exemple, une classe `HttpRequest` pourrait avoir des méthodes pour analyser les en-têtes et le corps de la requête.

### Initialisation du Serveur

-   **Socket et Liaison** : Créer un socket, le lier à une adresse IP et un port spécifiques (définis dans le fichier de configuration), et mettre le socket en mode écoute.
    
```
int server_fd = socket(AF_INET, SOCK_STREAM, 0);
bind(server_fd, (struct sockaddr*)&address, sizeof(address));
listen(server_fd, SOMAXCONN);
```
    
-   **Poll (ou équivalent)** : Mettre en place `poll()` (ou `select()`, `epoll()`, etc.) pour surveiller plusieurs descripteurs de fichiers, détecter les connexions entrantes, et gérer les opérations de lecture/écriture sans blocage.

### Gestion des Requêtes HTTP

-   **Accepter les connexions** : Lorsque `poll()` détecte une nouvelle connexion, l'accepter et ajouter le descripteur de fichier au set de descripteurs surveillés.
    
```
 int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
```
    
-   **Lire les requêtes** : Lire la requête entrante via le socket, analyser les en-têtes et le corps de la requête.

```
char buffer[1024] = {0};
read(new_socket, buffer, 1024);
```
    
-   **Créer une réponse** : En fonction de la requête, générer une réponse HTTP appropriée (200 OK, 404 Not Found, etc.). Cela inclut la gestion des méthodes GET, POST, DELETE, et l'exécution des scripts CGI si nécessaire.

```
std::string http_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html>...</html>";
write(new_socket, http_response.c_str(), http_response.length());
```

### Gestion des Entrées/Sorties Non Bloquantes

-   **Mise en place de `poll()`** : Utiliser `poll()` pour surveiller à la fois les opérations de lecture et d'écriture sur les sockets sans bloquer le serveur.
-   **Non-blocage** : Configurer les sockets pour qu'ils soient non-bloquants afin que le serveur reste réactif même sous une lourde charge.

### Gestion du Fichier de Configuration

-   **Analyse du fichier de configuration** : Écrire un parseur pour lire les paramètres de configuration (ports, routes, hôtes, etc.) et configurer le serveur en conséquence.
-   **Application des configurations** : Appliquer les configurations pour les différentes routes, les pages d'erreur personnalisées, les limitations de taille de corps, etc.

### Implémentation du CGI

-   **Exécution des scripts** : Lorsqu'une requête nécessite l'exécution d'un CGI (ex : script PHP), forker un nouveau processus pour exécuter le script et capturer sa sortie.

```
pid_t pid = fork();
if (pid == 0) {
	// Code enfant: exécuter le CGI
	execl("/usr/bin/php-cgi", "php-cgi", "script.php", NULL);
} else {
    // Code parent: récupérer la sortie du CGI
    waitpid(pid, &status, 0);
}
```

-   **Intégration avec HTTP** : Prendre la sortie du CGI, l'incorporer dans la réponse HTTP, et l'envoyer au client.

### Tests et Débogage

-   **Tests unitaires** : Écrire des tests pour vérifier chaque module (parsing des requêtes, génération des réponses, gestion des connexions, etc.).
-   **Tests de stress** : Simuler de lourdes charges pour s'assurer que le serveur reste stable.
-   **Comparaison avec NGINX** : Comparer les réponses du serveur avec celles d'un serveur comme NGINX pour s'assurer de la conformité.

### Optimisations et Bonus

-   **Optimisation des performances** : Améliorer la gestion des ressources et la rapidité du serveur.
-   **Implémentation des fonctionnalités bonus** : Ajouter la gestion des sessions, des cookies, ou d'autres fonctionnalités avancées.

<p>&nbsp;</p>

# V. CGI
Le **CGI** (Common Gateway Interface) est un standard qui permet à un serveur web d'interagir avec des programmes externes pour générer du contenu dynamique. Voici comment cela fonctionne et son rôle dans un serveur HTTP :

### Fonctionnement de CGI

1.  **Demande HTTP** :
    
    -   Lorsqu'un utilisateur envoie une requête HTTP pour une page web qui nécessite du contenu dynamique (par exemple, un formulaire de contact ou un script PHP), le serveur web ne peut pas simplement retourner un fichier statique comme il le ferait pour une image ou une page HTML. Il doit exécuter un programme ou un script pour générer ce contenu.
2.  **Exécution du programme CGI** :
    
    -   Le serveur web utilise CGI pour appeler un programme externe ou un script (comme un script Python, PHP, Perl, etc.). Ce programme est généralement situé sur le serveur lui-même.
    -   Le serveur passe les informations de la requête (telles que les données du formulaire, les variables d'environnement, etc.) au programme CGI via des variables d'environnement ou en utilisant l'entrée standard (stdin).
3.  **Réponse du programme** :
    
    -   Le programme CGI traite les données, effectue les calculs ou accède à une base de données si nécessaire, puis génère un contenu, généralement sous la forme de HTML.
    -   Ce contenu est renvoyé au serveur web via la sortie standard (stdout).
4.  **Transmission au client** :
    
    -   Le serveur web reçoit la sortie du programme CGI, qui inclut généralement des en-têtes HTTP suivis du contenu généré.
    -   Ce contenu est ensuite envoyé au navigateur de l'utilisateur comme réponse à la requête HTTP.

### Exemple de flux CGI

1.  L'utilisateur soumet un formulaire web.
2.  Le serveur reçoit la requête et la transmet à un script CGI, par exemple, `process_form.cgi`.
3.  `process_form.cgi` récupère les données du formulaire, traite les informations (comme stocker des données dans une base de données), et génère une page HTML de confirmation.
4.  Le serveur web envoie cette page générée au navigateur de l'utilisateur.

### Importance et Utilisation

-   **Simplicité** : CGI est l'un des moyens les plus simples d'ajouter du contenu dynamique à un site web.
-   **Portabilité** : Étant donné que CGI peut exécuter tout programme qui fonctionne en ligne de commande, il est très flexible et peut être utilisé dans différents environnements.
-   **Historique** : CGI est l'une des premières méthodes utilisées pour créer des pages web dynamiques, mais il a été largement remplacé par des technologies plus modernes comme les servlets, PHP, et les frameworks web.

### Limites

-   **Performance** : Chaque requête CGI implique le lancement d'un nouveau processus, ce qui peut être coûteux en termes de ressources système, particulièrement pour des serveurs à haute charge.
-   **Sécurité** : Si le programme CGI n'est pas bien sécurisé, il peut être vulnérable aux attaques, comme l'injection de commandes.

En résumé, CGI permet à un serveur web d'exécuter des programmes externes pour générer des réponses dynamiques, ce qui est crucial pour les applications web interactives.
