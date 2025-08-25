import { Box, Container } from "@chakra-ui/react"
import { Routes, Route } from "react-router-dom"
// import Nav from "./components/Nav"

import Home from "./pages/Home"
import Login from "./pages/Login"
import Register from "./pages/Register"
import Game from "./pages/Game"
import User from "./pages/User"

function App() {
  return (
    <Box minH="100vh" bg="gray.100">
      {/* <Nav /> */}
      <Container maxW="container.lg" py={8}>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/login" element={<Login />} />
          <Route path="/register" element={<Register />} />
          <Route path="/game" element={<Game />} />
          <Route path="/user/:id" element={<User />} />
        </Routes>
      </Container>
    </Box>
  )
}

export default App

// LEARNING
//
// App.tsx : point d'entrée logique de l'application
// Définition du layout (structure) principal
// Configuration des routes de l'application
