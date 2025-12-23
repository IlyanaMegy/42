/* *****************************************************************************/ 
/*                                                                             */ 
/*                                                         :::      ::::::::   */ 
/*    MutantStack.tpp                                    :+:      :+:    :+:   */ 
/*                                                     +:+ +:+         +:+     */ 
/*    By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */ 
/*                                                 +#+#+#+#+#+   +#+           */ 
/*    Created: 2024/12/05 19:55:27 by ilymegy           #+#    #+#             */ 
/*    Updated: 2024/12/05 19:55:28 by ilymegy          ###   ########.fr       */ 
/*                                                                             */ 
/* *****************************************************************************/ 

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src): std::stack<T>(src){}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){return  (std::stack<T>::c.begin()); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){return  (std::stack<T>::c.end()); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {return (std::stack<T>::c.begin());}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {return (std::stack<T>::c.end());}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {return (std::stack<T>::c.rbegin());}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){return (std::stack<T>::c.rend());}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {return (std::stack<T>::c.rbegin());}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {return (std::stack<T>::c.rend());}
