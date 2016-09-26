using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    class SwordsMan : Hero
    {
        private double criticalChance;

        public SwordsMan(string name)
            : base(name)
        {
            this.criticalChance = GameUtils.randDouble();
            this.Name = name;
        }

        public override void doCritical(int damage, Monster monster = null, Hero hero = null)
        {
            if (monster == null)
            {
                Logger.printMsgSystem("Sorry, but there is no Monster to attack!");
                return;
            }
            Logger.printMsgSystem(String.Format("Hero {0} did a critical damage to {1}!", this.Name, monster.getMonsterName()));
            int criticalDamageToDeal = (int)(this.Damage * this.criticalChance) + this.Damage;
            monster.getDamage(criticalDamageToDeal);
        }

        public override string ToString()
        {
            return String.Format("Hero {0}. Level {1}. Has {2} items in backpack. Sword: {3}. Critical damage: {4}.", this.Name, this.level, this.backpack.Length, this.sword, this.criticalChance);
        }
    }
}
