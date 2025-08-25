import { VStack, Image } from '@chakra-ui/react';
import logo from '../assets/HomePage/logo.png';
import DemoPong from '../components/DemoPong.tsx';
import background from '../assets/HomePage/demo_bg_smaller.png';

const Home = () => {
	return (
		<VStack 
			minH="92vh"
			justify="space-around" 
			// spacing={12} 
			px={4}
			bg="#E2DDD7"
			color="black"
		>
			<Image 
				src={logo} 
				alt="Pong Logo" 
				maxW="450px"
			/>

			<DemoPong
				backgroundImage={background}
				animationUrl="https://lottie.host/0614a9ce-8d47-462c-a5ed-fd71b89da7dc/lAYQJ0DvD0.lottie"
				width="100%"
				maxW="800px"
				mx="auto"
				opacity={0.6}
				mb={8}
			/>
      {/* <Button 
        as={RouterLink} 
        to="/login" 
        colorScheme="teal" 
        size="lg"
        px={8}
      >
        Commencer à jouer
      </Button> */}
    	</VStack>
  );
};

export default Home;