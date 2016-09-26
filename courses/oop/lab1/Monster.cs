using System;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    public class Monster : Model, IFightable
    {
        private static int GlobalMonstersAmount { get; set; }
        protected int armor;
        protected int goldDrop;

        public Monster()
            : base()
        {
            this.Damage = GameUtils.calculateDamageMonster(this.goldDrop);
            this.armor = GameUtils.randInt();
            this.goldDrop = GameUtils.randInt(500, 1000);
        }

        public Monster(string name)
            : this()
        {
            this.Name = name;
        }

        public virtual void dealDamage(Monster monster = null, Hero hero = null)
        {
            if (hero == null)
            {
                Logger.printMsgSystem("Sorry, but there is no Hero to attack!");
                return;
            }
            Logger.printMsgSystem(String.Format("Monster {0} is starting hitting a hero {1}!", this.Name, hero.getHeroName()));
            hero.getDamage(this.Damage, monster: this);
        }

        public virtual void getDamage(int damage, Monster monster = null, Hero hero = null)
        {
            if (hero == null)
            {
                Logger.printMsgSystem("Sorry, but there is no Hero to get damage from!");
                return;
            }
            this.Health -= damage - (int)(this.armor * 0.25);
            Logger.printMsgPlayer(
                String.Format(
                    "Arrrgh, hero {0} dealed {1} damage to me, {2}!",
                    hero.getHeroName(), damage, this.Name));
        }

        public virtual void doCritical(int damage, Monster monster = null, Hero hero = null)
        {
            Logger.printMsgSystem("This monster cannot use a critical hit ability.");
        }

        protected virtual void prepareToFight()
        {
            Logger.printMsgSystem(String.Format("Monster {0} is ready to fight!", this.Name));
        }

        public int getCurrentHealth()
        {
            return base.Health;
        }

        public string getMonsterName()
        {
            return this.Name;
        }

        public override string ToString()
        {
            return String.Format("Monster {0}. Gold dropped: {1}. Has {2} armor.", this.Name, this.goldDrop, this.armor);
        }
    }
}
