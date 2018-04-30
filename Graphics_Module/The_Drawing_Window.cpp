#include <SFML/Graphics.hpp>

int main()
{
    // create the window.  Note:  RenderWindow is a class that
    //inherits from Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        //clear clears the whole window with the chosen color
        //Calling clear before drawing anything is mandatory,
        //otherwise the contents from previous frames will be present behind
        //anything you draw.
        window.clear(sf::Color::Black);

        // draw everything here...
        // draw draws whatever object you pass to it
        // window.draw(...);

        // end the current frame
        // Calling display is also mandatory, it takes what was drawn since
        //the last call to display and displays it on the window
        window.display();
    }

    return 0;
}
