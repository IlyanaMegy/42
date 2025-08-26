import { Box, type BoxProps } from "@chakra-ui/react";
import { DotLottieReact } from "@lottiefiles/dotlottie-react";
import demo from "../assets/HomePage/demo.png";

interface DemoPongProps extends BoxProps {
	backgroundImage?: string;
	animationUrl?: string;
	opacity?: number;
}

const DemoPong = ({
	backgroundImage,
	animationUrl,
	opacity = 1,
	...rest
}: DemoPongProps) => {
	return (
		<Box pos="relative" width="100%" maxW="800px" mx="auto" {...rest}>
			{backgroundImage && (
				<Box position="relative" width="100%" pt="56.25%" overflow={"hidden"}>
					<Box
						position="absolute"
						top={0}
						left={0}
						width="100%"
						height="100%"
						backgroundImage={`url(${backgroundImage})`}
						backgroundSize="auto"
						backgroundPosition="center"
						backgroundRepeat="no-repeat"
						opacity={opacity}
					/>
					<Box
						position="absolute"
						top="-10%"
						left="-10%"
						width="120%"
						height="120%"
					>
						<DotLottieReact
							src={animationUrl}
							loop
							autoplay
							style={{width: '100%', height: '100%', objectFit: 'cover'}}
						/>
					</Box>
					<Box
						position="absolute"
						top="30px"
						right="150px"
						px={3}
						py={1}
						borderRadius="md"
						display="flex"
						alignItems="center"
						zIndex={10}
						transform="rotate(-5deg)"
						transformOrigin="center"
						_hover={{
							transform: "rotate(-5deg) scale(1.05)",
							transition: "transform 0.2s ease-in-out"
						}}
					  >
						<Box
						  as="img"
						  src={demo}
						  width="140px"
						  height="125px"
						  alt="Logo"
						/>
					</Box>
				</Box>
			)}
		</Box>
	);
};

export default DemoPong;