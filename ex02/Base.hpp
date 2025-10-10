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
#  include <iostream>
#  include <exception>


class Base
{
	public:
		virtual 		~Base();
		static Base*	generate(void);
		static void		identify(Base* p);
		static void		identify(Base& p);
};



#endif