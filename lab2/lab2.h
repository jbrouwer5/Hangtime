/* graph : graphs a quadratic function*/
void graph(double a, double b, double c, double step, int xleft, int xright,
           int ybottom, int ytop);

/* takes a given point and decides what symbol should be drawn there. */
void draw_point(double a, double b, double c, double step, 
                int x_val, int y_val);

/* draws the row with the given y value between
   the given x dimensions */ 
void draw_row(double a, double b, double c, double step, 
              int xleft, int xright, int yvalue);

