using System;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    class GameMain
    {
        static void Main(string[] args)
        {
            //Logger lg = new Logger();

            //Model a = new Model(123, 5, 5);
            //Console.WriteLine(a);

            Hero h = new Hero();
            Console.WriteLine(h);
            Hero h2 = new Hero("Maxim");
            Console.WriteLine(h2);

        }
    }
}
