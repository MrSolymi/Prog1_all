#include "../forras/Graph.h"
#include "../forras/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    int xgrid = 100;
    int ygrid = 100;
    
    Lines grid;
    
    //2.
    for (int x = xgrid; x <= 800; x += xgrid)
    {
        grid.add(Point{x,0}, Point{x, 800});
    }
    for (int y = ygrid; y <= 800; y += ygrid)
    {
        grid.add(Point{0,y}, Point{xmax, y});
    }

    //3.
    Vector_ref<Rectangle> vr;

    for (int i = 0; i < 8; i++)
    {
        vr.push_back(new Rectangle{Point{i*100,i*100}, Point{(i+1)*100,(i+1)*100}});
        vr[vr.size()-1].set_fill_color(Color::red);
        vr[vr.size()-1].set_color(Color::invisible);
        win.attach(vr[vr.size()-1]);
    }
    win.attach(grid);
    //4.
    Image kutyus {Point{300,0},"ch13/200x200kep.jpeg"};
    win.attach(kutyus);
    Image kutyus1 {Point{600,200},"ch13/200x200kep.jpeg"};
    win.attach(kutyus1);
    Image kutyus2 {Point{0,400},"ch13/200x200kep.jpeg"};
    win.attach(kutyus2);
    

    win.wait_for_button();
}