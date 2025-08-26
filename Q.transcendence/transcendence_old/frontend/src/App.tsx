import { Box, Container } from "@chakra-ui/react"
import { Routes, Route } from "react-router-dom"
import { AuthProvider } from "./context/Auth"
import background from "./assets/background.jpg"
import Home from "./pages/Home"
import Login from "./pages/Login"
import Register from "./pages/Register"
import Game from "./pages/Game"
import User from "./pages/User"
import Sidebar from "./components/Sidebar"

function App() {
  return (
    <AuthProvider>
    <Box 
      minH="100vh"
      sx={{
        bgImage: `url(${background})`,
        bgPosition: 'center',
        bgRepeat: 'no-repeat',
        bgSize: 'cover',
        position: 'relative',
      }}
      position="relative"
    >
      <Sidebar />
      <Container maxW="70%" py={8}>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/login" element={<Login />} />
          <Route path="/register" element={<Register />} />
          <Route path="/game" element={<Game />} />
          <Route path="/user/:id" element={<User />} />
        </Routes>
      </Container>
    </Box>
    </AuthProvider>
  )
}

export default App

// LEARNING
//
// App.tsx : point d'entrée logique de l'application
// Définition du layout (structure) principal
// Configuration des routes de l'application
