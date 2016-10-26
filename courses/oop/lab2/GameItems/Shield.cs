using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    class Shield : GameItem
    {
        private double diameter;
        private double weight;

        public Shield(string name, int diameter, int weight) 
            : base(name)
        {
            this.diameter = diameter;
            this.weight = weight;
        }

        public override void calculateEfficiency()
        {
            double efficiency = 27 * diameter - weight + strength + agility * intelligence / 100;
            Logger.printMsgGame(String.Format("Shield {0} efficiency is {1}.", Name, efficiency));
        }

        public override void increaseDurability(int healValue)
        {
            this.durability += healValue * Convert.ToInt32(diameter * 2.5 * weight);
            this.cost += healValue / 3 + 25 - Convert.ToInt32(this.diameter * 0.5);
            Logger.printMsgGame(String.Format("Shield {0} healed up to {1}! Now it costs {2}.", Name, durability, cost));
        }

        public override void decreaseDurability(int damageValue)
        {
            this.durability -= damageValue * Convert.ToInt32(weight * diameter / 100);
            this.cost -= damageValue / 5 * 3;
            Logger.printMsgGame(String.Format("Shield {0} damaged down to {1}! Now it costs {2}.", Name, durability, cost));
        }

        public override string ToString()
        {
            return String.Format("Shield {0}. Cost: {1}. Durability: {2}", Name, cost, durability);
        }
    }
}
