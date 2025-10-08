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