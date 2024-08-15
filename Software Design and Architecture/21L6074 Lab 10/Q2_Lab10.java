
 interface Shape
{
    void draw();
}
interface Color
{
    void fill();
}

abstract class AbstractFactory
{
    abstract Shape createShape(String type);
    abstract Color createColor(String type);
}

 class ShapeFactory extends AbstractFactory
{
    public Shape createShape(String type)
    {
        if (type.equals("circle")) {
            return new Circle();
        } else if (type.equals("rectangle"))
        {
            return new Rectangle();
        } else if (type.equals("square"))
        {
            return new Square();
        } else {
            throw new IllegalArgumentException("Invalid shape type");
        }
    }
    public Color createColor(String type)
    {
        throw new UnsupportedOperationException("Shape factory does not create colors");
    }
}

class ColorFactory extends AbstractFactory
{
    public Shape createShape(String type)
    {
        throw new UnsupportedOperationException("Color factory does not create shapes");
    }
    public Color createColor(String type)
    {
        if (type.equals("red"))
        {
            return new Red();
        } else if (type.equals("green"))
        {
            return new Green();
        } else if (type.equals("blue"))
        {
            return new Blue();
        } else
        {
            throw new IllegalArgumentException("Invalid color type");
        }
    }
}

 class Circle implements Shape
{
    public void draw()
    {
        System.out.println("Inside Circle::draw() method.");
    }
}

class Rectangle implements Shape
{
    public void draw()
    {
        System.out.println("Inside Rectangle::draw() method.");
    }
}

class Square implements Shape
{
    public void draw()
    {
        System.out.println("Inside Square::draw() method.");
    }
}

 class Red implements Color
{
    public void fill()
    {
        System.out.println("Inside Red::fill() method.");
    }
}

class Green implements Color
{
    public void fill()
    {
        System.out.println("Inside Green::fill() method.");
    }
}

class Blue implements Color
{
    public void fill()
    {
        System.out.println("Inside Blue::fill() method.");
    }
}

class FactoryGenerator
{
    public static AbstractFactory getFactory(String choice)
    {
        if (choice.equalsIgnoreCase("SHAPE"))
        {
            return new ShapeFactory();
        } else if (choice.equalsIgnoreCase("COLOR"))
        {
            return new ColorFactory();
        } else {
            throw new IllegalArgumentException("Invalid factory type");
        }
    }
}
