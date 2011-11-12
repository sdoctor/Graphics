#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "SceneParser.h"
#include "Image.h"
#include "Camera.h"

using namespace std;


void parse_program_args()
{
    // hint says to parse the arguments of the program in a separate function
}

int main( int argc, char* argv[] )
{
    // Fill in your implementation here.
    
    
    // Things we get from the input arguments
    const char* input_filename;
    int scene_height;
    int scene_width;
    const char* output_filename;
    int depth_height;
    int depth_width;
    const char* depth_output_filename;
    const char* normals_filename;
    

    // This loop loops over each of the input arguments.
    // argNum is initialized to 1 because the first
    // "argument" provided to the program is actually the
    // name of the executable (in our case, "a4").
    for( int argNum = 1; argNum < argc; ++argNum )
    {
        std::cout << "Argument " << argNum << " is: " << argv[argNum] << std::endl;
        
        if (string(argv[argNum]) == "-input")
        {
            assert (argNum+1 <= argc && "Did not specify argument for flag -input"); // make sure there is something after the flag
            input_filename = argv[argNum+1];
            argNum += 1; // move past the flag you just read
        }
        if (string(argv[argNum]) == "-size")
        {
            assert (argNum+2 <= argc && "Did not specify enough arguments for flag -size"); // make sure there is something after the flag
            scene_height = atoi(argv[argNum+1]);
            scene_width = atoi(argv[argNum+2]);
            argNum += 2;
        }
        if (string(argv[argNum]) == "-output")
        {
            assert (argNum+1 <= argc && "Did not specify argument for flag -output"); // make sure there is something after the flag
            output_filename = argv[argNum+1];
            argNum+=1;
        }
        if (string(argv[argNum]) == "-depth")
        {
            assert (argNum+3 <= argc && "Did not specify enough arguments for flag -depth (should have 3)");
            depth_height = atoi(argv[argNum+1]);
            depth_width = atoi(argv[argNum+2]);
            depth_output_filename = argv[argNum+3];
            argNum+=3;
        }
        if (string(argv[argNum]) == "-normals")
        {
            assert (argNum+3 <= argc && "Did not specify enough arguments for flag -depth (should have 3)");
            normals_filename = argv[argNum+1];
            argNum+=1;
        }
        
    }
    

    // From the handout: Write a main function that:
    //    1) reads the scene (using the parsing code provided)
    //    2) loops over the pixesl in the image plane
    //        3) generates a ray using your camera class
    //        4) intersects it with the high lievel Group that stores the objects of the scene
    //        5) writes the color of the closest intersected object
    
    
    SceneParser parser = SceneParser(input_filename);
    
    
    // First, parse the scene using SceneParser.
    // Then loop over each pixel in the image, shooting a ray
    // through that pixel and finding its intersection with
    // the scene.  Write the color at the intersection to that
    // pixel in your output image.

    return 0;
}

