import { Home } from './pages/Home';

document.addEventListener('DOMContentLoaded', () => {
  const app = document.querySelector<HTMLDivElement>('#app');
  if (app) {
    const homePage = new Home();
    homePage.render(app);
  }
});
