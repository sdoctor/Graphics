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
    int img_height;
    int img_width;
    const char* output_filename;
    int depth_min;
    int depth_max;
    const char* depth_output_filename;
    const char* normals_output_filename;
    
    cout << "All variables declared in main..." << endl;

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
            img_height = atoi(argv[argNum+1]);
            img_width = atoi(argv[argNum+2]);
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
            assert (argNum+1 <= argc && "Did not specify enough arguments for flag -normals (should have 1)");
            normals_output_filename = argv[argNum+1];
            argNum+=1;
        }
        
    }
    
    cout << "Input arguments parsed" << endl;
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
    Image* img = new Image(img_width, img_height);
    Image* depth_img = new Image(img_width, img_height);
    Image* normals_img = new Image(img_width, img_height);
    
    cout << "now starting to produce image" << endl;
    cout << "tmin = " << camera->getTMin();
    for (int i = 0; i < img_width; i++) 
    {
        for (int j = 0; j < img_height; j++) 
        {
//            cout << "for pixel " << i << "," << j << ": ";
            // Generate ray using cmaera class
            float tmin = camera->getTMin();
            Hit hit = Hit(FLT_MAX, NULL, NULL); // is this supposed to be something more...profound?
            
            // we want it to map from (-1,-1) to (1,1)
            float x = (2.0/img_width)*(float)i - 1.0;
            float y = (2.0/img_height)*(float)j - 1.0;
            Vector2f pixel = Vector2f(x, y);

            Ray ray = camera->generateRay(pixel);
            
            // intersect the ray with the high level group for the scene
            if (group->intersect(ray, hit, tmin))
            {
                // write color of the closest intersected object
                Material* material = hit.getMaterial();
                if (parser->getNumLights() == 0)
                {
                    Vector3f color = material->getDiffuseColor();
//                cout << "writing intersect color" << endl;
                    img->SetPixel(i, j, color); 
                }
                else
                {
                    Vector3f color(0,0,0);//material->getDiffuseColor();
                    for (int k = 0; k < parser->getNumLights(); k++)
                    {
                        Light* light = parser->getLight(k);
                        
//                        Vector3f col = parser.getAmbientLight();
                        Vector3f p = ray.pointAtParameter(hit.getT());
                        Vector3f dir;
                        Vector3f col;
                        float distanceToLight = 10.0;
                        light->getIllumination(p, dir, col, distanceToLight); // wht should distance to light actually be?
                                                cout << "after getIllum: dir = " << dir[0] << dir[1] << dir[2] << endl;
                        
                        float coeff = Vector3f::dot(hit.getNormal().normalized(), dir.normalized());
                        //coeff = 0.1;
                        color += material->getDiffuseColor() * col * coeff;
                        
                        cout << "Coeff: " << coeff << endl;
                        
                        //float denom = dir.abs()*hit.getNormal().abs();
                        //float angle_between = Vector3f::dot(dir, hit.getNormal())/denom;
//                        angle_between = angle_between*180.0/6.28;
//                        cout << "angle between = " << angle_between << endl;
                        
                        //float to_add = Vector3f::dot(dir, hit.getNormal());
                       //Vector3f irradiance = angle_between*col;
                       //cout << "irradiance = " << irradiance[0] << irradiance[1] << irradiance[2] << endl;
                       
                       //cout << "to_add = " << to_add << endl;
                       //color -= Vector3f(to_add/10.0, to_add/10.0, to_add/10.0);
                    }
                    img->SetPixel(i, j, color);
                }
                               
                
                // Visualize Depth (QUESTION: should this be a separate routine?
                // I don't think so because all of the tests also have depth 
                // but this can be commented out for testing if it doesn't work...
                if (depth_output_filename != NULL)
                {
                    float t = hit.getT();
                    
                    if (t >= depth_min && t <= depth_max)
                    {
                        float depth_val = (depth_max - t)/(depth_max - depth_min);
//                        cout << "depth_val = " << depth_val << endl;
                        // QUESTION: how to make Vector3f of the color?
                        depth_img->SetPixel(i, j, Vector3f(depth_val, depth_val, depth_val));
                    
                    
                    }
                    else 
                    {
                        depth_img->SetPixel(i, j, Vector3f(0,0,0));
                    }
                }
                
                if (normals_output_filename != NULL)
                {
                    Vector3f normal = hit.getNormal();
                    normals_img->SetPixel(i, j, normal); // QUESTION: just color the normal?
                }
                    
            } 
            else
            {
//                cout << "writing background color" << endl;
                img->SetPixel(i, j, background_color);
                depth_img->SetPixel(i, j, background_color);
            }
            
            
            
            
            
        }      
    }
    
    
    // Instructions for Depth:
    // Implement a second rendering style to visualize the depth t of
    // objects in the scene. Two input depth values specify the range
    // of depth values which should be mapped to shades of gray in 
    // the visualization. Depth values outside this range = clamped
    
    
    // Instructions for Normals:
    // Implement a new rendering mode, normal visualization
    
    
    
    
    // Write outfiles!
    cout << "images produced, writing outfiles" << endl;
    img->SaveTGA(output_filename);
    if (depth_output_filename != NULL)
    {
        depth_img->SaveTGA(depth_output_filename);
    }
    if (normals_output_filename != NULL)
    {
        normals_img->SaveTGA(normals_output_filename);

    }
           
    

    return 0;
}

