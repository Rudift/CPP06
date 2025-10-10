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

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& src){
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src){
	(void)src;
	return (*this);
}

ScalarConverter::ScalarConverter(){}

bool	isChar(const std::string &literal){
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (true);
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

	if (std::isprint(c))
		std::cout << "char: '" << c << "'" <<std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	convertInt(const std::string &literal){
	long	temp = 0;
	int		value = 0;

	std::stringstream ss(literal);
	ss >> temp;
	if (ss.fail() || temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else{
		value = static_cast<int>(temp);
		if (value < 0 || value > 255)
			std::cout << "char: impossible" << std::endl;
		else if (isDisplayable(value))
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

	if (literal == "nanf"){
		value = std::numeric_limits<float>::quiet_NaN();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inff"){
		value = std::numeric_limits<float>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inff"){
		value = -std::numeric_limits<float>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else{
		std::stringstream ss(literal);
		ss >> value;
		if (ss.fail()){
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		
		if (value < 0 || value > 255)
			std::cout << "char: impossible" << std::endl;
		else if (isDisplayable(static_cast<int>(value)))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		
		std::cout << "float: " << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << "f" << std::endl;
		
		std::cout << "double: " << static_cast<double>(value);
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void	convertDouble(const std::string &literal){
	double	value = 0;

	if (literal == "nan"){
		value = std::numeric_limits<double>::quiet_NaN();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf"){
		value = std::numeric_limits<double>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf"){
		value = -std::numeric_limits<double>::infinity();
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else{
		std::stringstream ss(literal);
		ss >> value;
		if (ss.fail()){
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		
		if (value < 0 || value > 255)
			std::cout << "char: impossible" << std::endl;
		else if (isDisplayable(static_cast<int>(value)))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		
		if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else{
			std::cout << "float: " << static_cast<float>(value);
			if (value == static_cast<int>(value))
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
		
		std::cout << "double: " << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void 	ScalarConverter::convert(const std::string &literal){
	if (isChar(literal)){
		convertChar(literal);
	}else if (isInt(literal)){
		convertInt(literal);
	}else if (isFloat(literal)){
		convertFloat(literal);
	}else if (isDouble(literal)){
		convertDouble(literal);
	}else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}