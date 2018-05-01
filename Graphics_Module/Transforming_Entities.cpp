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

/* Position

The position is the... position of the entity in the 2D world.
I don't think it needs more explanation :).*/
// 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other
//transformable class

// set the absolute position of the entity
entity.setPosition(10, 50);

// move the entity relatively to its current position
entity.move(5, 5);

// retrieve the absolute position of the entity
sf::Vector2f position = entity.getPosition(); // = (15, 55)

//By default, entities are positioned relative to their top-left corner. We'll
see how to change that with the 'origin' property later.
/* Rotation

The rotation is the orientation of the entity in the 2D world. It is defined in
degrees, in clockwise order (because the Y axis is pointing down in SFML).*/

// 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class

// set the absolute rotation of the entity
entity.setRotation(45);

// rotate the entity relatively to its current orientation
entity.rotate(10);

// retrieve the absolute rotation of the entity
float rotation = entity.getRotation(); // = 55

//Note that SFML always returns an angle in range [0, 360) when you call
//getRotation.

//As with the position, the rotation is performed around the top-left corner by
//default, but this can be changed by setting the origin.




/* Scale

The scale factor allows the entity to be resized. The default scale is 1.
Setting it to a value less than 1 makes the entity smaller, greater than 1
makes it bigger. Negative scale values are also allowed, so that you can
mirror the entity.*/

// 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class

// set the absolute scale of the entity
entity.setScale(4.0f, 1.6f);

// scale the entity relatively to its current scale
entity.scale(0.5f, 0.5f);

// retrieve the absolute scale of the entity
sf::Vector2f scale = entity.getScale(); // = (2, 0.8)


/* Origin

The origin is the center point of the three other transformations. The entity's
position is the position of its origin, its rotation is performed around the
origin, and the scale is applied relative to the origin as well. By default,
it is the top-left corner of the entity (point (0, 0)), but you can set it to
the center of the entity, or any other corner of the entity for example.

To keep things simple, there's only a single origin for all three
transformation components. This means that you can't position an entity
relative to its top-left corner while rotating it around its center for
example. If you need to do such things, have a look at the next chapters.*/

// 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class

// set the origin of the entity
entity.setOrigin(10, 20);

// retrieve the origin of the entity
sf::Vector2f origin = entity.getOrigin(); // = (10, 20)

//Note that changing the origin also changes where the entity is drawn on
//screen, even though its position property hasn't changed. If you don't
//understand why, read this tutorial one more time!



/* Transforming your own classes

sf::Transformable is not only made for SFML classes, it can also be a
base (or member) of your own classes.*/
class MyGraphicalEntity : public sf::Transformable
{
    // ...
};

MyGraphicalEntity entity;
entity.setPosition(10, 30);
entity.setRotation(110);
entity.setScale(0.5f, 0.2f);

//To retrieve the final transform of the entity (commonly needed when drawing
//it), call the getTransform function. This function returns a sf::Transform
//object. See below for an explanation about it, and how to use it to transform
//an SFML entity.

//If you don't need/want the complete set of functions provided by the
//sf::Transformable interface, don't hesitate to simply use it as a member
//instead and provide your own functions on top of it. It is not abstract,
//so it is possible to instantiate it instead of only being able to use it as
//a base class.


/* Custom transforms

The sf::Transformable class is easy to use, but it is also limited. Some users
might need more flexibility. They might need to specify a final transformation
as a custom combination of individual transformations. For these users, a
lower-level class is available: sf::Transform. It is nothing more than a 3x3
matrix, so it can represent any transformation in 2D space.

There are many ways to construct a sf::Transform:

1. by using the predefined functions for the most common
    transformations (translation, rotation, scale)
2. by combining two transforms
3. by specifying its 9 elements directly


Here are a few examples:*/

// the identity transform (does nothing)
sf::Transform t1 = sf::Transform::Identity;

// a rotation transform
sf::Transform t2;
t2.rotate(45);

// a custom matrix
sf::Transform t3(2, 0, 20,
                 0, 1, 50,
                 0, 0, 1);

// a combined transform
sf::Transform t4 = t1 * t2 * t3;

/* You can apply several predefined transformations to the same transform as
well. They will all be combined sequentially:*/
sf::Transform t;
t.translate(10, 100);
t.rotate(90);
t.translate(-10, 50);
t.scale(0.5f, 0.75f);

/* Back to the point: How can a custom transform be applied to a graphical
entity? Simple: Pass it to the draw function. */
window.draw(entity, transform);

//... which is in fact a short-cut for:
sf::RenderStates states;
states.transform = transform;
window.draw(entity, states);

//If your entity is a sf::Transformable (sprite, text, shape), which contains
//its own internal transform, both the internal and the passed transform are
//combined to produce the final transform.

/* Bounding boxes

After transforming entities and drawing them, you might want to perform some
computations using them e.g. checking for collisions.

SFML entities can give you their bounding box. The bounding box is the minimal
rectangle that contains all points belonging to the entity, with sides aligned
to the X and Y axes.

The bounding box is very useful when implementing collision detection: Checks
against a point or another axis-aligned rectangle can be done very quickly,
and its area is close enough to that of the real entity to provide a good
approximation.*/

// get the bounding box of the entity
sf::FloatRect boundingBox = entity.getGlobalBounds();

// check collision with a point
sf::Vector2f point = ...;
if (boundingBox.contains(point))
{
    // collision!
}

// check collision with another box (like the bounding box of another entity)
sf::FloatRect otherBox = ...;
if (boundingBox.intersects(otherBox))
{
    // collision!
}

//The function is named getGlobalBounds because it returns the bounding box of
//the entity in the global coordinate system, i.e. after all of its
//transformations (position, rotation, scale) have been applied.

//There's another function that returns the bounding box of the entity in its
//local coordinate system (before its transformations are applied):
//getLocalBounds. This function can be used to get the initial size of an
//entity, for example, or to perform more specific calculations.

/* Object hierarchies (scene graph)

With the custom transforms seen previously, it becomes easy to implement a
hierarchy of objects in which children are transformed relative to their parent.
All you have to do is pass the combined transform from parent to children when
you draw them, all the way until you reach the final drawable entities
(sprites, text, shapes, vertex arrays or your own drawables).*/

// the abstract base class
class Node
{
public:

    // ... functions to transform the node

    // ... functions to manage the node's children

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
    {
        // combine the parent transform with the node's one
        sf::Transform combinedTransform = parentTransform * m_transform;

        // let the node draw itself
        onDraw(target, combinedTransform)

        // draw its children
        for (std::size_t i = 0; i < m_children.size(); ++i)
            m_children[i]->draw(target, combinedTransform);
    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;

    sf::Transform m_transform;
    std::vector<Node*> m_children;
};

// a simple derived class: a node that draws a sprite
class SpriteNode : public Node
{
public:

    // .. functions to define the sprite

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
    {
        target.draw(m_sprite, transform);
    }

    sf::Sprite m_sprite;
};
