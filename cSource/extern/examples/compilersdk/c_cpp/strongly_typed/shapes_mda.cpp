// Use "mcc -W 'cpplib:libshapes,generic' +shapes calculatearea.m -d output/cpp" command 
// to generate libshapesv2.hpp and libshapes.ctf under existing output/cpp folder

#include "MatlabCppSharedLib.hpp"
#include "output/cpp/v2/generic_interface/libshapesv2.hpp"
using namespace shapes;

// Show the value of a position
void showPosition(MyPosition& p)
{
    printf("Point (%lf, %lf)\n", p.getX(), p.getY());
}

// Show the value of a rectangle
void showRectangle(std::shared_ptr<MATLABControllerType> matlabPtr, MyRectangle& r)
{
    MyPosition pUL(matlabPtr, r.getUpperLeft());
    MyPosition pLR(matlabPtr, r.getLowerRight());
    printf("Rectangle (%lf, %lf) -> (%lf, %lf)\n", pUL.getX(), pUL.getY(), pLR.getX(), pLR.getY());
}

// Pass libshapes.ctf as the only argument to the application
int main(const int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <path to libshapes.ctf>\n";
        return 0;
    }

    try {
        // Initialize MATLAB application
        auto mode = matlab::cpplib::MATLABApplicationMode::IN_PROCESS;
        std::vector<std::u16string> OPTIONS = {u"-nojvm"};
        auto appPtr = matlab::cpplib::initMATLABApplication(mode, OPTIONS);

        // Initialize MATLAB runtime from the ctf
        std::string ctfName(argv[1]);
        auto libPtr = matlab::cpplib::initMATLABLibrary(appPtr, std::u16string(ctfName.cbegin(), ctfName.cend()));
        std::shared_ptr<MATLABControllerType> matlabPtr(std::move(libPtr));

        // Create a rectangle from two points
        MyPosition p1(matlabPtr);
        p1.setX(10);
        p1.setY(5);
        showPosition(p1);
        MyPosition p2(matlabPtr);
        p2.setX(50);
        p2.setY(20);
        showPosition(p2);
        MyRectangle r1(matlabPtr);
        r1.setUpperLeft(p1);
        r1.setLowerRight(p2);
        showRectangle(matlabPtr, r1);

        // Create second rectangle by enlarging the first one
        MyRectangle r2(matlabPtr, r1.enlarge(10.0));
        showRectangle(matlabPtr, r2);

        // Call MATLAB calculatearea function
        matlab::data::TypedArray<double> doubles = calculatearea(matlabPtr, r2);
        std::cout << "Area of rectangle r2 = " << doubles[0] << "\n";

        appPtr.reset();
        return 0;
    } catch (const std::exception & exc) {
        std::cout << exc.what() << std::endl;
        return 1;
    }
}

