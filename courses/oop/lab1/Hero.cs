using System;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    // TOASK: which is better - base.field, or this.field?
    // TOASK: here I wanted to implement Interface function doCritical() in a child. Is that really possible?
    // TODO: event, if all dragons are defeated - call a greetings func.

    /// <summary>
    /// <para>Class to represent a Hero instance.</para>
    /// <para>Hero has a sword, backpack objects, level and a lifetime.</para>
    /// It overrides Model.dealDamage and Model.prepareToFight methods.
    /// </summary>
    public class Hero : Model, IFightable
    {
        private readonly DateTime lifeTime;
        protected string[] backpack;
        protected string sword;
        protected int level;

        public Hero()
            : base()
        {
            this.lifeTime = DateTime.Now;
            this.backpack = GameUtils.createBackPack();
            this.sword = GameUtils.createSword();
            this.Damage = GameUtils.calculateDamageHero(this.backpack, this.sword);
            this.level = 1;
        }

        public Hero(string name)
            : this()
        {
            this.Name = name;
        }

        public virtual void dealDamage(Monster monster = null, Hero hero = null)
        {
            if (monster == null)
            {
                Logger.printMsgSystem("Sorry, but there is no Monster to attack!");
                return;
            }
            Logger.printMsgSystem(String.Format("Hero {0} is starting hitting a monster {1}!", this.Name, monster.getMonsterName()));
            monster.getDamage(this.Damage, hero: this);
        }

        public virtual void getDamage(int damage, Monster monster = null, Hero hero = null)
        {
            if (monster == null)
            {
                Logger.printMsgSystem("Sorry, but there is no Monster to get damage from!");
                return;
            }
            this.Health -= damage;
            Logger.printMsgPlayer(
                String.Format(
                    "Oh no, monster {0} dealed {1} damage to me, {2}!",
                    monster.getMonsterName(), damage, this.Name));
        }

        public virtual void doCritical(int damage, Monster monster = null, Hero hero = null)
        {
            Logger.printMsgSystem("This hero cannot use a critical hit ability.");
        }

        protected virtual void prepareToFight()
        {
            Logger.printMsgPlayer(String.Format("Hero {0} is ready to fight!", this.Name));
        }

        public int getCurrentHealth()
        {
            return this.Health;
        }

        public string getHeroName()
        {
            return this.Name;
        }

        public override string ToString()
        {
            return String.Format("Hero {0}. Level {1}. Has {2} items in backpack. Sword: {3}. Created at {4}.", this.Name, this.level, this.backpack.Length, this.sword, this.lifeTime);
        }
    }
}
