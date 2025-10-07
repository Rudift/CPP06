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
#include <limits>

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

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (true);

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

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (true);

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

bool	isDisplayable(const int i){
	if (!std::isprint(i))
		return (false);
	return (true);
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
	if (ss.fail()){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else{
		if (isDisplayable(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;		
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	}
	return ;
}

void	convertFloat(const std::string &literal){
	float	value = 0;

	if (literal == "nanf")
		value = std::numeric_limits<float>::quiet_NaN();
	else if (literal == "+inf")
		value = std::numeric_limits<float>::infinity();
	else if (literal == "-inf")
		value = -std::numeric_limits<float>::infinity();
	else{
		std::stringstream ss(literal);
		ss >> value;
		if (ss.fail())
			std::cerr << "Conversion failed" << std::endl;
		else{
			if (isDisplayable(value))
				std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(value) << std::endl;
			std::cout << "float: " << value << std::endl;
			std::cout << "double: " << static_cast<double>(value) << std::endl;
		}
	}
}

void	convertDouble(const std::string &literal){
	float	value = 0;

	if (literal == "nanf")
		value = std::numeric_limits<float>::quiet_NaN();
	else if (literal == "+inf")
		value = std::numeric_limits<float>::infinity();
	else if (literal == "-inf")
		value = -std::numeric_limits<float>::infinity();
	else{
		std::stringstream ss(literal);
		ss >> value;
		if (ss.fail())
			std::cerr << "Conversion failed" << std::endl;
		else{
			if (isDisplayable(value))
				std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(value) << std::endl;
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
			std::cout << "double: " << value << std::endl;
		}
	}
}

void 	ScalarConverter::convert(const std::string &literal){
	if (isChar(literal)){
		std::cout << "C'est un char" << std::endl;
		convertChar(literal);
	}else if (isInt(literal)){
		std::cout << "C'est un int" << std::endl;
		convertInt(literal);
	}else if (isFloat(literal)){
		std::cout << "C'est un float" << std::endl;
		convertFloat(literal);
	}else if (isDouble(literal)){
		std::cout << "C'est un double" << std::endl;
		convertDouble(literal);
	}else{
		
	}
}