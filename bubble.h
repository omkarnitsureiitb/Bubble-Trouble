#include <simplecpp>

/* Bubble Vars */
const int BUBBLE_START_X = 250;
const int BUBBLE_START_Y = 50;
const int BUBBLE_DEFAULT_RADIUS = 10;
const int BUBBLE_RADIUS_THRESHOLD = 20;
const int BUBBLE_DEFAULT_VX = 100;
const int BUBBLE_DEFAULT_VY = 0;
const int BUBBLE_Y_ACCELERATION = 10;
const int PLAY_Y_HEIGHT = 450;

class Bubble
{
private:
    Circle circle;  // the circle representing the bubble
    double vx, vy, ay;  // velocity in x and y direction,accleration in y direction
    Color color;    // color of the bubble

public:
    Bubble(double cx, double cy, double r, double vx_=BUBBLE_DEFAULT_VX, double vy_=BUBBLE_DEFAULT_VY, double ay_ =BUBBLE_Y_ACCELERATION, Color color_=COLOR(0, 0, 255))
    {
        // Bubble constructor
        color = color_;
        circle = Circle(cx, cy, r);
        circle.setColor(color);
        circle.setFill(true);

        vx = vx_;
        vy = vy_;
        ay = ay_;
    }

    void nextStep(double t)
    {
        vy += ay*t;      //  Updating velocity in y direction due to acceleration before moving to the next position
        double new_x = circle.getX() + vx*t;      //   evaluating the next position of the bubble
        double new_y = circle.getY() + vy*t;

        if ((vx < 0 && new_x < (0 + circle.getRadius())) // bounce along X direction at left border
            ||
            (vx > 0 && new_x > (WINDOW_X - circle.getRadius()))) // bounce along X direction at right border
        {

            vx = -vx;
            new_x = circle.getX() + vx*t;

        }

        if (circle.getRadius() + circle.getY() > PLAY_Y_HEIGHT)     //   bounce along the y direction at the bottom border blue line
        {

            vy = -vy;
            new_y = circle.getY() + vy*t;

        }

        if ((circle.getY() - BUBBLE_START_Y < circle.getRadius()) && (vy < 0))       //   bounce back after touching the top border
        {
            vy = -vy;
            new_y = circle.getY() + vy*t;
        }

        circle.moveTo(new_x, new_y);      //   Moving the bubble to the next position
    }

    double get_radius()
    {
        // return the radius of the bubble
        return circle.getRadius();
    }

    double get_center_x()
    {
        // return the x coordinate of the center of the bubble
        return circle.getX();
    }

    double get_center_y()
    {
        // return the y coordinate of the center of the bubble
        return circle.getY();
    }

    double get_vx()
    {
        // return the x velocity of the bubble
        return vx;
    }
    double get_vy()
    {
        // return the y velocity of the bubble
        return vy;
    }

    Color get_color()
    {
        // return the color of the bubble
        return color;
    }
};
