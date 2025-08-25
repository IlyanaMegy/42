import { Flex, Button, Box, Heading } from "@chakra-ui/react"
import { Link as RouterLink } from "react-router-dom"

const Nav = () => {
	const navLinkStyles = {
		variant: "ghost" as const,
		color: "white" as const,
		_hover: { bg: "blue.500" }
	}

	return (
		<Box bg="blue.600" px={4} py={3} color="white">
			<Flex justify="space-between" align="center" maxW="container.lg" mx="auto">
				<Heading size="lg">Pong 42</Heading>
				<Flex as="nav" gap={4}>
					<Button as={RouterLink} to="/" {...navLinkStyles}>
						Accueil
					</Button>
					{/* <Button as={RouterLink as any} to="/login" variant="ghost" color="white" _hover={{bg: 'blue.500' }}>
						Connexion
					</Button>
					<Button as={RouterLink} to="/register" variant="ghost" color="white" _hover={{bg: 'blue.500' }}>
						Inscription
					</Button> */}
				</Flex>
			</Flex>
		</Box>
	)
}

export default Nav
