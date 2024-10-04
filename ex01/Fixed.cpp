/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:15 by erigolon          #+#    #+#             */
/*   Updated: 2024/10/04 14:26:39 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fp_number = 0;
	return ;
}

Fixed::Fixed(Fixed const&copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fp_number = copy.getRawBits();
	return ;	
}

Fixed::Fixed(const int fp_number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fp_number = fp_number << _fract;
}

Fixed::Fixed(const float fp_number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fp_number = roundf(fp_number * (1 << _fract));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fp_number = copy.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_number = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fp_number) / (1 << _fract));
}

int		Fixed::toInt(void) const
{
	return (this->_fp_number >> _fract);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}