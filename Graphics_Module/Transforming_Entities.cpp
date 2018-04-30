/* Transforming SFML entities

All SFML classes (sprites, text, shapes) use the same interface for
transformations: sf::Transformable. This base class provides a simple API to
move, rotate and scale your entities. It doesn't provide maximum flexibility,
but instead defines an interface which is easy to understand and to use, and
which covers 99% of all use cases -- for the remaining 1%, see the last
chapters.

sf::Transformable (and all its derived classes) defines four properties:
position, rotation, scale and origin.

They all have their respective getters and setters. These transformation
components are all independent of one another: If you want to change the
orientation of the entity, you just have to set its rotation property,
you don't have to care about the current position and scale. */
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
