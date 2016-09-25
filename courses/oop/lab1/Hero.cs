using System;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    public class Hero : Model
    {
        private static readonly DateTime globalStartTime;

        public string Name
        {
            get
            {
                return name;
            }

            set
            {
                name = value;
            }
        }

        public Hero()
        {
            
        }
    }
}
