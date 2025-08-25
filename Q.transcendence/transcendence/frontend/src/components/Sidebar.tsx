import { Box, VStack, Text, HStack } from "@chakra-ui/react"
import { useState } from 'react'
import { useAuth } from '../context/Auth'
import { useNavigate } from "react-router-dom"
import { Link as RouterLink, useLocation } from 'react-router-dom'
import HomeIcon from "../assets/Sidebar/home.png"
import ProfileIcon from "../assets/Sidebar/profile.png"
import ScoreIcon from "../assets/Sidebar/scores.png"
import LogoutIcon from "../assets/Sidebar/logout.png"

const Sidebar = () => {
	const [isExpanded, setIsExpanded] = useState(false);
	const location = useLocation();
	const navigate = useNavigate();

	const menuItems = [
		{ icon: HomeIcon, label: 'Home', path: '/' },
		{ icon: ScoreIcon,
			label: 'Scores',
			path: useAuth().isLoggedIn ? '/scores' : '/login' },
		{ icon: ProfileIcon,
			label: 'Profile',
			path: useAuth().isLoggedIn ? '/profile' : '/login' },
		{ icon: LogoutIcon, label: 'Logout', 
			path: useAuth().isLoggedIn ? '/logout' : '/' },
	];

	return (
		<Box
			pos="fixed"
			left={0}
			bottom="50%"
			transform="translateY(50%)"
			bg="rgb(18 10 3 / 55%)"
			h="auto"
			w={isExpanded ? '150px' : '65px'}
			p={2}
			borderRadius="0 5px 5px 0"
			boxShadow="lg"
			transition="all 0.5s ease"
			zIndex={1000}
			onMouseEnter={() => setIsExpanded(true)}
			onMouseLeave={() => setIsExpanded(false)}
		>
			<VStack spacing={4} align="stretch">
				{menuItems.map((item) => (
					<RouterLink
					to={item.path}
					key={item.path}
					onClick={(e) => {
						if (item.path === '/login') {
							e.preventDefault();
							navigate('/login', { state: { from: location.pathname } });
						}
					}}
					>
						<HStack
							p={2}
							borderRadius="md"
							bg={location.pathname === item.path ? 'transparent' : 'transparent'}
							_hover="none"
							transition="all 0.5s"
						>
							<Box
								as="img"
								src={item.icon}
								alt={item.label}
								boxSize="45px"
								objectFit="contain"
							/>
							{isExpanded && (
								<Text ml={2} textAlign="center" fontSize="lg" fontWeight="500" fontFamily={"Gluten, cursive"} color="rgb(255 217 248 / 55%)" whiteSpace="nowrap">
									{item.label}
								</Text>
							)}
						</HStack>
					</RouterLink>
				))}
			</VStack>
		</Box>
	);
};

export default Sidebar;
