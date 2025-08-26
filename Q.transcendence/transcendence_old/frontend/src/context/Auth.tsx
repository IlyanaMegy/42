import React, { createContext, useContext, useState, type ReactNode } from "react";

interface AuthType {
    isLoggedIn: boolean;
	login: () => void;
	logout: () => void;
}

const defaultAuthContext: AuthType = {
	isLoggedIn: false,
	login: () => {},
	logout: () => {},
};

const AuthContext = createContext<AuthType>(defaultAuthContext);
console.log('AuthContext created: ', AuthContext);

interface AuthProviderProps {
    children: ReactNode;
}

export const AuthProvider: React.FC<AuthProviderProps> = ({ children }) => {
	const [isLoggedIn, setIsLoggedIn] = useState(false);

	const login = () => {
		setIsLoggedIn(true);
	};

	const logout = () => {
		setIsLoggedIn(false);
	};

	return (
		<AuthContext.Provider value={{ isLoggedIn, login, logout }}>
			{children}
		</AuthContext.Provider>
	);
};

export const useAuth = (): AuthType => {
	const context = useContext(AuthContext);
	if (context == undefined) {
		throw new Error("useAuth must be used within an AuthProvider");
	}
	return context;
};



