﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    class CasualMonster : Monster
    {
        public CasualMonster() : base() { }

        public override string ToString()
        {
            return String.Format("Arrrgh, I will kill you! By the way, my name is {0}.", this.Name);
        }
    }
}
