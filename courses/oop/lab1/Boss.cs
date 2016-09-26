﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    class Boss : Monster
    {
        private double criticalChance;
        private int jewelDrop;

        public Boss(string name)
            : base(name)
        {
            this.criticalChance = GameUtils.randDouble();
            this.jewelDrop = GameUtils.randInt(max: 10);
        }

        public override void doCritical(int damage, Monster monster = null, Hero hero = null)
        {
            if (hero == null)
            {
                Logger.printMsgSystem("Sorry, but there is no Hero to attack!");
                return;
            }
            Logger.printMsgSystem("Monster {0} did a critical damage to {1}!", this.Name, hero.getHeroName());
            int criticalDamageToDeal = (int)(this.Damage * this.criticalChance) + this.Damage;
            hero.getDamage(criticalDamageToDeal);
        }

        public override string ToString()
        {
            return String.Format("Hello, I am a boss {0}. How you doin?", this.Name);
        }

    }
}