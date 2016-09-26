using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    class WeakKnight : Hero
    {
        public WeakKnight() : base() { }

        public override string ToString()
        {
            return String.Format("Weak Knight {0} ready!", this.Name);
        }
    }
}
