/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:50:14 by ilymegy           #+#    #+#             */
/*   Updated: 2024/12/05 19:50:30 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include "../inc/style.hpp"
#include <list>

int main()
{
	std::cout << SALM << "\nSubject test\n"<< RESET;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << PLUM <<  "top: \t"   RESET << mstack.top() << std::endl;

	mstack.pop();

	std::cout << PLUM <<  "size: \t"   RESET << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << PLUM <<  "stack: \t"   << RESET;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);



	std::cout << EMRD << "\nTest with std::list to compare\n"<< RESET;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << PLUM <<  "top: \t"   RESET << lst.back() << std::endl;

	lst.pop_back();

	std::cout << PLUM <<  "size: \t"   RESET << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lst_it = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();

	std::cout << PLUM <<  "list: \t"   << RESET;
	while (lst_it != lst_ite)
	{
		std::cout << *lst_it << " ";
		++lst_it;
	}
	std::cout << std::endl;


	std::cout << SALM << "\nTest with rbegin and rend\n"<< RESET;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	mstack.push(5);
	mstack.push(17);
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << PLUM <<  "stack: \t"   << RESET;
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
