// import { Modal } from 'flowbite'
// import type { ModalOptions, ModalInterface } from 'flowbite'

// const $buttonElement = document.querySelector('[data-modal-toggle="authentication-modal"]');
// const $modalElement = document.getElementById('authentication-modal');

// const modalOptions: ModalOptions = {
//     placement: 'top-right'
// }

// if ($buttonElement && $modalElement) {
//   const modal: ModalInterface = new Modal($modalElement, modalOptions);
//   $buttonElement.addEventListener('click', () => modal.toggle());

//   // Sélectionne le bouton de fermeture (croix)
//   const $closeButton = $modalElement.querySelector('[data-modal-hide="authentication-modal"]');
//   if ($closeButton) {
//     $closeButton.addEventListener('click', () => {
//       modal.hide();
//       // Supprime l’overlay Flowbite s’il existe
//       const overlay = document.querySelector('.bg-gray-900\/50, .bg-gray-900\/80');
//       if (overlay) overlay.remove();
//     });
//   }
// }