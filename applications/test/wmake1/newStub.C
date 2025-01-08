// Some test code

#include "ansysVersion.H"
#include "IOstreams.H"

namespace Foam
{
    void printTest()
    {
        Info<< nl;
        ansysVersion::printBuildInfo(Info.stdStream());
    }
}
