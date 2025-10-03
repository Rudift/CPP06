/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 13:31:58 by vdeliere          #+#    #+#             */
/*   Updated: 2025-10-02 13:31:58 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char** av){
	if (ac != 2){
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	std::string input = av[1];
}