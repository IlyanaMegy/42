## 1. Structure du projet

```
transcendence/
├── frontend/          # Frontend en TypeScript + Tailwind (sans framework)
└── backend/           # Backend en Fastify + TypeScript + SQLite
```

## 2. Configuration du Frontend (TypeScript + Tailwind uniquement)
bash

# Créer le dossier frontend

```bash
mkdir -p frontend
cd frontend
```

# Initialiser le projet

```bash
npm init -y
```

# Installer TypeScript

```bash
npm install -D typescript
npx tsc --init
```

# Installer Vite pour le bundling (sans framework)

```bash
npm install -D vite @types/node
```

# Installer Tailwind

```bash
npm install -D tailwindcss postcss autoprefixer
npx tailwindcss init -p
```

# Créer la structure des dossiers

```bash
mkdir -p src/{components,pages,styles}
```

---

## Explication de Vite et du bundling

### Qu'est-ce que Vite ?

Vite est un outil de build moderne qui offre :

- Un serveur de développement extrêmement rapide
- Un système de build optimisé pour la production
- Le support natif des modules ES
- L'intégration avec TypeScript, JSX, CSS et plus

### Qu'est-ce qu'un bundler ?

Un bundler est un outil qui :

- Prend votre code source (fichiers JS/TS, CSS, etc.)
- Analyse les dépendances
- Combine tout en un ou plusieurs "bundles" optimisés
- Peut effectuer des optimisations comme le tree-shaking
- Respect des règles du sujet

Points clés :

- Vite n'est pas un framework comme React ou Angular, c'est un outil de build.
- Il ne fait pas le travail à votre place :
- Il ne fournit pas de logique métier
- Il ne crée pas de composants UI
- Il ne gère pas l'état de l'application

---

## Tailwind CSS vs CSS vs Bootstrap

### 1. CSS Traditionnel

Approche : Écrire du CSS personnalisé

Avantages :

- Contrôle total sur le style
- Pas de surcharge inutile

Inconvénients :

- Beaucoup de code répétitif
- Difficile à maintenir sur de gros projets
- Pas de système de design cohérent

### 2. Bootstrap

Approche : Framework CSS avec composants prédéfinis

Avantages :

- Composants UI prêts à l'emploi (boutons, cartes, etc.)
- Grille responsive intégrée
- Documentation complète

Inconvénients :

- Taille importante (même si personnalisable)
- Look "Bootstrap" reconnaissable
- Moins de flexibilité dans le design

### 3. Tailwind CSS

Approche : Utilitaire-first CSS framework

Avantages :

- Personnalisation : Créez votre propre design système
- Performance : Purge le CSS inutilisé
- Maintenabilité : Pas de conflits de classes
- Rapidité : Développement plus rapide une fois appris
- Responsive : Préfixes intégrés (md:, lg:, etc.)

Exemple de code comparatif

CSS Traditionnel

```css
/* styles.css */
.card {
  border-radius: 0.5rem;
  padding: 1rem;
  background-color: white;
  box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1);
}
```

Bootstrap

```html
<div class="card">
  <div class="card-body">
    Contenu
  </div>
</div>
```

Tailwind CSS

```html
<div class="rounded-xl p-4 bg-white shadow-sm">
  Contenu
</div>
```

Pourquoi choisir Tailwind pour ton projet ?

- Flexibilité : Crée un design unique sans être limité par des composants prédéfinis
- Performance : Génère uniquement le CSS utilisé
Workflow : Moins de changements de contexte entre HTML et CSS
- Maintenance : Pas de soucis de conflits de classes
Personnalisation : Facile à adapter au design system de ton projet

Inconvénients de Tailwind

- Courbe d'apprentissage initiale
- Le HTML peut devenir verbeux
- Nécessite une configuration initiale

Pour ton projet Transcendence, Tailwind est un excellent choix car :

- Tu peux créer une UI unique
- C'est léger et performant
- Tu gardes le contrôle total sur le design
- C'est parfait pour les applications web modernes

---

## Les Modals dans une Application Web

### Qu'est-ce qu'un Modal ?

Un modal est une fenêtre contextuelle qui s'affiche par-dessus le contenu principal de la page, généralement pour :

- Afficher des informations importantes
- Demander une confirmation
- Afficher un formulaire
- Montrer des détails supplémentaires

### Utilité dans ton Projet

Cas d'utilisation possibles :

- Authentification : Connexion/Inscription
- Paramètres : Modification du profil utilisateur
- Confirmation : Actions importantes (suppression, déconnexion)
- Détails : Afficher plus d'informations sur un élément
- Notifications : Messages d'erreur ou de succès

### Avantages

Expérience utilisateur : Garde l'utilisateur dans le même contexte

Attention ciblée : Focalise l'attention sur une action spécifique

Économie d'espace : Évite de surcharger l'interface

### Inconvénients

- Peut perturber le flux de navigation
- Peut être mal adapté aux petits écrans si mal conçu
- Peut rendre l'accessibilité plus complexe

### Recommandation

Oui, utilise des modals pour :
- Les formulaires de connexion/inscription
- Les confirmations d'actions importantes
- Les messages d'erreur/succès contextuels
- Les fenêtres de paramètres rapides

Évite les modals pour :
- Le contenu principal de l'application
- Les longs formulaires
- Les informations critiques qui doivent être toujours visibles

### Exemple d'implémentation simple

```typescript
// Exemple de composant Modal en TypeScript
class Modal {
  private modal: HTMLElement;
  
  constructor(content: string) {
    this.modal = document.createElement('div');
    this.modal.className = 'fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center hidden';
    this.modal.innerHTML = `
      <div class="bg-white p-6 rounded-lg max-w-md w-full">
        <div class="mb-4">${content}</div>
        <button class="px-4 py-2 bg-blue-500 text-white rounded">Fermer</button>
      </div>
    `;
    
    const closeButton = this.modal.querySelector('button');
    closeButton?.addEventListener('click', () => this.hide());
  }

  show() {
    this.modal.classList.remove('hidden');
    document.body.style.overflow = 'hidden';
  }

  hide() {
    this.modal.classList.add('hidden');
    document.body.style.overflow = '';
  }

  render() {
    document.body.appendChild(this.modal);
    return this;
  }
}

// Utilisation
const modal = new Modal('Contenu de la modale').render();
modal.show();
```

---
