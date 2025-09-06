# Presentation Module Framework or toolkit to build the front-end

Ce module exige que le frontend soit développé en ***TypeScript*** (comme base de code) et utilise ***Tailwind CSS*** en complément, sans rien d'autre. 

Ce module permet un développement frontend moderne, rapide et maintenable :
- ***TypeScript*** apporte la sécurité des types pour éviter les erreurs runtime
- ***Tailwind CSS*** offre un système de classes utilitaires pour des styles cohérents et responsives sans CSS personnalisé lourd. 

Cela respecte les contraintes du sujet (pas de frameworks complets comme React, juste ***TypeScript*** + ***Tailwind***) et s'aligne avec les exigences de l'application **SPA**.

Le module fonctionne parfaitement : l'application se lance sans erreurs, les pages se chargent dynamiquement, les interactions utilisateur (navigation, formulaires, jeu) sont fluides, et tout est compatible avec Firefox. Aucune erreur visible, et les styles sont appliqués correctement via ***Tailwind***.

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
`<main id="app">` est rempli dynamiquement par les pages (via `router/index.ts`). Les liens dans `<nav>` utilisent `onclick="navigate('/path')"` pour changer de page sans rechargement.

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



Autres pages du frontend :
- `pages/dashboard.ts` (page tableau de bord avec stats, amis, paramètres)
- `pages/auth/gdpr.ts` (page politique de confidentialité)
- `pages/game/gameSelection.ts` (page de sélection options de jeu)
- `pages/game/pong/index.ts` (page de jeu avec canvas et logique de jeu)
- `pages/game/tournament/tournament.ts` (page tournoi avec liste de matchs)
- `pages/auth/login.ts`/`pages/auth/register.ts` (page de login/registration avec formulaire et redirection OAuth)
- `styles.css` importe ***Tailwind*** (`@tailwind base; @tailwind components; @tailwind utilities;`) et ajoute des styles personnalisés pour des éléments spécifiques (ex. : .`dropdown-menu` pour les menus déroulants, `.game-canvas` pour le canvas du jeu).