/*The class that provides access to the keyboard state is sf::Keyboard. It only
contains one function, isKeyPressed, which checks the current state of a key
(pressed or released). It is a static function, so you don't need to
instantiate sf::Keyboard to use it.

This function directly reads the keyboard state, ignoring the focus state of
your window. This means that isKeyPressed may return true even if your window
is inactive.

*************Key codes are defined in the sf::Keyboard::Key enum.***************

But the most important ones for our game are:

Left
Left arrow.

Right
Right arrow.

Up
Up arrow.

Down
Down arrow.

Space
The Space key.

Return
The Return key.

BackSpace
The Backspace key.

Escape
The Escape key.
*/
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    // left key is pressed: move our character
    character.move(1, 0);
}


/*The class that provides access to the mouse state is sf::Mouse. Like its
friend sf::Keyboard, sf::Mouse only contains static functions and is not meant
to be instantiated (SFML only handles a single mouse for the time being).

You can check if buttons are pressed:*/

if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{
    // left mouse button is pressed: shoot
    gun.fire();
}

/* Mouse button codes are defined in the sf::Mouse::Button enum. SFML supports
up to 5 buttons: left, right, middle (wheel), and two additional buttons
whatever they may be.

You can also get and set the current position of the mouse, either relative to
the desktop or to a window: */

// get the global mouse position (relative to the desktop)
sf::Vector2i globalPosition = sf::Mouse::getPosition();

// get the local mouse position (relative to a window)
sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a
                                                            //sf::Window

// set the mouse position globally (relative to the desktop)
sf::Mouse::setPosition(sf::Vector2i(10, 50));

// set the mouse position locally (relative to a window)
sf::Mouse::setPosition(sf::Vector2i(10, 50), window); // window is a sf::Window

/**/
/**/
/**/
/**/
/**/
/**/
/**/
