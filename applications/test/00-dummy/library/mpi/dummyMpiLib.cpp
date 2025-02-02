/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openansys.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2020 OpenCFD Ltd.
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

#include "dummyLib.H"
#include <iostream>

// Include MPI without any C++ bindings
#ifndef MPICH_SKIP_MPICXX
#define MPICH_SKIP_MPICXX
#endif
#ifndef OMPI_SKIP_MPICXX
#define OMPI_SKIP_MPICXX
#endif
#include <mpi.h>

// * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * * //

bool Foam::Detail::dummyLib::hasMPI()
{
    return true;
}


bool Foam::Detail::dummyLib::printMPI()
{
    int rank = 0, nprocs = 0;

    MPI_Init(nullptr, nullptr);

    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Hello world
    std::cout
        <<
        (
            std::string("mpi rank ")
          + std::to_string(rank) + '/' + std::to_string(nprocs)
          + '\n'
        );

    MPI_Finalize();

    #ifdef FOAM_MPI
    if (rank == 0)
    {
        std::cout
            <<
            (
                std::string("FOAM_MPI=") + std::string(FOAM_MPI)
              + '\n'
            );
    }
    #endif

    return rank == 0;
}


// ************************************************************************* //
