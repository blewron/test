#include<gdiplusgraphics.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    
    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set the drawing color to red
    setcolor(RED);

    // Draw a rectangle
    rectangle(100, 100, 200, 200);
    floodfill(150, 150, RED);

    // Close the graphics mode
    closegraph();

    return 0;
}
