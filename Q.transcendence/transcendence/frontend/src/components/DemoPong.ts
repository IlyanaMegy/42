interface DemoPongOptions {
	backgroundImage?: string;
	width?: number;
	opacity?: number;
}

export class DemoPong {
	private element: HTMLElement;

	constructor(container: HTMLElement, options: DemoPongOptions = {}) {
		this.element = document.createElement('div');
		this.element.className = 'relative w-full pt-[56.25%] overflow-hidden';

		if (options.backgroundImage) {
			const bgDiv = document.createElement('div');
			bgDiv.className = 'relative w-full h-full bg-cover bg-center';
			
			const bgImage = document.createElement('div');
			bgImage.className = 'absolute top-0 left-0 w-full h-full bg-cover bg-center';
			bgImage.style.backgroundImage = `url(${options.backgroundImage})`;
			bgImage.style.opacity = options.opacity?.toString() || '1';
			
			bgDiv.appendChild(bgImage);
			this.element.appendChild(bgDiv);
		}
		
		container.appendChild(this.element);
	}
}
