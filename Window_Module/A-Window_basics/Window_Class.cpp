#include <Window.hpp>

Class Window {
public:

  Window (VideoMode mode, const String &title, Uint32 style=Style::Default, const ContextSettings &settings=ContextSettings())
  /* Constructor for a window
      mode--> 	Video mode to use (defines the width, height and depth of the rendering area of the window)
      title-->	Title of the window
      stlye-->  Window style, a bitwise OR combination of sf::Style enumerators
        Style options:
          sf::Style::None	No decoration at all (useful for splash screens, for example);
                this style cannot be combined with others
          sf::Style::Titlebar	The window has a titlebar
          sf::Style::Resize	The window can be resized and has a maximize button
          sf::Style::Close	The window has a close button
          sf::Style::Fullscreen	The window is shown in fullscreen mode; this style cannot
                be combined with others, and requires a valid video mode
          sf::Style::Default	The default style, which is a shortcut for
              Titlebar | Resize | Close


      settings--> Additional settings for the underlying OpenGL context
  */

  void 	close ()
  // 	Close the window and destroy all the attached resources.

  bool 	isOpen () const
  // Tell whether or not the window is open.

  bool 	pollEvent (Event &event)
   	//Pop the event on top of the event queue, if any, and return it.

    Vector2i 	getPosition () const
     //	Get the position of the window. More...

    void 	setPosition (const Vector2i &position)
     	//Change the position of the window on screen. More...

      Vector2u 	getSize () const
     	//Get the size of the rendering region of the window. More...

    void 	setSize (const Vector2u &size)
     	//Change the size of the rendering region of the window. More...

    void 	setTitle (const String &title)
     	//Change the title of the window. More...


    void 	setVisible (bool visible)
    // 	Show or hide the window. More...

    void 	setMouseCursorVisible (bool visible)
 	//Show or hide the mouse cursor. More...

  void 	setMouseCursorGrabbed (bool grabbed)
 	//Grab or release the mouse cursor. More...

  void 	setKeyRepeatEnabled (bool enabled)
 	//Enable or disable automatic key-repeat. More...

  void 	display ()
   	//Display on screen what has been rendered to the window so far. More...

protected:
  virtual void 	onCreate ()
   	//Function called after the window has been created. More...

  virtual void 	onResize ()
   	//Function called after the window has been resized. More...

};
