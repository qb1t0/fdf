# FDF project for 42 school
The representation in 3D of a landscape is a critical aspect of modern mapping.
For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest. 

As another example, comparing various 3D repre- sentations of an area of high tectonic activity will allow you to better understand these phenomenon and their evolution, and as a result be better prepared.

<img width="934" alt="screen shot 2017-11-21 at 5 01 03 pm" src="https://user-images.githubusercontent.com/26835866/33079177-9a63c5e2-cedd-11e7-871c-2863138f25bb.png">

# Mandatory part

This project is about creating a simplified graphic “wireframe” 
(“fils de fer” in french, hence the name of the project) representation of a relief landscape linking various points (x, y, z) via segments.
The coordinates of this landscape are stored in a file passed as a parameter to your program. 
Here is an example:

                          0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
                          0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
                          0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
                          0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
                          0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
                          0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
                          0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
                          0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
                          0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
                          0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
                          0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

If you execute your program fdf on this file, we should see something like this:
            
    $./fdf maps/42.fdf
       
<img width="1901" alt="screen shot 2017-11-21 at 7 51 26 pm" src="https://user-images.githubusercontent.com/26835866/33088147-7655fdba-cef5-11e7-8e90-598ff70aad5d.png">

    $./fdf maps/julia.fdf
    
<img width="1899" alt="screen shot 2017-11-21 at 7 43 48 pm" src="https://user-images.githubusercontent.com/26835866/33088170-8a5cc686-cef5-11e7-8397-e553ca2ab23b.png">

    $./fdf maps/t1.fdf
    
<img width="1894" alt="screen shot 2017-11-21 at 7 49 49 pm" src="https://user-images.githubusercontent.com/26835866/33088224-ba9eab20-cef5-11e7-90d3-f63c027e889f.png">
