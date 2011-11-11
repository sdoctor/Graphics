#!/bin/bash

rm *.tga

./a4 -input scene1_01.txt -size 200 200 -output output1_01.tga -depth 9 10 depth1_01.tga
./a4 -input scene1_02.txt -size 200 200 -output output1_02.tga -depth 8 12 depth1_02.tga
./a4 -input scene1_03.txt -size 200 200 -output output1_03.tga -depth 8 12 depth1_03.tga
./a4 -input scene1_04.txt -size 200 200 -output output1_04.tga -depth 12 17 depth1_04.tga
./a4 -input scene1_05.txt -size 200 200 -output output1_05.tga -depth 14.5 19.5 depth1_05.tga
./a4 -input scene1_06.txt -size 200 200 -output output1_06.tga -depth 3 7 depth1_06.tga
./a4 -input scene1_07.txt -size 200 200 -output output1_07.tga -depth -2 2 depth1_07.tga
./a4 -input scene2_01_diffuse.txt -size 200 200 -output output2_01.tga
./a4 -input scene2_02_ambient.txt -size 200 200 -output output2_02.tga
./a4 -input scene2_03_colored_lights.txt -size 200 200 -output output2_03.tga -normals normals2_03.tga
./a4 -input scene2_04_perspective.txt -size 200 200 -output output2_04.tga -normals normals2_04.tga
./a4 -input scene2_06_plane.txt -size 200 200 -output output2_06.tga -depth 8 20 depth2_06.tga -normals normals2_06.tga
./a4 -input scene2_08_cube.txt -size 200 200 -output output2_08.tga
./a4 -input scene2_09_bunny_200.txt -size 200 200 -output output2_09.tga
./a4 -input scene2_10_bunny_1k.txt -size 200 200 -output output2_10.tga
./a4 -input scene2_11_squashed_sphere.txt -size 200 200 -output output2_11.tga -normals normals2_11.tga
./a4 -input scene2_12_rotated_sphere.txt -size 200 200 -output output2_12.tga -normals normals2_12.tga
./a4 -input scene2_13_rotated_squashed_sphere.txt -size 200 200 -output output2_13.tga -normals normals2_13.tga
./a4 -input scene2_14_axes_cube.txt -size 200 200 -output output2_14.tga
./a4 -input scene2_15_crazy_transforms.txt -size 200 200 -output output2_15.tga
./a4 -input scene2_16_t_scale.txt -size 200 200 -output output2_16.tga -depth 2 7 depth2_16.tga
