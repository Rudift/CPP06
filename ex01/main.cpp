/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-07 16:07:54 by vdeliere          #+#    #+#             */
/*   Updated: 2025-10-07 16:07:54 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(){
	Data		data = {42};
	uintptr_t	raw = Serializer::serialize(&data);
	Data*		ptr = Serializer::deserialize(raw);

	std::cout << "Data.x = " << ptr->intValue << std::endl;
	std::cout << "Adresse originale : " << &data << std::endl;
	std::cout << "Adresse deserialisee : " << ptr << std::endl;
}