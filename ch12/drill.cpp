#include "../forras/Simple_window.h"
#include "../forras/Graph.h"

#include <iostream>
#include <sstream>

int main()
{
    int xmax = 600;
    int ymax = 400;

    Simple_window win {Point{200,200}, xmax, ymax, "My window"};
    win.wait_for_button();
    //Axis (tengely)
    Axis xa {Axis::x, Point{20,300}, 280, 20, "x axis"};
    xa.set_color(Color::dark_blue);
    win.attach(xa);
    win.set_label("Cancas #2");
    win.wait_for_button();

    Axis ya {Axis::y, Point{20,300}, 280, 20, "y axis"};
    ya.set_color(Color::dark_red);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();

    Function sine {sin,0,100,Point{20,150},1000,50,50}; // sine curve
    // plot sin() in the range [0:100) with (0,0) at (20,150)
    // using 1000 points; scale x values *50, scale y values *50
    sine.set_color(Color::dark_magenta);
    win.attach(sine);
    win.set_label("Canvas #4");
    win.wait_for_button();
    //Graphing a function (függvényábrázolás)
    sine.set_color(Color::blue); // we changed our mind about sine’s color
    Polygon poly; // a polygon; a Polygon is a kind of Shape
    poly.add(Point{300, 200}); // three points make a triangle
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dot);
    win.attach(poly);
    win.set_label("Canvas #5");
    win.wait_for_button();
    //Polygons
    Rectangle r {Point{200,200}, 120, 50}; // top left corner, width, height
    win.attach(r);
    win.set_label("Canvas #6");
    win.wait_for_button();
    //Rectangles
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    poly_rect.add(Point{150,130});
    win.attach(poly_rect);
    win.wait_for_button();
    //Fill
    r.set_fill_color(Color::yellow); // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::yellow);
    win.set_label("Canvas #7");
    win.wait_for_button();
    //Text
    
    Text t {Point{150,150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("Canvas #8");
    win.wait_for_button();
    //Text decor
    t.set_font(Font::courier_bold);
    t.set_font_size(25);
    win.set_label("Canvas #9");
    win.wait_for_button();
    //Images
    Image ii {Point{100,50},"ch12/image1.jpeg"}; //400*200 jepg (can be jpg too)
    win.attach(ii);
    win.set_label("Canvas #10");
    win.wait_for_button();
    //Move images
    ii.move(100,200);
    win.set_label("Canvas #11");
    win.wait_for_button();
    //And much more
    Point center = Point{100,200};
    Circle c {center,50};
    win.attach(c);
    Ellipse e {center, 75,25};
    e.set_color(Color::red);
    win.attach(e);
    Mark m {center,'o'};
    win.attach(m);

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
    << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100,20},oss.str()};

    Image cal {Point{225,225},"ch12/200x200.gif"}; //200x200 gif
    cal.set_mask(Point{40,40},200,150); // display center part of image
    win.attach(cal);
    
    win.set_label("Canvas #12");
    win.wait_for_button();
}