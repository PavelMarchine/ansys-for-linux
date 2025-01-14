/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openansys.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2016 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

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

Application
    Test-sysInfo

Description
    Simple output of endian and system-information

\*---------------------------------------------------------------------------*/

#include "profilingSysInfo.H"
#include "IOstreams.H"
#include "ansysEndian.H"  // For run-time tests
#include "cpuInfo.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//  Main program:

int main(int argc, char *argv[])
{
    profilingSysInfo{}.writeEntry("sys-info", Info);
    Foam::cpuInfo{}.writeEntry("cpu-info", Info);

#ifdef WM_BIG_ENDIAN
    Info
        << "WM_BIG_ENDIAN is defined"
        << nl;
#endif
#ifdef WM_LITTLE_ENDIAN
    Info
        << "WM_LITTLE_ENDIAN is defined"
        << nl;
#endif

    Info<< "Runtime endian check: big=" << endian::isBig()
        << " little=" << endian::isLittle()
        << nl;

    return 0;
}


// ************************************************************************* //
