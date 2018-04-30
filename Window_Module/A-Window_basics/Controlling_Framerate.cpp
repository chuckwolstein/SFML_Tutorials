/*
Sometimes, when your application runs fast, you may notice visual artifacts such
as tearing. The reason is that your application's refresh rate is not
synchronized with the vertical frequency of the monitor, and as a result, the
bottom of the previous frame is mixed with the top of the next one.
The solution to this problem is to activate vertical synchronization.
*/

window.setVerticalSyncEnabled(true); // call it once, after creating the window

/*
In other situations, you may also want your application to run at a given
framerate, instead of the monitor's frequency. This can be done by calling
setFramerateLimit:
*/

window.setFramerateLimit(60); // call it once, after creating the window

/*
Never use both setVerticalSyncEnabled and setFramerateLimit at the same time!
They would badly mix and make things worse.
*/
