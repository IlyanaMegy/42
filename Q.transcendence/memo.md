# Presentation Module Framework or toolkit to build the front-end

Ce module exige que le frontend soit développé en ***TypeScript*** (comme base de code) et utilise ***Tailwind CSS*** en complément, sans rien d'autre. 

Ce module permet un développement frontend moderne, rapide et maintenable :
- ***TypeScript*** apporte la sécurité des types pour éviter les erreurs runtime
- ***Tailwind CSS*** offre un système de classes utilitaires pour des styles cohérents et responsives sans CSS personnalisé lourd. 

Cela respecte les contraintes du sujet (pas de frameworks complets comme React, juste ***TypeScript*** + ***Tailwind***) et s'aligne avec les exigences de l'application **SPA**.

Le module fonctionne parfaitement : l'application se lance sans erreurs, les pages se chargent dynamiquement, les interactions utilisateur (navigation, formulaires, jeu) sont fluides, et tout est compatible avec Firefox. Aucune erreur visible, et les styles sont appliqués correctement via ***Tailwind***.

## Définitions fondamentales

### TypeScript : Le langage principal du projet

**TypeScript** est un langage de programmation développé par Microsoft qui étend JavaScript en y ajoutant un système de **typage statique**. C'est un "superset" de JavaScript, ce qui signifie que tout code JavaScript valide est aussi du TypeScript valide.

**Caractéristiques principales** :
- **Typage statique** : Définit le type des variables, fonctions et objets à l'écriture du code
- **Compilation** : Le code TypeScript est transpilé en JavaScript standard avant exécution
- **Détection d'erreurs** : Les erreurs de type sont détectées à la compilation, pas à l'exécution
- **IntelliSense** : Autocomplétion avancée et documentation dans les éditeurs

**Exemple concret dans le projet** :
```typescript
export async function homePage(): Promise<string> {
  const user = await checkAuthStatus();
  // TypeScript sait que 'user' peut être null ou un objet User
  if (!user) return '<h2>Welcome! Please login or register.</h2>';
  // TypeScript garantit que la fonction retourne toujours une string
  return `<div>Welcome, ${user.display_name}!</div>`;
}
```

**Avantages pour le projet** :
- Prévention des erreurs runtime (ex. : tentative d'accès à une propriété undefined)
- Code plus maintenable et documenté
- Refactoring sécurisé avec la vérification des types
- Meilleure collaboration en équipe grâce aux interfaces typées

### Tailwind CSS : Le système de styles utilitaires

**Tailwind CSS** est un framework CSS "utility-first" qui fournit des classes pré-construites pour styliser les éléments HTML directement, sans écrire de CSS personnalisé.

**Principe "utility-first"** :
- Chaque classe correspond à une propriété CSS spécifique
- Les styles sont composés en combinant plusieurs classes utilitaires
- Pas de composants pré-stylés (contrairement à Bootstrap)

**Exemple concret dans le projet** :
```html
<button class="bg-blue-600 text-white px-8 py-4 rounded-lg text-xl hover:bg-blue-700">
  Play Now
</button>
```
Cette seule ligne équivaut à :
```css
button {
  background-color: #2563eb;  /* bg-blue-600 */
  color: white;               /* text-white */
  padding: 2rem 0.75rem;      /* px-8 py-4 */
  border-radius: 0.5rem;      /* rounded-lg */
  font-size: 1.25rem;         /* text-xl */
}
button:hover {
  background-color: #1d4ed8;  /* hover:bg-blue-700 */
}
```

**Avantages pour le projet** :
- **Développement rapide** : Pas besoin d'écrire du CSS, tout se fait dans le HTML/TypeScript
- **Cohérence** : Palette de couleurs, espacements et tailles prédéfinis
- **Responsive** : Classes conditionnelles (`md:`, `lg:`) pour différents breakpoints
- **Performance** : Seules les classes utilisées sont incluses dans le CSS final (purge automatique)
- **Maintenabilité** : Modifications visuelles directement visibles dans le code

**Intégration dans le projet** :
- Importé via `styles.css` avec les directives `@tailwind base; @tailwind components; @tailwind utilities;`
- Compilé automatiquement par Vite lors du build
- Classes utilisées directement dans les templates TypeScript (strings HTML)

## Point d'entrée : `index.html` (Structure de base de l'application)

C'est le fichier HTML principal qui définit la coquille de l'application. Il importe le script ***TypeScript*** (`main.ts`) et les styles (`styles.css`).

La structure est simple et utilise ***Tailwind*** pour le layout (ex. : `bg-gray-900` pour le fond sombre, `flex flex-col` pour la disposition verticale).

```markdown
<html>
├── <head> (métadonnées, imports)
└── <body class="bg-gray-900 text-white min-h-screen flex flex-col">
    ├── <nav> (barre de navigation avec titre et statut auth)
    ├── <main id="app"> (contenu dynamique injecté par les pages)
    └── <footer> (pied de page)
```
`<main id="app">` est rempli dynamiquement par les pages (via `router/index.ts`). Le lien principal (`<a href="/">`) est intercepté par `main.ts` et transformé en navigation SPA. Les boutons d'authentification (Login/Register/Logout/Dashboard) sont injectés dynamiquement dans `<div id="auth-status">` par `router/index.ts` avec `onclick="navigate('/path')"`.

**Pourquoi pertinent** : Cela établit la base SPA. Le contenu de `<main>` change selon la route, mais la structure reste fixe.

## Entrée ***TypeScript*** : `main.ts` (Initialisation et gestion de l'authentification)

Point d'entrée ***TypeScript*** qui initialise le routeur, gère l'authentification (via tokens OAuth ou locaux), et configure la navigation globale. 

Il vérifie les paramètres URL (ex. : `access_token` pour OAuth) et redirige vers `/login` si non authentifié.

**Intégration** : Appelé depuis `index.html`. Il importe `router/index.ts` pour gérer les routes et `services/index.ts` pour l'auth.

**Événements clés** :
- `DOMContentLoaded` : Lance l'initialisation.
- `navigate(path)` : Fonction globale pour changer de route (ajoute à l'historique et rend la page).

**Explication poussée** : Ce fichier assure que l'app démarre correctement. Par exemple, il gère les redirections `post-OAuth` en stockant les tokens dans `localStorage`. Sans lui, l'app ne pourrait pas différencier utilisateurs authentifiés/non-authentifiés.

##  Routage : `router/index.ts` (Gestion des pages et navigation)

Définit les routes (ex. : / → `homePage`, /dashboard → `dashboardPage`) et gère le rendu dynamique. 

Il injecte le HTML généré dans `<main id="app">` et attache les événements.

**Arbre DOM mis à jour** : Après rendu, `<main>` contient le HTML de la page actuelle (ex. : pour /, c'est le contenu de `homePage`).

**Événements** :
- `popstate` : Gère le retour/avancer du navigateur.
- `attachEventListeners()` : Attache des listeners spécifiques à la page (ex. : clics sur boutons).

**Explication poussée** : Ce fichier est le cœur de la SPA. Il utilise `window.location.pathname` pour matcher les routes et appelle les fonctions de page (ex. : `Pages.homePage()`). Les événements sont attachés après rendu pour éviter les fuites mémoire.


## **Concept de SPA**: Toute la page est chargée, mais les éléments sont cachés/visibles selon les actions

Dans une Single Page Application (SPA) comme celle-ci, la page entière (HTML, CSS, JS) est chargée une seule fois au démarrage (via `index.html` et `main.ts`). Au lieu de recharger la page pour chaque route, le contenu dynamique est injecté dans `<main id="app">` via ***JavaScript*** / ***TypeScript***.

Les éléments "invisibles" sont stockés dans le DOM mais masqués avec des classes CSS comme hidden (de ***Tailwind***), et rendus visibles/invisibles via des événements utilisateur.

### Pourquoi ça fonctionne : 

Cela permet une navigation fluide sans rechargement, respectant la contrainte SPA du sujet (utilisation des boutons Back/Forward du navigateur). Les éléments cachés sont générés à l'avance (ex. : lors du rendu de `dashboardPage()`) mais ne sont affichés que sur interaction.

### Avantages :

- Performance (pas de requêtes répétées pour le HTML de base), 
- fluidité UX
- compatibilité avec le routage (via `index.ts` qui écoute popstate pour Back/Forward).

### Exemple concret :

Système de choix pour les matchs avec options qui se proposent petit à petit (dans `dashboard.ts`)
Dans `dashboard.ts`, le dashboard utilise des onglets (tabs) pour afficher différents contenus (Stats, Amis, Paramètres). 
Toute la page est chargée d'un coup (HTML généré par `dashboardPage()`), mais les sections sont cachées/visibles via des classes hidden et des événements.

Structure DOM :

```typescript
<div class="max-w-4xl mx-auto">
  <!-- Onglets (toujours visibles) -->
  <div class="flex border-b border-gray-700 mb-6">
    <button id="stats-tab" class="tab-button active ...">Statistics</button>
    <button id="friends-tab" class="tab-button ...">Friends</button>
    <button id="settings-tab" class="tab-button ...">Settings</button>
  </div>
  
  <!-- Contenus (cachés par défaut) -->
  <div id="stats-content" class="tab-content">...</div>  <!-- Visible par défaut -->
  <div id="friends-content" class="tab-content hidden">...</div>  <!-- Caché -->
  <div id="settings-content" class="tab-content hidden">...</div>  <!-- Caché -->
</div>
```

Comment ça se révèle petit à petit :

**Au chargement** : stats-content est visible (`class="tab-content"` sans hidden), les autres ont hidden.

**Événement** : Clic sur `#friends-tab` → Fonction `attachDashboardListeners()` écoute et bascule :

```ts
document.querySelectorAll('.tab-button').forEach(button => {
  button.addEventListener('click', (e) => {
    const tabId = (e.target as HTMLElement).id;  // ex. 'friends-tab'
    const contentId = tabId.replace('-tab', '-content');  // 'friends-content'
    
    // Masquer tous les contenus
    document.querySelectorAll('.tab-content').forEach(content => {
      content.classList.add('hidden');
    });
    
    // Afficher le contenu sélectionné
    document.getElementById(contentId)?.classList.remove('hidden');
    
    // Mettre à jour l'onglet actif (classes CSS)
    // ...
  });
});
```

**Résultat** : L'utilisateur clique sur "Friends" → `#friends-content` devient visible, révélant les options (recherche d'amis, liste, demandes en attente).

**C'est progressif** : d'abord l'onglet, puis le contenu se déroule sans rechargement.

**Cela montre une UX fluide** : la page est "chargée" mais les choix se proposent petit à petit via des interactions (clics), évitant une surcharge initiale.

## Développement de l'exemple : Typage des fonctions dans `home.ts`

Je vais développer l'exemple que vous avez fourni, en expliquant en détail les mots techniques spécifiques à JavaScript (JS) et TypeScript (TS). L'exemple se concentre sur la fonction `homePage()` dans `pages/home.ts`, qui illustre comment TypeScript améliore la robustesse du code en typant les fonctions asynchrones. Je vais décomposer chaque élément technique, avec des définitions claires et des exemples pratiques.

### Rappel de l'exemple
Voici la fonction en question :

```typescript
export async function homePage(): Promise<string> {
  const user = await checkAuthStatus();
  if (!user) return '<h2>Welcome! Please login or register.</h2>';
  return `
    <div class="text-center py-20">
      <h2 class="text-4xl mb-8">Welcome, ${user.display_name}!</h2>
      <button id="play-now-btn" class="bg-blue-600 text-white px-8 py-4 rounded-lg text-xl hover:bg-blue-700">
        Play Now
      </button>
    </div>
  `;
}
```

Cette fonction génère du HTML pour la page d'accueil, en vérifiant d'abord l'authentification de l'utilisateur. Elle est typée en TypeScript pour garantir que le retour est une chaîne de caractères (le HTML).

### Explication des mots techniques spécifiques à JS et TypeScript

1. **`async`** (JavaScript - Asynchrone) :
   - **Définition** : Mot-clé en JS qui marque une fonction comme asynchrone. Cela signifie que la fonction peut contenir des opérations qui prennent du temps (comme des appels API), et elle retourne automatiquement une **Promise** (voir ci-dessous). Cela permet d'utiliser `await` à l'intérieur.
   - **Pourquoi ici** : `homePage` appelle `checkAuthStatus()`, qui est probablement une fonction asynchrone (elle contacte un serveur pour vérifier l'utilisateur). `async` permet d'attendre le résultat sans bloquer le reste du code.
   - **Exemple sans `async`** : Si on enlève `async`, `await checkAuthStatus()` causerait une erreur de syntaxe. Le code tournerait en parallèle, risquant un affichage incorrect si `user` n'est pas encore défini.

2. **`Promise<string>`** (TypeScript - Types génériques) :
   - **Définition** : En TS, `Promise<T>` est un type générique qui représente une valeur qui sera disponible dans le futur (asynchrone). `<string>` spécifie le type de la valeur résolue (ici, une chaîne de caractères). Une Promise peut être "pending" (en attente), "fulfilled" (résolue avec succès) ou "rejected" (échouée).
   - **Pourquoi ici** : `: Promise<string>` indique que `homePage` retourne une Promise qui résout vers un `string` (le HTML généré). Cela force le compilateur TS à vérifier que le retour est bien une string, évitant des erreurs comme retourner un objet par erreur.
   - **Exemple** : Si on oublie `: Promise<string>`, TS pourrait permettre un retour invalide (ex. : un nombre), causant une erreur runtime.

3. **`await`** (JavaScript - Asynchrone, avec `async`) :
   - **Définition** : Opérateur en JS (utilisable seulement dans une fonction `async`) qui "attend" la résolution d'une Promise. Il pause l'exécution de la fonction jusqu'à ce que la Promise soit résolue ou rejetée, puis continue avec la valeur.
   - **Pourquoi ici** : `await checkAuthStatus()` attend que la fonction d'authentification finisse (probablement une requête API), puis assigne le résultat à `user`. Sans `await`, `user` serait une Promise non résolue, causant des erreurs comme "Cannot read property 'display_name' of Promise".
   - **Exemple** : Dans un code synchrone, on utiliserait des callbacks ou `.then()`, mais `await` rend le code plus lisible.

4. **`checkAuthStatus()`** (JavaScript/TypeScript - Appel de fonction) :
   - **Définition** : C'est un appel à une fonction (probablement définie dans `services/index.ts`), qui vérifie l'état d'authentification (ex. : via un token dans `localStorage` ou une API). Elle est asynchrone, donc elle retourne une Promise.
   - **Pourquoi ici** : Elle fournit les données utilisateur pour personnaliser le HTML (ex. : afficher le nom si connecté).
   - **Lien avec TypeScript** : TS typerait probablement `checkAuthStatus` comme `() => Promise<User | null>`, forçant `user` à être traité comme un objet User ou null.

### Comment TypeScript évite les erreurs runtime
- **Sans TypeScript (JS pur)** : Les erreurs ne sont détectées qu'à l'exécution. Par exemple :
  - Si `checkAuthStatus()` retourne un objet au lieu d'un utilisateur, `user.display_name` causerait "TypeError: Cannot read property 'display_name' of object" à l'exécution, crashant l'app.
  - Si on oublie `await`, `user` serait une Promise, et l'interpolation `${user.display_name}` afficherait "[object Promise]", rendant la page inutilisable.
  - Le compilateur JS ne signale rien, donc ces bugs arrivent en production.

- **Avec TypeScript** : Le compilateur analyse statiquement le code avant exécution.
  - Il signale immédiatement : "Type 'object' is not assignable to type 'User'" si `checkAuthStatus` retourne le mauvais type.
  - Il force la correction : Vous devez ajuster le code (ex. : caster le type ou corriger la fonction) avant de compiler.
  - Cela transforme des erreurs runtime en erreurs de compilation, rendant le code plus fiable et réduisant les bugs en prod.


## Développement de l'utilisation de Tailwind CSS

### Qu'est-ce que Tailwind CSS ?
- **Définition** : Tailwind CSS est un framework CSS "utility-first" (priorité aux utilitaires). Au lieu d'écrire du CSS personnalisé pour chaque élément, il fournit des classes pré-définies pour des propriétés communes (ex. : `bg-blue-600` pour la couleur de fond, `flex` pour la disposition). Ces classes sont générées à la volée via des directives comme `@tailwind base;`.
- **Pourquoi "utility-first"** : Chaque classe correspond à une seule propriété CSS (ex. : `text-center` = `text-align: center`). Cela permet de composer des styles directement dans le HTML/TypeScript sans fichiers CSS lourds.
- **Avantages** : 
  - Rapide à utiliser
  - Responsive (avec des préfixes comme `md:` pour desktop)
  - Cohérent (palette de couleurs et espacements prédéfinis)
  - Léger (seulement les classes utilisées sont incluses dans le build)
  - Intégration avec TypeScript : Les classes sont des chaînes dans le code TS (ex. : dans les templates strings), et TS les traite comme des strings normales. Pas de conflit.
  - Permet un développement rapide sans CSS personnalisé lourd, aligné avec les exigences SPA (responsive, fluide).

### Comment Tailwind est intégré dans le projet ?
- **Fichier principal** : `styles.css` importe Tailwind via :
  ```css
  @tailwind base;
  @tailwind components;
  @tailwind utilities;
  ```
  - `@tailwind base` : Styles de base (reset, typographie).
  - `@tailwind components` : Pour des composants personnalisés (optionnel ici).
  - `@tailwind utilities` : Les classes utilitaires (principalement utilisées).
- **Build** : Le projet utilise Vite (via `vite.config.js`), qui compile Tailwind automatiquement. Les classes sont purgées (seulement celles utilisées sont incluses) pour optimiser la taille.
- **Utilisation** : Dans les fichiers TS (ex. : `pages/home.ts`), les classes sont injectées dans les templates HTML via des strings (ex. : `class="bg-blue-600 hover:bg-blue-700"`).

### Exemples concrets d'utilisation dans le code
Voici des exemples tirés des fichiers pour illustrer comment Tailwind est appliqué :

1. **Layout de base dans `index.html`** :
   ```html
   <body class="bg-gray-900 text-white min-h-screen flex flex-col">
   ```
   - `bg-gray-900` : Fond sombre (gris foncé).
   - `text-white` : Texte blanc.
   - `min-h-screen` : Hauteur minimale de l'écran.
   - `flex flex-col` : Disposition en colonne flexible (verticale).
   - **Pourquoi** : Crée une coquille responsive sans CSS personnalisé. `flex-col` assure que nav, main, footer s'empilent verticalement.

2. **Navigation dans `index.html`** :
   ```html
   <nav class="glass-header bg-gray-900 p-4">
   ```
   - `glass-header` : Classe personnalisée (définie dans `styles.css` pour un effet glass).
   - `bg-gray-900` : Fond gris.
   - `p-4` : Padding de 1rem autour.
   - **Intégration** : Combine utilitaires Tailwind avec une classe custom pour l'effet visuel.

3. **Boutons dans `pages/home.ts`** :
   ```typescript
   <button id="play-now-btn" class="bg-blue-600 text-white px-8 py-4 rounded-lg text-xl hover:bg-blue-700">
   ```
   - `bg-blue-600` : Fond bleu.
   - `text-white` : Texte blanc.
   - `px-8 py-4` : Padding horizontal/vertical.
   - `rounded-lg` : Bordures arrondies.
   - `text-xl` : Taille de texte grande.
   - `hover:bg-blue-700` : Changement de couleur au survol.
   - **Pourquoi** : Style complet en une ligne, responsive et interactif sans CSS externe.

4. **Masquage/affichage dans `dashboard.ts`** :
   ```typescript
   <div id="friends-content" class="tab-content hidden">
   ```
   - `hidden` : Masque l'élément (display: none).
   - **Utilisation** : Dans `attachDashboardListeners()`, on ajoute/retire `hidden` pour basculer la visibilité :
     ```typescript
     document.getElementById(contentId)?.classList.remove('hidden');
     ```
     - **Pourquoi** : Permet une UX fluide en SPA (éléments cachés révélés progressivement).

5. **Grille responsive dans `dashboard.ts`** :
   ```typescript
   <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
   ```
   - `grid` : Active le layout grille.
   - `grid-cols-1` : 1 colonne par défaut (mobile).
   - `md:grid-cols-2` : 2 colonnes sur écrans moyens+ (desktop).
   - `gap-6` : Espacement entre éléments.
   - **Pourquoi** : Responsive automatique, s'adapte aux devices sans media queries personnalisées.

### Avantages et bénéfices
- **Rapidité de développement** : Pas besoin d'écrire CSS ; composez directement dans le HTML/TS.
- **Cohérence** : Palette prédéfinie (ex. : `gray-900`, `blue-600`) assure un design uniforme.
- **Performance** : Purge automatique des classes inutiles, fichier CSS léger.
- **Responsive** : Préfixes comme `md:` pour breakpoints (mobile, tablet, desktop).
- **Évitement des erreurs** : Pas de conflits CSS ; chaque classe est isolée.
- **Intégration parfaite** : Fonctionne avec TypeScript (classes comme strings) et respecte le sujet (pas de framework complet).

Autres pages du frontend :
- `pages/dashboard.ts` (page tableau de bord avec stats, amis, paramètres)
- `pages/auth/gdpr.ts` (page politique de confidentialité)
- `pages/game/gameSelection.ts` (page de sélection options de jeu)
- `pages/game/pong/index.ts` (page de jeu avec canvas et logique de jeu)
- `pages/game/tournament/tournament.ts` (page tournoi avec liste de matchs)
- `pages/auth/login.ts`/`pages/auth/register.ts` (page de login/registration avec formulaire et redirection OAuth)
- `styles.css` importe ***Tailwind*** (`@tailwind base; @tailwind components; @tailwind utilities;`) et ajoute des styles personnalisés pour des éléments spécifiques (ex. : .`dropdown-menu` pour les menus déroulants, `.game-canvas` pour le canvas du jeu).