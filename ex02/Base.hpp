/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 09:23:11 by vdeliere          #+#    #+#             */
/*   Updated: 2025-10-08 09:23:11 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#  include <iostream>
#  include <cstdlib>
#  include <ctime>

class Base
{
	public:
		virtual ~Base();
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};



#endif