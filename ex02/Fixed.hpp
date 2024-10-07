/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:08 by erigolon          #+#    #+#             */
/*   Updated: 2024/10/07 11:29:08 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:

	int					_fp_number;
	static const int	_fract = 8;
	
public:

	Fixed(void);
	Fixed(Fixed const& copy);
	Fixed(const int fp_number);
	Fixed(const float fp_number);
	
	~Fixed(void);
	
	Fixed&	operator=(const Fixed& copy);

	bool	operator>(const Fixed& compare) const;
	bool	operator<(const Fixed& compare) const;
	bool	operator>=(const Fixed& compare) const;
	bool	operator<=(const Fixed& compare) const;
	bool	operator==(const Fixed& compare) const;
	bool	operator!=(const Fixed& compare) const;

	Fixed	operator+(const Fixed& arith) const;
	Fixed	operator-(const Fixed& arith) const;
	Fixed	operator*(const Fixed& arith) const;
	Fixed	operator/(const Fixed& arith) const;

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif