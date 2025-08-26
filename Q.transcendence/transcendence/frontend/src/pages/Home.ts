import { DemoPong } from "../components/DemoPong";

export class Home {
	private element: HTMLElement;

	constructor() {
		this.element = document.createElement('div');
		this.element.className = 'min-h-[92vh] flex flex-col justify-around px-4';
    this.element.style.backgroundColor = 'rgba(203, 185, 163, 0.92)';
    this.element.style.color = 'black';
    
    // Logo
    const logo = document.createElement('img');
    logo.src = '/assets/Home/logo.png';
    logo.alt = 'Pong Logo';
    logo.className = 'max-w-[450px] mx-auto';
    this.element.appendChild(logo);
    
    // Zone de jeu
    const gameContainer = document.createElement('div');
    this.element.appendChild(gameContainer);
    
    // Initialiser le jeu
    new DemoPong(gameContainer, {
      backgroundImage: '/assets/Home/demo_bg_smaller.png',
      opacity: 0.6
    });
  }
  
  render(container: HTMLElement) {
    container.appendChild(this.element);
  }
}
