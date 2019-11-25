#include "../include/ComplexNumbers.h"
#include <math.h>
#include <iostream>

/**
 * Empty constructor for ComplexNumbers class
 * It initializes ComplexNumber object with x=0 and y=0
 */
ComplexNumbers::ComplexNumbers()
{
    ComplexNumbers(0.,0.);
}

/** 
 * Constructor for ComplexNumbers class
 * It initializes ComplexNumber object with given x and y,
 * For initializing with euler or polar form, type should be 
 * specified as type!=1
 */
ComplexNumbers::ComplexNumbers(double x ,double y, int type)
{
    if(type==1)
	{
		_x	= x;
		_y	= y;
		ComputePolar();
	}

	else
	{
		_r	= x;
		_phi	= y;
		ComputeCartesian();
	}
}

/** 
 * Copy constructor for ComplexNumbers class
 */
ComplexNumbers::ComplexNumbers(const ComplexNumbers& other)
{
    _x      = other._x;
    _y      = other._y;
    _phi    = other._phi;
    _r      = other._r;
}

/** 
 * '=' operator for ComplexNumbers class
 */
ComplexNumbers& ComplexNumbers::operator=(const ComplexNumbers& rhs)
{
    if (this == &rhs) return *this;

    this->_x      = rhs._x;
    this->_y      = rhs._y;
    this->_phi    = rhs._phi;
    this->_r      = rhs._r;

    return *this;
}

/** 
 * '==' operator for ComplexNumbers class
 */
bool ComplexNumbers::operator==(const ComplexNumbers& rhs)
{
    if (this == &rhs) return true;

    if(this->_x      == rhs._x   &&
       this->_y      == rhs._y   &&
       this->_phi    == rhs._phi &&
       this->_r      == rhs._r)
       {return true;}

    return false;
}

/** 
 * Summation function 
 */
void ComplexNumbers::Sum(ComplexNumbers& j)
{
        _x += j._x;
        _y += j._y;

        ComputePolar();
}

/** 
 * Divide function 
 */
void ComplexNumbers::Divide(ComplexNumbers& j)
{
    ComplexNumbers tmp = j.ComplexConjugate();
    Multiply(tmp);

    *this = ComplexNumbers(_x /= j.Magnitude(),_y /= j.Magnitude());
}

/** 
 * Multiply function 
 */
void ComplexNumbers::Multiply(ComplexNumbers& j)
{
    *this = ComplexNumbers(_x*j._x - _y*j._y, _x*j._y + _y*j._x);
}

/** 
 * Subtraction function 
 */
void ComplexNumbers::Subtract(ComplexNumbers& j)
{
    *this = ComplexNumbers(_x-j._x,_y-j._y);
}

/** 
 * Function for computing polar form
 * Since polar and euler form parameters are equal, 
 * it can be used to compute euler form
 */
void ComplexNumbers::ComputePolar()
{
    _r      = sqrt(_x*_x + _y*_y);
    _phi    = atan2(_y, _x);
}

/** 
 * Function for computing cartesian form
 */
void ComplexNumbers::ComputeCartesian()
{
    _x = _r*cos(_phi);
    _y = _r*sin(_phi);
}

/** 
 * Function for computing complex conjugate,
 * it returns the result as a ComplexNumbers object
 */
ComplexNumbers ComplexNumbers::ComplexConjugate()
{
    ComplexNumbers tmp(_x,-_y);
    return tmp;
}

/** 
 * Function for computing magnitude
 */
double ComplexNumbers::Magnitude()
{
    return _r;
}

/** 
 * Function for n power
 */
void ComplexNumbers::Power(double n)
{
    double r_n   = pow(_r,n);
    double phi_n = _phi*n;

    phi_n = NormalizeAngle(phi_n);

    *this = ComplexNumbers(r_n, phi_n,2);
}

/** 
 * Function for n root
 */
void ComplexNumbers::Root(double n)
{
    Power(1.0/n);
}

/** 
 * This function is a helper function for Root and Power functions
 */
double ComplexNumbers::NormalizeAngle(double angle)
{
    while( angle > PI )
    {
        angle -= PI;
    }

    while( angle < -PI )
    {
        angle += PI;
    }

    return angle;
}

