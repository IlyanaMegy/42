import { Box, VStack, Input, Button, Text, Image, InputGroup, InputRightElement, IconButton } from "@chakra-ui/react";
import { useState } from "react";
import logo from "../assets/LoginPage/login_title.png"; // Assurez-vous d'avoir ce logo

const Login = () => {
	const [showPassword, setShowPassword] = useState(false);
	const [isRegister, setIsRegister] = useState(false);

	return (
		<Box
		minH="100vh"
		display="flex"
		justifyContent="center"
		alignItems="center"
		bg="rgb(203 185 163 / 92%)"
		p={4}
	>
		<Box
			w="100%"
			maxW="md"
			p={8}
			bg="white"
			borderRadius="md"
			boxShadow="x1"
			textAlign="center"
		>
			<Box mb={8}>
				<Image src={logo} alt="Pong Logo" maxW="200px" mx="auto" mb={2} />
			</Box>

			<VStack spacing={4}>
				<Input
					placeholder="name ?"
					size="lg"
					borderRadius="full"
					bg="aquamarine"
					border="none"
					_focus={{ bg: 'white', shadow: 'md' }}
				/>

				<InputGroup size="lg">
					<Input
						type={showPassword ? 'text' : 'password'}
						placeholder="password ?"
						borderRadius="full"
						bg="aquamarine"
						border="none"
						_focus={{ bg: 'white', shadow: 'md' }}
					/>
					<InputRightElement>
						<IconButton
							h="1.75rem"
							size="sm"
							onClick={() => setShowPassword(!showPassword)}
							aria-label="Show password"
							// icon={showPassword ? 'eye' : 'eye-slash'}
							variant="ghost"
						/>
					</InputRightElement>
				</InputGroup>

				<Button
					colorScheme="blue"
					size="lg"
					w="100%"
					borderRadius="full"
					_hover={{ transform: 'translateY(-2px)' }}
					transition="all 0.2s ease-in-out"
					
				>
					OK !
				</Button>

				<Text color="blue.600" mt={4}>
					New here ?
					<Button
						variant="link"
						color="blue.600"
						onClick={() => setIsRegister(true)}
					>
						Register
					</Button>
				</Text>
			</VStack>

			{isRegister && (
				<Box mt={8} pt={6} borderTopWidth={1} borderColor="gray.200">
					<Text fontSize="xl" fontWeight="bold" mb={4} color="gray.700">
						Créer un compte
					</Text>
					<VStack spacing={4}>
						<Input
							placeholder="Nom d'utilisateur"
							size="lg"
							borderRadius="full"
							bg="gray.100"
							border="none"
							_focus={{ bg: 'white', shadow: 'md' }}
						/>
						<Input
							type="email"
							placeholder="Email"
							size="lg"
							borderRadius="full"
							bg="gray.100"
							border="none"
							_focus={{ bg: 'white', shadow: 'md' }}
						/>
						<Input
							type="password"
							placeholder="Mot de passe"
							size="lg"
							borderRadius="full"
							bg="gray.100"
							border="none"
							_focus={{ bg: 'white', shadow: 'md' }}
						/>
						<Button
							colorScheme="green"
							size="lg"
							w="100%"
							borderRadius="full"
							_hover={{ transform: 'translateY(-2px)' }}
							transition="all 0.2s"
						>
							S'inscrire
						</Button>
						<Button
							variant="link"
							color="gray.500"
							onClick={() => setIsRegister(false)}
							size="sm"
						>
							Retour à la connexion
						</Button>
					</VStack>
				</Box>
			)}
			</Box>
		</Box>
	);
}

export default Login;
