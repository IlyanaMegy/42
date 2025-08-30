import { Modal } from 'flowbite';
import type { ModalOptions, ModalInterface } from 'flowbite';

document.addEventListener('DOMContentLoaded', () => {
  const $buttonElement = document.querySelector('[data-modal-toggle="authentication-modal"]');
  const $modalElement = document.getElementById('authentication-modal');

  const modalOptions: ModalOptions = {
    placement: 'center',
  };

  if ($buttonElement && $modalElement) {
    const modal: ModalInterface = new Modal($modalElement, modalOptions);
    $buttonElement.addEventListener('click', () => modal.toggle());

    // Sélectionne le bouton de fermeture (croix)
    const $closeButton = $modalElement.querySelector('[data-modal-hide="authentication-modal"]');
    if ($closeButton) {
      $closeButton.addEventListener('click', () => {
        modal.hide();
        // Ne pas manipuler l’overlay manuellement
      });
    }
  }
});