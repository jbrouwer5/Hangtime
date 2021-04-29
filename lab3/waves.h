/* Takes four doubles representing two point of the form
(x0, y0) and (x1, y1). The function then returns the 
distance between the two points*/
double dist(double x0, double y0, double x1, double y1);

/* Makes a ppm representing a picture of concentric blue 
circles with concentric black circles in between. 
Takes three integer arguments, the first argument represents 
the side length of the final image produced, 
while the second two integers represent the offset
distance from the center of the picture and the center of the 
concentric circles. */
void draw_waves(int side_length, int x_offset, int y_offset);