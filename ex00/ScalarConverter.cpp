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
#include <sstream>

bool	isChar(const std::string &literal){
	if (literal.length() == 1){
		if (std::isprint(literal[0]))
			return (true);
		else
			std::cerr << "non-printable char" << std::endl;
	}
	return (false);
}

bool	isInt(const std::string &literal){
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

bool	isFloat(const std::string &literal){
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
	if (hasdot && std::isdigit(literal[i - 1]))
		return (true);
	return (false);
}

bool	isDouble(const std::string &literal){
	size_t	i = 0;
	bool	hasdot = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for(; i < literal.length(); i++){
		if (literal[i] == '.'){
			if (hasdot)
				return(false);
			hasdot = true;
		}
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	if (hasdot && std::isdigit(literal[i -1]))
		return (true);
	return (false);
}

void	convertChar(const std::string &literal){
	char	c = literal[0];

	std::cout << "char: '" << c << "'" <<std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	convertInt(const std::string &literal){
	int	value = 0;

	std::stringstream ss(literal);
	ss >> value;
	if (ss.fail())
		std::cerr << "Conversion failed" << std::endl;
	else{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		std::cout << "int:" << value << std::endl;
		std::cout << "float:" << static_cast<float>(value) << std::endl;
		std::cout << "double:" << static_cast<double>(value) << std::endl;
		// a tester
	}
	return ;
}

void 	ScalarConverter::convert(const std::string &literal){
	if (isChar(literal)){
		convertChar(literal);
	}else{
		std::cout << "Not a char bitch" << std::endl;
	}
}