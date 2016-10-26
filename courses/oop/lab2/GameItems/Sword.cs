﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    class Sword : GameItem
    {
        private double length;
        private double materialEfficiency;

        public Sword(string name, int length, int materialEfficiency) 
            : base(name)
        {
            this.length = length;
            this.materialEfficiency = materialEfficiency;
        }

        public override void calculateEfficiency()
        {
            double efficiency = strength * agility * intelligence / 100 + length * materialEfficiency / 100 ;
            Logger.printMsgGame(String.Format("Sword {0} efficiency is {1}.", Name, efficiency));
        }
        
        public override void increaseDurability(int healValue)
        {
            this.durability += healValue * Convert.ToInt32(materialEfficiency);
            this.cost += healValue / 5 + 1;
            Logger.printMsgGame(String.Format("Sword {0} healed up to {1}! Now it costs {2}.", Name, durability, cost));
        }

        public override void decreaseDurability(int damageValue)
        {
            this.durability -= damageValue;
            this.cost -= damageValue / 5;
            Logger.printMsgGame(String.Format("Sword {0}has been damaged down to {1}! Now it costs {2}.", Name, durability, cost));
        }

        public override string ToString()
        {
            return String.Format("Sword {0}. Cost: {1}. Durability: {2}", Name, cost, durability);
        }
    }
}
