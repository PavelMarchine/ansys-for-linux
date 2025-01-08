/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openansys.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2016 OpenFOAM Foundation
    Copyright (C) 2021 OpenCFD Ltd.
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

Class
    Foam::ansysChemistryReader

Group
    grpReactionThermophysicalChemistryReaders

Description
    Chemistry reader for OpenFOAM format

SourceFiles
    ansysChemistryReader.C

\*---------------------------------------------------------------------------*/

#ifndef ansysChemistryReader_H
#define ansysChemistryReader_H

#include "chemistryReader.H"
#include "fileName.H"
#include "labelList.H"
#include "speciesTable.H"
#include "atomicWeights.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                       Class ansysChemistry Declaration
\*---------------------------------------------------------------------------*/

template<class ThermoType>
class ansysChemistryReader
:
    public chemistryReader<ThermoType>
{
        //- Chemistry/reactions dictionary
        dictionary chemDict_;

        //- Thermo properties dictionary
        dictionary thermoDict_;

        //- List of elements
        DynamicList<word> elementNames_;

        //- Element indices
        HashTable<label> elementIndices_;

        //- Table of species
        speciesTable& speciesTable_;

        //- Table of species composition
        speciesCompositionTable speciesComposition_;

        //- Table of the thermodynamic data given in the ansysChemistry file
        ReactionTable<ThermoType> speciesThermo_;

        //- List of the reactions
        ReactionList<ThermoType> reactions_;


    // Private Member Functions

        //- Set the species list
        speciesTable& setSpecies(const dictionary& dict, speciesTable& species);

        //- Read the species composition
        void readSpeciesComposition();

        //- No copy construct
        ansysChemistryReader(const ansysChemistryReader&) = delete;

        //- No copy assignment
        void operator=(const ansysChemistryReader&) = delete;


public:

    //- Runtime type information
    TypeName("ansysChemistryReader");


    // Constructors

        //- Construct from ansysChemistry and thermodynamics file names
        ansysChemistryReader
        (
            const fileName& reactionsFileName,
            speciesTable& species,
            const fileName& thermoFileName
        );

        //- Construct by getting ansysChemistry and thermodynamics file names
        //- from dictionary
        ansysChemistryReader
        (
            const dictionary& thermoDict,
            speciesTable& species
        );


    //- Destructor
    virtual ~ansysChemistryReader() = default;


    // Member Functions

        //- List of elements
        const wordList& elementNames() const
        {
            return elementNames_;
        }

        //- Element indices
        const HashTable<label>& elementIndices() const
        {
            return elementIndices_;
        }

        //- Table of species
        const speciesTable& species() const
        {
            return speciesTable_;
        }

        //- Table of species composition
        const speciesCompositionTable& specieComposition() const
        {
            return speciesComposition_;
        }

        //- Table of the thermodynamic data given in the ansysChemistry file
        const ReactionTable<ThermoType>& speciesThermo() const
        {
            return speciesThermo_;
        }

        //- List of the reactions
        const ReactionList<ThermoType>& reactions() const
        {
            return reactions_;
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "ansysChemistryReader.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
