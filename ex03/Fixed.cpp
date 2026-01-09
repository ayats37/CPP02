/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:57:38 by taya              #+#    #+#             */
/*   Updated: 2026/01/09 01:16:35 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : raw(0){
}

Fixed::Fixed(const int n){
  raw = n << fractionalbits;
}

Fixed::Fixed(const float f){
    raw = (int)roundf(f * (1 << fractionalbits));
}

Fixed::Fixed(const Fixed& other){
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
  if (this != &other)
    this->raw = other.getRawBits();
  return *this;
}

Fixed::~Fixed(){
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

bool Fixed::operator<(const Fixed& other)const{
  return (raw < other.raw);
}
bool Fixed::operator>(const Fixed& other)const{
  return (raw > other.raw);
}
bool Fixed::operator<=(const Fixed& other)const{
  return (raw <= other.raw);
}
bool Fixed::operator>=(const Fixed& other)const{
  return (raw >= other.raw);
}
bool Fixed::operator==(const Fixed& other)const{
  return (raw == other.raw);
}
bool Fixed::operator!=(const Fixed& other)const{
  return (raw != other.raw);
}

Fixed Fixed::operator+(const Fixed& other) const{
  Fixed add;
  add.raw = raw + other.raw;
  return add;
}


Fixed Fixed::operator-(const Fixed& other) const{
  Fixed subs;
  subs.raw = raw - other.raw;
  return subs;
}

Fixed Fixed::operator*(const Fixed& other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {     
  ++raw;
  return *this;
}

Fixed Fixed::operator++(int) {     
  Fixed tmp(*this);
  ++raw;
  return tmp;
}

Fixed& Fixed::operator--() {       
  --raw;
  return *this;
}

Fixed Fixed::operator--(int) {      
  Fixed tmp(*this);
  --raw;
  return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a > b) ? a : b;
}
