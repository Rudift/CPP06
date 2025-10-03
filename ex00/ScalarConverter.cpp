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

bool	ft_isalpha(const std::string &s){
	for (std::string::size_type i = 0; i < s.size(); ++i){
		if(!std::isalpha(static_cast<unsigned char>(s[i])))
			return (false);
	}
	return (!s.empty());
}

bool	ft_isnum(const std::string &s){
	for (std::string::size_type i = 0; i < s.size(); ++i){
		if(!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	}
	return (!s.empty());
}

bool	ft_isfloat(const std::string &s){
	for(std::string::size_type i = 0; i < s.size(); ++i){

	}
}

void ScalarConverter::convert(const std::string &literal){

}