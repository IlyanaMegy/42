# Presentation Module — Framework or toolkit to build the front-end

This module requires that the frontend be developed in TypeScript (as the base language) and uses Tailwind CSS as the only styling system.

This module enables a modern, fast, and maintainable frontend development:
- TypeScript provides type safety to avoid runtime errors
- Tailwind CSS offers a utility-class system for consistent, responsive styles without heavy custom CSS

This respects the project constraints (no full frameworks like React, only TypeScript + Tailwind) and aligns with the requirements of the Single Page Application (SPA).

The module works correctly: the application starts without errors, pages load dynamically, user interactions (navigation, forms, game) are fluid, and everything is compatible with Firefox. No visible errors and styles are applied correctly via Tailwind.

## Fundamental definitions

### TypeScript: the project's primary language

TypeScript is a programming language developed by Microsoft that extends JavaScript by adding a static type system. It is a superset of JavaScript, which means any valid JavaScript code is also valid TypeScript.

Key characteristics:
- Static typing: defines types of variables, functions and objects at development time
- Compilation: TypeScript is transpiled to standard JavaScript before execution
- Error detection: type errors are caught at compile time rather than at runtime
- IntelliSense: advanced autocompletion and in-editor documentation

Concrete example from the project:

```typescript
export async function homePage(): Promise<string> {
  const user = await checkAuthStatus();
  return `<div>Welcome, ${user.display_name}!</div>`;
}
```

Advantages for the project:
- Prevents runtime errors (e.g., accessing a property of undefined)
- More maintainable and self-documenting code
- Safe refactoring thanks to type checks
- Better team collaboration through typed interfaces

### Tailwind CSS: the utility-first styling system

Tailwind CSS is a utility-first CSS framework that provides prebuilt classes to style HTML elements directly without writing custom CSS.

Utility-first principle:
- Each class corresponds to a specific CSS property
- Styles are composed by combining multiple utility classes
- No pre-styled components (unlike Bootstrap)

Concrete example from the project:

```html
<button class="bg-blue-600 text-white px-8 py-4 rounded-lg text-xl hover:bg-blue-700">
  Play Now
</button>
```

This single line is equivalent to:

```css
button {
  background-color: #2563eb;  /* bg-blue-600 */
  font-size: 1.25rem;         /* text-xl */
}
button:hover {
  background-color: #1d4ed8;  /* hover:bg-blue-700 */
}
```

Advantages for the project:
- Rapid development: no need to write CSS, everything is done in HTML/TypeScript
- Consistency: predefined palette for colors, spacing and sizes
- Responsive: conditional classes (e.g., `md:`, `lg:`) for different breakpoints
- Performance: only used classes are included in the final CSS (automatic purge)
- Maintainability: visual changes are visible directly in the code

Integration in the project:
- Imported via `styles.css` using the directives `@tailwind base; @tailwind components; @tailwind utilities;`
- Compiled automatically by Vite during the build
- Classes used directly in TypeScript-generated HTML templates (strings)

## Entry point: `index.html` (Application skeleton)

This is the main HTML file that defines the shell of the application. It imports the TypeScript entry (`main.ts`) and the styles (`styles.css`).

The structure is simple and uses Tailwind for layout (e.g., `bg-gray-900` for dark background, `flex flex-col` for vertical layout).

```text
<html>
├── <head> (metadata, imports)
└── <body class="bg-gray-900 text-white min-h-screen flex flex-col">
    ├── <nav> (navigation bar with title and auth status)
    └── <footer> (footer)
```

`<main id="app">` is populated dynamically by the pages (via `router/index.ts`). The main link (`<a href="/">`) is intercepted by `main.ts` and transformed into SPA navigation. Authentication buttons (Login/Register/Logout/Dashboard) are injected dynamically into `<div id="auth-status">` by `router/index.ts` with `onclick="navigate('/path')"`.

Why this matters: it establishes the SPA shell. The content inside `<main>` changes according to the route, while the surrounding structure stays fixed.

## TypeScript entry: `main.ts` (Initialization and auth handling)

The TypeScript entry point initializes the router, handles authentication (via OAuth tokens or local tokens), and configures global navigation.

It checks URL parameters (e.g., `access_token` for OAuth) and redirects to `/login` if the user is not authenticated.

Integration: called from `index.html`. It imports `router/index.ts` to manage routes and `services/index.ts` for authentication.

Key events:
- `DOMContentLoaded`: starts the initialization
- `navigate(path)`: global function to change route (pushes to history and renders the page)

Detailed explanation: this file ensures the app starts correctly. For example, it handles post-OAuth redirections by storing tokens in `localStorage`. Without it the app could not distinguish authenticated from unauthenticated users.

## Routing: `router/index.ts` (Page management and navigation)

Defines routes (e.g., `/` → `homePage`, `/dashboard` → `dashboardPage`) and manages dynamic rendering.

It injects the generated HTML into `<main id="app">` and attaches event listeners.

Key DOM updates: after rendering, `<main>` contains the HTML of the current page (for `/`, it is the content generated by `homePage`).

Events:
- `popstate`: handles browser back/forward
- `attachEventListeners()`: attaches page-specific listeners (e.g., button clicks)

Detailed explanation: this file is the core of the SPA. It uses `window.location.pathname` to match routes and calls page functions (e.g., `Pages.homePage()`). Event listeners are attached after rendering to avoid memory leaks.

## SPA concept: the page is loaded once and elements are shown/hidden based on interaction

In a Single Page Application (SPA) like this one, the page is loaded once at startup (via `index.html` and `main.ts`). Instead of reloading the page for each route, dynamic content is injected into `<main id="app">` through JavaScript/TypeScript.

Elements that are "invisible" are kept in the DOM but hidden with CSS classes such as `hidden` (from Tailwind) and toggled visible/invisible by user events.

Why this works:
- Enables smooth navigation without full page reloads
- Preserves the browser Back/Forward behavior via history API (the router listens to `popstate`)

Advantages:
- Performance (no repeated fetches for base HTML)
- Fluid UX
- Compatibility with routing (since `router/index.ts` listens to `popstate`)

Concrete example:
The match options UI progressively reveals choices (in `dashboard.ts`). The dashboard uses tabs to show different contents (Stats, Friends, Settings). The entire page is generated at once (`dashboardPage()`), but sections are hidden/visible using the `hidden` class and events.

DOM structure example:

```typescript
<div class="max-w-4xl mx-auto">
  <!-- Tabs (always visible) -->
  <div id="settings-content" class="tab-content hidden">...</div>  <!-- Hidden -->
</div>
```

How it progressively reveals content:
- On load: `stats-content` is visible (no `hidden`), others have `hidden`.
- Event: clicking `#friends-tab` → `attachDashboardListeners()` listens and toggles classes:

```ts
document.querySelectorAll('.tab-button').forEach(button => {
  button.addEventListener('click', (e) => { /* ... */ });
});
```

Result: user clicks "Friends" → `#friends-content` becomes visible, revealing options (friend search, list, pending requests).

This is progressive: first the tab, then the content unfolds without a reload.

It demonstrates a smooth UX: the page is "loaded" and choices appear progressively through interactions.

## Development example: Typing functions in `home.ts`

- `styles.css` imports Tailwind with `@tailwind base; @tailwind components; @tailwind utilities;` and adds some small custom styles for specific elements (e.g., `.dropdown-menu` for dropdowns, `.game-canvas` for the game canvas).