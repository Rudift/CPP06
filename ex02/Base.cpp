/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 09:25:29 by vdeliere          #+#    #+#             */
/*   Updated: 2025-10-08 09:25:29 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base*	Base::generate(void){
	static bool	init = false;
	if (!init){
		srand(static_cast<unsigned int>(time(0)));
		init = true;
	}
	int	r = rand() % 3;

	if (r == 0){
		return (new A);
	}else if (r == 1){
		return (new B);
	}else{
		return (new C);
	}
}

void Base::identify(Base* p){
	std::cout << "Identifaction by pointer" << std::endl;
	if (dynamic_cast<A*>(p)){
		std::cout << "Type of the object: A" << std::endl;
	}else if (dynamic_cast<B*>(p)){
		std::cout << "Type of the object: B" << std::endl;
	}else if (dynamic_cast<C*>(p)){
		std::cout << "Type of the object: C" << std::endl;
	}else{
		std::cout << "The object is not a child of Base" << std::endl;
	}
}

void Base::identify(Base& p){
	std::cout << "Identifaction by reference" << std::endl;
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type of the object: A" << std::endl;
		return ;
	}catch(...){
	}

	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type of the object: B" << std::endl;
		return ;
	}catch(...){
	}

	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type of the object: C" << std::endl;
		return ;
	}catch(...){
	}
}