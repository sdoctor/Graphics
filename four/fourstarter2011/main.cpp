#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "SceneParser.h"
#include "Image.h"
#include "Camera.h"

using namespace std;

int main( int argc, char* argv[] )
{
    // Fill in your implementation here.

    // This loop loops over each of the input arguments.
    // argNum is initialized to 1 because the first
    // "argument" provided to the program is actually the
    // name of the executable (in our case, "a4").
    for( int argNum = 1; argNum < argc; ++argNum )
    {
        std::cout << "Argument " << argNum << " is: " << argv[argNum] << std::endl;
    }

    // First, parse the scene using SceneParser.
    // Then loop over each pixel in the image, shooting a ray
    // through that pixel and finding its intersection with
    // the scene.  Write the color at the intersection to that
    // pixel in your output image.

    return 0;
}

