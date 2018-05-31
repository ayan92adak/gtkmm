#include <iostream>
#include "HelloWorldWindow.h"

HelloWorldWindow::HelloWorldWindow()
 : hello_world("Hello World")
{
    // Set the title of the window.
    set_title("Hello World");

    // Add the member button to the window,
    add(hello_world);

    // Handle the 'click' event.
    hello_world.signal_clicked().connect([] () {
          std::cout << "Hello world" << std::endl;
    });
    // Display all the child widgets of the window.
    show_all_children();
}