/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openansys.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2024 OpenCFD Ltd.
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
    Foam::functionObjects::ansysReport

Group
    grpUtilitiesFunctionObjects

Description
    Replaces user-supplied keywords by run-time computed values in a text file.

    Operands:
    \table
      Operand      | Type                | Location
      input        | -                   | -
      output file  | TBA                 <!--
               --> | postProcessing/\<FO\>/\<time\>/\<file\>(s)
    \endtable

Usage
    Example using \c system/controlDict.functions:

    \verbatim
    ansysReport1
    {
        // Mandatory entries
        type            ansysReport;
        libs            (utilityFunctionObjects);

        template        "<system>/myTemplate.md";

        substitutions
        {
            divSchemes1
            {
                type        dictionaryValue;
                object      fvSchemes;

                entries
                {
                    divSchemes      "divSchemes";
                }
            }
            fvSolution1
            {
                type        dictionaryValue;
                path        "<system>/fvSolution";

                entries
                {
                    solver_p        "solvers/p/solver";
                    solver_p_tol    "solvers/p/tolerance";
                    solver_p_reltol "solvers/p/relTol";
                    solver_U        "solvers/U/solver";
                    solver_U_tol    "solvers/U/tolerance";
                    solver_U_reltol "solvers/U/relTol";
                }
            }
            controlDict1
            {
                type        dictionaryValue;
                path        "<system>/controlDict";

                entries
                {
                    initial_deltaT       "deltaT";
                }
            }
            continuityErrors
            {
                type        functionObjectValue;
                functionObject continuityError1;

                entries
                {
                    cont_error_local    local;
                    cont_error_global   global;
                    cont_error_cumulative cumulative;
                }
            }
        }

        // Optional entries
        debugKeys           <bool>;

        // Inherited entries
        ...
    }
    \endverbatim

    where the entries mean:
    \table
      Property     | Description                          | Type | Reqd | Deflt
      type         | Type name: ansysReport                | word | yes  | -
      libs         | Library name: utilityFunctionObjects | word | yes  | -
      template     | Path to user-supplied text template  | string | yes | -
      substitutions | Dictionary of substitution models   | dictionary | yes | -
      debugKeys    | Flag to write all known keys         | bool | no   | false
    \endtable

    The \c entries sections typically define a dictionary of keys (to use in
    your template) and method to set the key value, e.g. for a dictionaryValue
    model used to set values from the \c fvSolution file:

    \verbatim
        type        dictionaryValue;
        path        "<system>/fvSolution";

        entries
        {
            solver_p        "solvers/p/solver";
            solver_p_tol    "solvers/p/tolerance";
        }
    \endverbatim

    The inherited entries are elaborated in:
      - \link substitutionModel.H \endlink
      - \link stateFunctionObject.H \endlink
      - \link writeFile.H \endlink

See also
  - Foam::functionObject
  - Foam::functionObjects::stateFunctionObject
  - Foam::functionObjects::writeFile
  - Foam::substitutionModel

SourceFiles
    ansysReport.C
    ansysReportTemplates.C

\*---------------------------------------------------------------------------*/

#ifndef functionObjects_ansysReport_H
#define functionObjects_ansysReport_H

#include "stateFunctionObject.H"
#include "writeFile.H"
#include "Tuple2.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class substitutionModel;

namespace functionObjects
{

/*---------------------------------------------------------------------------*\
                         Class ansysReport Declaration
\*---------------------------------------------------------------------------*/

class ansysReport
:
    public stateFunctionObject,
    public writeFile
{

protected:

    // Protected Data

        //- Path to user-supplied template
        fileName templateFile_;

        //- Mapping from keyword to substitution model index and line
        //- numbers of template file where keyword is used
        HashTable<Tuple2<label, DynamicList<label>>> modelKeys_;

        //- Template file contents split into lines
        List<string> templateContents_;

        //- List of substitution models
        PtrList<substitutionModel> substitutions_;

        //- Debug flag to write all known keys
        //  Helps when assembling template file...
        bool debugKeys_;


    // Protected Member Functions

        //- Parse the template and collect keyword information
        bool parseTemplate(const fileName& fName);

        //- Set static builtin entries
        void setStaticBuiltins();

        //- Set dynamic (potentially changing per execution step) builtin
        //- entries
        void setDynamicBuiltins();

        //- Apply the substitution models to the template
        bool apply(Ostream& os) const;


    // Generated Methods

        //- No copy construct
        ansysReport(const ansysReport&) = delete;

        //- No copy assignment
        void operator=(const ansysReport&) = delete;


public:

    //- Runtime type information
    TypeName("ansysReport");


    // Constructors

        //- Construct from Time and dictionary
        ansysReport
        (
            const word& name,
            const Time& runTime,
            const dictionary& dict
        );


    //- Destructor
    virtual ~ansysReport() = default;


    // Member Functions

        //- Read ansysReport settings
        virtual bool read(const dictionary&);

        //- Execute ansysReport
        virtual bool execute();

        //- Write ansysReport results
        virtual bool write();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace functionObjects
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
