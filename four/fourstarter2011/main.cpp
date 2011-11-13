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
    int depth_min;
    int depth_max;
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
            depth_min = atoi(argv[argNum+1]);
            depth_max = atoi(argv[argNum+2]);
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
    
    
    // read the scene using SceneParser
    SceneParser* parser = new SceneParser(input_filename);
    Camera* camera = parser->getCamera();
    Group* group = parser->getGroup();
    Vector3f background_color = parser->getBackgroundColor(); 
    
    
    
    // Loop over pixels in the image plane
    Image* img = new Image(scene_width, scene_height);
    Image* depth_img = new Image(scene_width, scene_height);
    
    for (int i = 0; i < scene_width; i++) 
    {
        for (int j = 0; j < scene_height; j++) 
        {
            // Generate ray using cmaera class
            Hit hit = Hit(); // is this supposed to be something more...profound?
            float tmin = camera->getTMin();
            
            Vector2f pixel = Vector2f(i, j);
            Ray ray = camera->generateRay(pixel);
            
            // intersect the ray with the high level group for the scene
            if (group->intersect(ray, hit, tmin))
            {
                //update shit? or was that done in Group.intersect? before it returned true...bc it called each itnersect method...
                // write color of the closest intersected object
                Material* material = hit.getMaterial();
                Vector3f color = material->getDiffuseColor();
                img->SetPixel(i, j, color);
                
                
                
                // Visualize Depth (QUESTION: should this be a separate routine?
                // I don't think so because all of the tests also have depth 
                // but this can be commented out for testing if it doesn't work...
            
                float depth_val = hit.getT();
                if (depth_val >= depth_min && depth_val <= depth_max)
                {
                    // QUESTION: how to make Vector3f of the color?
                    depth_img->SetPixel(i, j, Vector3f(depth_val, depth_val, depth_val));
                }
            } 
            else
            {
                img->SetPixel(i, j, background_color);
                depth_img->SetPixel(i, j, Vector3f(0,0,0));
            }
            
            
            
            
            
        }      
    }
    
    // Instructions for Depth:
    // Implement a second rendering style to visualize the depth t of
    // objects in the scene. Two input depth values specify the range
    // of depth values which should be mapped to shades of gray in 
    // the visualization. Depth values outside this range = clamped
    
    
    
    
    
    

    return 0;
}

