#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

# define PI           3.14159265358979323846  /* pi */

class ComplexNumbers
{
    public:
        ComplexNumbers();
        ComplexNumbers(double x ,double y, int type=1);
        ComplexNumbers(const ComplexNumbers& other);
        ComplexNumbers& operator=(const ComplexNumbers& other);
        bool operator==(const ComplexNumbers& rhs);
        
        void Sum(ComplexNumbers&);
        void Divide(ComplexNumbers&);
        void Multiply(ComplexNumbers&);
        double Magnitude();
        void Subtract(ComplexNumbers&);
        void ComputePolar();
        void ComputeCartesian();
        ComplexNumbers ComplexConjugate();
        void Power(double);
        void Root(double);
        double NormalizeAngle(double angle);

        double _x; //!< Real part of cartesian form
        double _y; //!< Imaginary part of cartesian form
        double _r; //!< Radius of polar form
        double _phi;//!< Angle of polar form
};

#endif // COMPLEXNUMBERS_H
