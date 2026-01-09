/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:57:11 by taya              #+#    #+#             */
/*   Updated: 2026/01/09 01:27:05 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : raw(0){
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n){
  std::cout << "Int constructor called" << std::endl;
  raw = n << fractionalbits;
}

Fixed::Fixed(const float f){
  std::cout << "Float constructor called" << std::endl;
  raw = (int)roundf(f * (1 << fractionalbits));
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
  return(this->raw);
}

void Fixed::setRawBits(int const raw)
{
  this->raw = raw; 
}

float Fixed::toFloat( void ) const
{
  return (float)raw / (float)(1 << fractionalbits);
}

int Fixed::toInt( void ) const
{
  return (raw >> fractionalbits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
  os << f.toFloat();
  return os;
}
