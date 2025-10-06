/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 13:27:08 by vdeliere          #+#    #+#             */
/*   Updated: 2025-10-02 13:27:08 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>

bool	ischar(const std::string &literal){
	if (literal.length() == 1){
		if (std::isprint(literal[0]))
			return (true);
		else
			std::cerr << "non-printable char" << std::endl;
	}
	return (false);
}

bool	isint(const std::string &literal){
	size_t	i = 0;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for(; i < literal.length(); i++){
		if (!std::isdigit(literal[i])){
			return (false);
		}
	}
	return (true);
}

bool	isfloat(const std::string &literal){
	size_t	i = 0;
	bool	hasdot = false;

	if (literal[literal.length() - 1] != 'f')
		return (false);
		
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for(; i < literal.length() - 1; i++){
		if (literal[i] == '.'){
			if (hasdot)
				return(false);
			hasdot = true;
		}
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	if (hasdot)
		return (true);
	return (false);
}

// bool	isdouble(const std::string &literal){

// }

void ScalarConverter::convert(const std::string &literal){
	if (isfloat(literal)){
		std::cout << "well done" << std::endl;
	}else{
		std::cout << "too bad" << std::endl;
	}
}