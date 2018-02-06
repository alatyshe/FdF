## Subject
**Mandatory part** - 2d representation of 3d coordinates in isometric projection. This is enough for the successful project validation.

In this project you will discover the basics of graphic programming, and in particular how
to place points in space, how to join them with segments and most importantly how to
observe the scene from a particular viewpoint.
You will also discover your first graphic library: miniLibX. This library was developed
internally and includes the minimum necessary to open a window, light a pixel and deal
with events linked to this window: keyboard and mouse. This project introduces you to
“events” programming. Don’t forget to watch the e-learning videos

**Allowed functions:**  
* `open`,`read`, `write`, `close`   
* `malloc`, `free`   
* `perror`, `strerror`   
* `exit`   

**Allowed libraries:**  
* `math`
* `miniLibX`  
## Details
This project is about creating a simplified graphic “wireframe” representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as
a parameter to program. Here is an simple example:
    
       
Each number on the map corresponds to a point in space:  
  
* The horizontal position corresponds to its axis,  
* The vertical position corresponds to its ordinate,  
* The value corresponds to its altitude.  
