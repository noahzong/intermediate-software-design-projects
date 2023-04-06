// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <cmath>
#include <iterator>
#include <sstream>
#include <stdexcept>

template <uint32_t dim> class Vector {
public:
    /**
     * Default Constructor
     * Initializes a vector of dimension "dim" and sets every element to 0
     */
    Vector();

    /**
     * Alternate Constructor
     * Initializes a vector of dimension "dim" and sets its elements to the parameter array
     * @param arr A constant array of doubles which are the vector's elements
     */
    explicit Vector(const double arr[]);

    /**
     * Compiler Default Copy Constructor
     */
    Vector(const Vector<dim>&) = default;

    /**
     * Compiler Default Destructor
     */
    ~Vector() noexcept = default;

    /**
     * Compiler Default Assignment Operator
     * @param rhs The object that is being assigned to this
     * @return *this
     */
    Vector<dim>& operator=(const Vector<dim>& rhs) = default;

    /**
     * Returns the vector as a string
     * @return the vector as a string
     */
    std::string toString() const;

    /**
     * Adds one vector to another by adding each of their elements
     * @param v The vector to be added
     * @return The vector added together
     */
    Vector<dim> add(const Vector<dim>& v) const;

    /**
     * Inverts the vector, by multiplying each element by -1
     * @return The inverted vector
     */
    Vector<dim> invert() const;

    /**
     * Scales each element of the vector by a certain scalar
     * @param d The scalar the vector is scaled by
     * @return The scaled vector
     */
    Vector<dim> scale(double d) const;

    /**
     * Takes the dot product of two vectors
     * @param v The vector to be dotted with this
     * @return The double value of the dot product
     */
    double dot(const Vector<dim>& v) const;

    /**
     * Calculates the norm of the vector
     * @return The norm of the vector as a double
     */
    double norm() const;

    /**
     * Calculates the norm squared of the vector
     * @return The norm squared of the vector as a double
     */
    double normSq() const;

    /**
     * Normalizes the vector by dividing each element by the vector's norm
     * @return The normalized vector
     */
    Vector<dim> normalize() const;

    /**
     * Crosses two vectors
     * Throws std::domain_error if the vectors aren't of dimension three
     * Else computes the cross product of both three dimensional vectors
     * @param v The vector to be crossed with this
     * @return The vector value of the cross product
     */
    Vector<dim> cross(const Vector<dim>& v) const;

    /**
     * == operator overloaded, tests if two vectors are equal
     * @param v The vector to be equality tested
     * @return True if vectors are equal, false if not
     */
    bool operator==(const Vector<dim>& v) const;

    /**
     * != operator overloaded, tests if two vectors are not equal
     * @param v The vector to be inequality tested
     * @return True if the vectors are not equal, false if not
     */
    bool operator!=(const Vector<dim>& v) const;

    /**
     * [] operator overloaded, returns the element at the vector's specified index
     * @param index The index of the element to be returned
     * @return The double element at the specific index
     */
    double& operator[](uint32_t index);

    /**
     * Const [] operator overloaded, returns the element at the vector's specified index
     * @param index The index of the element to be returned
     * @return The const double element at the specific index
     */
    const double& operator[](uint32_t index) const;

    /**
     * - operator overloaded, scales each vector element by -1
     * @return The negation of the vector
     */
    Vector<dim> operator-() const;

    /**
     * * operator overloaded, performs scalar multiplication
     * @param d The double the vector is to be scaled by
     * @return The vector scaled by the specific value
     */
    Vector<dim> operator*(double d) const;

    /**
     * / operator overloaded, divides each vector element by the scalar
     * @param d The scalar the vector is to be divided by
     * @return The vector scaled by 1/the specific value
     */
    Vector<dim> operator/(double d) const;

    /**
     * + operator overloaded, adds two vectors
     * @param v The vector to be added
     * @return The two vectors added
     */
    Vector<dim> operator+(const Vector<dim>& v) const;

    /**
     * - operator overloaded, subtracts two vectors
     * @param v The vector to be subtracted
     * @return The two vectors subtracted
     */
    Vector<dim> operator-(const Vector<dim>& v) const;

    /**
     * * operator overloaded, takes the dot product of two vectors
     * @param v The vector to be dotted
     * @return The double value of the dot product
     */
    double operator*(const Vector<dim>& v) const;

    /**
     * ^ operator overloaded, takes the cross product of two vectors
     * @param v The vector to be crossed
     * @return The vector representing the cross product
     */
    Vector<3> operator^(const Vector<3>& v) const;

    /**
     * *= operator overloaded, multiplies the vector by a scalar
     * @param d The scalar the vector is scaled by
     * @return this vector multiplied by d
     */
    Vector<dim>& operator*=(double d);

    /**
     * /= operator overloaded, divides each vector element by a scalar
     * @param d The scalar the vector is divided by
     * @return this vector divided by d
     */
    Vector<dim>& operator/=(double d);

    /**
     * += operator overloaded, adds a vector to this
     * @param v The vector to be added
     * @return this vector with v added to it
     */
    Vector<dim>& operator+=(const Vector<dim>& v);

    /**
     * -= operator overloaded, subtracts a vector to this
     * @param v The vector to be subtracted
     * @return this vector with v subtracted from it
     */
    Vector<dim>& operator-=(const Vector<dim>& v);

private:
    double mArray[dim];

    /**
     * Creates a const iterator to the front of mArray
     * @return a const double* pointing to the first element of mArray
     */
    const double* begin() const noexcept;

    /**
     * Creates a const iterator to the back of mArray
     * @return a const double* pointing one past the last element of mArray
     */
    const double* end() const noexcept;

    /**
     * Creates an iterator to the front of mArray
     * @return a double* pointing to the first element of mArray
     */
    double* begin() noexcept;

    /**
     * Creates an iterator to the back of mArray
     * @return a double* pointing one past the last element of mArray
     */
    double* end() noexcept;
};

/**
 * A binary free function which overloads the * operator
 * @param d The scalar to be multiplied with v
 * @param v The vector to be multiplied by d
 * @return The vector d multiplied with v
 */
template <uint32_t dim> Vector<dim> operator*(const double d, const Vector<dim>& v);

#include "../src/Vector.cpp"
#endif
