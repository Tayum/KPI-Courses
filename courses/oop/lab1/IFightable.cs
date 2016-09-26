using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    interface IFightable
    {
        void dealDamage(Monster monster = null, Hero hero = null);
        void getDamage(int damage, Monster monster = null, Hero hero = null);
        void doCritical(int damage, Monster monster = null, Hero hero = null);
    }
}
