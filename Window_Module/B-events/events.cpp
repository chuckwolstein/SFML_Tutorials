/*
 sf::Event is a union, which means that only one of its members is valid at a
 time

 The valid member is the one that matches the event type, for example event.key
 for a KeyPressed event

 sf::Event instances are filled by the pollEvent (or waitEvent) function of
 the sf::Window class.

 Only these two functions can produce valid events, any attempt to use an
 sf::Event which was not returned by successful call to pollEvent (or waitEvent)
 will result in undefined behavior.
*/


/*Beginning:  typical event loop----------------------------------------------*/
sf::Event event;

// while there are pending events...
while (window.pollEvent(event))
{
    // check the type of the event...
    switch (event.type)
    {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
            ...
            break;

        // we don't process other types of events
        default:
            break;
    }
}

/*end:  typical event loop----------------------------------------------*/

/*
The sf::Event::Closed event is triggered when the user wants to close the window
*/

if (event.type == sf::Event::Closed)
    window.close();

/*
The sf::Event::Resized event is triggered when the window is resized, either
through user action or programmatically by calling window.setSize.
*/

if (event.type == sf::Event::Resized)
{
    std::cout << "new width: " << event.size.width << std::endl;
    std::cout << "new height: " << event.size.height << std::endl;
}

/*
The sf::Event::LostFocus and sf::Event::GainedFocus events are triggered when
the window loses/gains focus, which happens when the user switches the currently
active window. When the window is out of focus, it doesn't receive keyboard
events.
*/

if (event.type == sf::Event::LostFocus)
    myGame.pause();

if (event.type == sf::Event::GainedFocus)
    myGame.resume();
