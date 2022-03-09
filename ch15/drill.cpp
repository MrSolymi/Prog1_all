#include "../forras/Graph.h"
#include "../forras/Simple_window.h"
#include "../forras/Window.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
    int xmax = 600;
    int ymax = 600;

    Point orig {xmax/2,ymax/2};

    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs."};

    Axis ya {Axis::y, Point{300,500}, 400, 20, "1 = = 20 pixels"};
    ya.set_color(Color::red);
    win.attach(ya);
    Axis xa {Axis::x, Point{100,300}, 400, 20, "1 = = 20 pixels"};
    xa.set_color(Color::red);
    win.attach(xa);

    constexpr int r_min = -10;
    constexpr int r_max = 11;
    constexpr int n_points = 400;
    constexpr int x_scale = 20;
    constexpr int y_scale = 20;

    //Function ts {one, r_min, r_max, orig, n_points};
    //win.attach(ts);

    Function s {one, r_min, r_max, orig, n_points, x_scale, y_scale};
    win.attach(s);

    Function s2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
    Text ts2 {Point{100,380},"x/2"};
    win.attach(ts2);
    win.attach(s2);

    Function s3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};
    win.attach(s3);

    Function s4 {cos, r_min, r_max, orig, n_points, x_scale, y_scale};
    s4.set_color(Color::blue);
    win.attach(s4);

    Function s5 {sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};
    win.attach(s5);
    
    win.wait_for_button();
}