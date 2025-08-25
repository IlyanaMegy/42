import React from 'react'
import ReactDOM from 'react-dom/client'
import { ChakraProvider } from '@chakra-ui/react'
import { BrowserRouter } from 'react-router-dom'
import App from './App'

ReactDOM.createRoot(document.getElementById('root')!).render(
	<React.StrictMode>															
		<BrowserRouter>
			<ChakraProvider>
				<App />
			</ChakraProvider>
		</BrowserRouter>
	</React.StrictMode>
)


// LEARNING
//
// main.tsx : point d'entrée technique de l'application
// Configuration initiale des providers essentiels
// Montage de l'application dans le DOM (maquette complète du site)



