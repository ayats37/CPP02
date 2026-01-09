/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:56:58 by taya              #+#    #+#             */
/*   Updated: 2026/01/09 00:56:59 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : raw(0){
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->raw = other.getRawBits();
  return *this;
}

Fixed::~Fixed(){
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return(this->raw);
}

void Fixed::setRawBits(int const raw)
{
  this->raw = raw; 
}