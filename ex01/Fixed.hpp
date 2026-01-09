/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:10:02 by taya              #+#    #+#             */
/*   Updated: 2026/01/09 01:10:03 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
  private : 
      int raw;
      static const int fractionalbits = 8;
  
  public :
      Fixed();
      Fixed(const int n);
      Fixed(const float f);
      Fixed(const Fixed& other);
      Fixed& operator=(const Fixed& other);
      ~Fixed();

      int getRawBits( void ) const;
      void setRawBits( int const raw );

      float toFloat( void ) const;
      int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif