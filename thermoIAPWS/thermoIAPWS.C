/*---------------------------------------------------------------------------*\
=========                 |
\\      /  F ield         | Unsupported Contributions for OpenFOAM
 \\    /   O peration     |
  \\  /    A nd           | Copyright (C) 2015 Roman Thiele
   \\/     M anipulation  |
-------------------------------------------------------------------------------

License
    This file is a derivative work of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "thermoIAPWS.H"
#include "IOstreams.H"

/* * * * * * * * * * * * * * * private static data * * * * * * * * * * * * * */

template<class Thermo, template<class> class Type>
const Foam::scalar Foam::species::thermo<Thermo, Type>::tol_ = 1.0e-4;

template<class Thermo, template<class> class Type>
const int Foam::species::thermo<Thermo, Type>::maxIter_ = 100;


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Thermo, template<class> class Type>
Foam::species::thermo<Thermo, Type>::thermo(Istream& is)
:
    Thermo(is)
{
    is.check("thermo<Thermo, Type>::thermo(Istream&)");
}


template<class Thermo, template<class> class Type>
Foam::species::thermo<Thermo, Type>::thermo(const dictionary& dict)
:
    Thermo(dict)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Thermo, template<class> class Type>
void Foam::species::thermo<Thermo, Type>::write(Ostream& os) const
{
    Thermo::write(os);
}


// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class Thermo, template<class> class Type>
Foam::Ostream& Foam::species::operator<<
(
    Ostream& os, const thermo<Thermo, Type>& st
)
{
    os  << static_cast<const Thermo&>(st);

    os.check("Ostream& operator<<(Ostream&, const thermo&)");
    return os;
}


// ************************************************************************* //
