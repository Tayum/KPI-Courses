using System;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    public class Model
    {
        private int id;
        protected int health; // TODO: asdf
        protected string name; // TODO: asdf
        protected double posX;
        protected double posY;

        public Model()
        {
            this.id = 0;
            this.posX = 0;
            this.posY = 0;
        }
        
        public Model(int id)
            : this()
        {
            this.id = id;
        }

        public Model(int id, double posX, double posY)
            : this(id)
        {
            this.posX = posX;
            this.posY = posY;
        }

        public int getId()
        {
            return this.id;
        }

        public double getPosition()
        {
            return Math.Sqrt(Math.Pow(posX, 2) + Math.Pow(posY, 2));
        }

        public void setPosition(double posX, double posY)
        {
            this.posX = posX;
            this.posY = posY;
        }

        public override string ToString()
        {
            return String.Format("Model:{0}. Coord:({1}:{2})", this.id, this.posX, this.posY);
        }

    }
}
