/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openansys.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2015 OpenFOAM Foundation
    Copyright (C) 2023 OpenCFD Ltd.
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

#include "makeReactionThermo.H"
#include "thermoPhysicsTypes.H"
#include "solidThermoPhysicsTypes.H"

#include "chemistryReader.H"
#include "ansysChemistryReader.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Solid chemistry readers based on sensibleEnthalpy

makeChemistryReader(constGasHThermoPhysics);
makeChemistryReader(gasHThermoPhysics);
makeChemistryReader(PengRobinsonGasHThermoPhysics);
makeChemistryReader(constIncompressibleGasHThermoPhysics);
makeChemistryReader(incompressibleGasHThermoPhysics);
makeChemistryReader(icoPoly8HThermoPhysics);
makeChemistryReader(constFluidHThermoPhysics);
makeChemistryReader(constAdiabaticFluidHThermoPhysics);
makeChemistryReader(constHThermoPhysics);


makeChemistryReaderType(ansysChemistryReader, constGasHThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, gasHThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, PengRobinsonGasHThermoPhysics);
makeChemistryReaderType
(
    ansysChemistryReader,
    constIncompressibleGasHThermoPhysics
);
makeChemistryReaderType(ansysChemistryReader, incompressibleGasHThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, icoPoly8HThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, constFluidHThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, constAdiabaticFluidHThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, constHThermoPhysics);



// Solid chemistry readers based on sensibleInternalEnergy

makeChemistryReader(constGasEThermoPhysics);
makeChemistryReader(gasEThermoPhysics);
makeChemistryReader(PengRobinsonGasEThermoPhysics);
makeChemistryReader(constIncompressibleGasEThermoPhysics);
makeChemistryReader(incompressibleGasEThermoPhysics);
makeChemistryReader(icoPoly8EThermoPhysics);
makeChemistryReader(constFluidEThermoPhysics);
makeChemistryReader(constAdiabaticFluidEThermoPhysics);
makeChemistryReader(constEThermoPhysics);


makeChemistryReaderType(ansysChemistryReader, constGasEThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, gasEThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, PengRobinsonGasEThermoPhysics);
makeChemistryReaderType
(
    ansysChemistryReader,
    constIncompressibleGasEThermoPhysics
);
makeChemistryReaderType(ansysChemistryReader, incompressibleGasEThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, icoPoly8EThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, constFluidEThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, constAdiabaticFluidEThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, constEThermoPhysics);


// Solid chemistry readers for solids based on sensibleInternalEnergy

makeChemistryReader(hConstSolidThermoPhysics);
makeChemistryReader(hPowerSolidThermoPhysics);
makeChemistryReader(hExpKappaConstSolidThermoPhysics);

makeChemistryReaderType(ansysChemistryReader, hConstSolidThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, hPowerSolidThermoPhysics);
makeChemistryReaderType(ansysChemistryReader, hExpKappaConstSolidThermoPhysics);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
