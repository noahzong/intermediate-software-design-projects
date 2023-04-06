// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.

#ifndef VECTOR_CPP
#define VECTOR_CPP
#include "Vector.h"

template <uint32_t dim> Vector<dim>::Vector()
{
    std::fill(begin(), end(), 0);
}

template <uint32_t dim> Vector<dim>::Vector(const double arr[])
{
    Vector<dim> tmp;
    uint32_t i = 0;
    std::transform(begin(), end(), tmp.begin(), [&i, &arr](double& d) {
        d = arr[i];
        ++i;
        return d;
    });
    std::swap(mArray, tmp.mArray);
}

template <uint32_t dim> std::string Vector<dim>::toString() const
{
    std::stringstream output;
    output << "[";
    std::copy(begin(), end() - 1, std::ostream_iterator<double>(output, " "));
    output << (*this)[dim - 1] << "]";
    return output.str();
}

template <uint32_t dim> Vector<dim> Vector<dim>::add(const Vector<dim>& v) const
{
    return *this + v;
}

template <uint32_t dim> Vector<dim> Vector<dim>::invert() const
{
    return (-*this);
}

template <uint32_t dim> Vector<dim> Vector<dim>::scale(double d) const
{
    return *this * d;
}

template <uint32_t dim> double Vector<dim>::dot(const Vector<dim>& v) const
{
    return *this * v;
}

template <uint32_t dim> double Vector<dim>::norm() const
{
    return std::sqrt(normSq());
}

template <uint32_t dim> double Vector<dim>::normSq() const
{
    double sum = 0;
    Vector<dim> tmp;
    std::transform(begin(), end(), tmp.begin(), [&sum](double d) {
        sum += (d * d);
        return d;
    });
    return sum;
}

template <uint32_t dim> Vector<dim> Vector<dim>::normalize() const
{
    if (std::count(begin(), end(), 0) == dim) {
        throw std::overflow_error("Can not normalize the zero vector");
    }
    return *this / norm();
}

template <uint32_t dim> Vector<dim> Vector<dim>::cross(const Vector<dim>& v) const
{
    (void)v;
    throw std::domain_error("Vectors must be 3 dimensions");
}

template <> Vector<3> Vector<3>::cross(const Vector<3>& v) const
{
    Vector<3> cross;
    cross[0] = mArray[1] * v[2] - mArray[2] * v[1];
    cross[1] = mArray[0] * v[2] - mArray[2] * v[0];
    cross[2] = mArray[0] * v[1] - mArray[1] * v[0];
    return cross;
}

template <uint32_t dim> bool Vector<dim>::operator==(const Vector<dim>& rhs) const
{

    double epsilon = 0.000001;
    return std::equal(begin(), end(), rhs.begin(),
        [&epsilon](double d1, double d2) { return (std::abs(d1 - d2) < epsilon); });
}

template <uint32_t dim> bool Vector<dim>::operator!=(const Vector<dim>& rhs) const
{
    return !(*this == rhs);
}

template <uint32_t dim> double& Vector<dim>::operator[](uint32_t index)
{
    return const_cast<double&>(static_cast<const Vector<dim>*>(this)->operator[](index));
}

template <uint32_t dim> const double& Vector<dim>::operator[](uint32_t index) const
{
    return mArray[index];
}

template <uint32_t dim> Vector<dim> Vector<dim>::operator-() const
{
    Vector<dim> copy;
    std::transform(begin(), end(), copy.begin(), [](double d) { return -1 * d; });
    return copy;
}

template <uint32_t dim> Vector<dim> Vector<dim>::operator*(double d) const
{
    Vector<dim> copy;
    std::transform(begin(), end(), copy.begin(), [&d](double _d) { return d * _d; });
    return copy;
}

template <uint32_t dim> Vector<dim> Vector<dim>::operator/(double d) const
{
    return *this * (1 / d);
}

template <uint32_t dim> Vector<dim> Vector<dim>::operator+(const Vector<dim>& v) const
{
    Vector<dim> copy;
    std::transform(
        begin(), end(), v.begin(), copy.begin(), [](double d1, double d2) { return d1 + d2; });
    return copy;
}

template <uint32_t dim> Vector<dim> Vector<dim>::operator-(const Vector<dim>& v) const
{
    return *this + (-v);
}

template <uint32_t dim> double Vector<dim>::operator*(const Vector<dim>& v) const
{
    double sum = 0;
    Vector<dim> tmp;
    std::transform(begin(), end(), v.begin(), tmp.begin(), [&sum](double d1, double d2) {
        sum += (d1 * d2);
        return d1;
    });
    return sum;
}

template <> Vector<3> Vector<3>::operator^(const Vector<3>& v) const
{
    return cross(v);
}

template <uint32_t dim> Vector<dim>& Vector<dim>::operator*=(double d)
{

    return *this = *this * d;
}

template <uint32_t dim> Vector<dim>& Vector<dim>::operator/=(double d)
{
    return *this *= (1 / d);
}
template <uint32_t dim> Vector<dim>& Vector<dim>::operator+=(const Vector<dim>& v)
{

    return *this = *this + v;
}
template <uint32_t dim> Vector<dim>& Vector<dim>::operator-=(const Vector<dim>& v)
{
    return *this += (-v);
}

template <uint32_t dim> const double* Vector<dim>::begin() const noexcept
{
    return std::begin(mArray);
}

template <uint32_t dim> const double* Vector<dim>::end() const noexcept
{
    return std::end(mArray);
}

template <uint32_t dim> double* Vector<dim>::begin() noexcept
{
    return const_cast<double*>(static_cast<const Vector<dim>*>(this)->begin());
}

template <uint32_t dim> double* Vector<dim>::end() noexcept
{
    return const_cast<double*>(static_cast<const Vector<dim>*>(this)->end());
}

template <uint32_t dim> Vector<dim> operator*(const double d, const Vector<dim>& v)
{
    return v * d;
}

#endif
