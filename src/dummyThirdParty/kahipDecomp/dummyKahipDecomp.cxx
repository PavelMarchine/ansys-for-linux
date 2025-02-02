/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openansys.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2017-2023 OpenCFD Ltd.
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

\*---------------------------------------------------------------------------*/

#include "kahipDecomp.H"
#include "addToRunTimeSelectionTable.H"

static const char* notImplementedMessage =
"Attempted to use <kahip> without the kahipDecomp library loaded.\n"
"This message is from the dummy kahipDecomp stub library instead.\n\n"
"Please install <kahip> and ensure libkahip.so is in LD_LIBRARY_PATH.\n"
"The kahipDecomp library can then be built from "
"src/parallel/decompose/kahipDecomp.\n"
"Dynamically loading or linking this library will add "
"<kahip> as a decomposition method.\n";

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(kahipDecomp, 0);
    addToRunTimeSelectionTable
    (
        decompositionMethod,
        kahipDecomp,
        dictionary
    );
}


// * * * * * * * * * * * * Protected Member Functions  * * * * * * * * * * * //

Foam::label Foam::kahipDecomp::decomposeSerial
(
    const labelList& adjncy,
    const labelList& xadj,
    const List<scalar>& cellWeights,
    labelList& decomp
) const
{
    FatalErrorInFunction
        << notImplementedMessage << exit(FatalError);

    return -1;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::kahipDecomp::kahipDecomp(const label numDomains)
:
    metisLikeDecomp(numDomains)
{}


Foam::kahipDecomp::kahipDecomp
(
    const dictionary& decompDict,
    const word& regionName
)
:
    metisLikeDecomp("kahip", decompDict, regionName)
{}


// ************************************************************************* //
