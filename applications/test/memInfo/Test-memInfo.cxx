/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openansys.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011 OpenFOAM Foundation
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

Description

\*---------------------------------------------------------------------------*/

#include "memInfo.H"
#include "IOstreams.H"
#include "List.H"
#include "vector.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//  Main program:

int main(int argc, char *argv[])
{
    const int n = 10000000;
    const char* const memTags = "peak/size/rss/free mem: ";

    memInfo mem;

    Info<< memTags << mem << endl;

    List<vector> list(n, vector::one);

    Info<< "allocate " << n << " vectors" << nl;
    Info<< memTags << mem.update() << endl;

    list.clear();
    Info<< "clear" << nl;
    Info<< memTags << mem.update() << endl;

    mem.writeEntry("memory", Info);
    Info<< endl;

    return 0;
}


// ************************************************************************* //
