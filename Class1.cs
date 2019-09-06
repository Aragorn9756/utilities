using System;

public class Class1
{
	public Class1()
	{
        //structs are objects that act like variables
        struct Point2D
        {
        public int x = 0;
        public int y = 0;
        }
        
        //how to use a struct like a variable
        public void AddPoint(Point2D anotherPoint)
        {
            this.x = this.x + anotherPoint.x;
            this.y = this.y + anotherPoint.y;
        }
	}
}
