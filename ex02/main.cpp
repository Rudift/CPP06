/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 13:41:14 by vdeliere          #+#    #+#             */
/*   Updated: 2025-10-08 13:41:14 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void){
	Base* a = new A;
	Base* b = new B;
	Base* c = new C;

	std::cout << "/------Test 1 : identification by pointers------/" << std::endl;
	Base::identify(a);
	Base::identify(b);
	Base::identify(c);

	delete a;
	delete b;
	delete c;
}