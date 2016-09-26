using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    /// <summary>
    /// Game utilities.
    /// </summary>
    public static class GameUtils
    {
        /// <summary>
        /// Random check if place (posX, posY) is free on the map.
        /// </summary>
        /// <param name="posX">Position on OX axis.</param>
        /// <param name="posY">Position on OY axis.</param>
        /// <returns>Result of the check.</returns>
        public static bool checkIfPositionIsFree(double posX = -1, double posY = -1)
        {
            if ((posX >= 100 && posY == -1) ||
                (posY >= 100 && posX == -1) ||
                (posX >= 100 && posY >= 100))
            {
                return false;
            }
            return true;
        }

        /// <summary>
        /// Fill backpack (string array) with random tools.
        /// </summary>
        /// <param name="backpack">Backpack to fill</param>
        public static string[] createBackPack()
        {
            string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
            Random r = new Random();
            string[] backpack = new string[10];
            for (int i = 0; i < backpack.Length; i++)
            {
                backpack[i] = chars[r.Next(chars.Length)].ToString() + "-item";
            }
            return backpack;
        }

        /// <summary>
        /// Return a sword (string) object with length of 10 characters.
        /// </summary>
        /// <returns>Random generated sword</returns>
        public static string createSword()
        {
            Random r = new Random();
            string sword = "";
            for (int i = 0; i < 10; i++)
            {
                sword += r.Next(i).ToString();
            }
            return sword;
        }

        /// <summary>
        /// Calculate damage for the hero.
        /// </summary>
        /// <param name="backpack">A backpack.</param>
        /// <param name="sword">A sword.</param>
        /// <returns></returns>
        public static int calculateDamageHero(string[] backpack, string sword)
        {
            // TODO: do an algorithm for the proper calculating of the damage.
            Random r = new Random();
            return r.Next(50);
        }

        /// <summary>
        /// Calculate damage for the monster.
        /// </summary>
        /// <param name="goldDrop">Gold dropped from the Monster.</param>
        /// <returns></returns>
        public static int calculateDamageMonster(int goldDrop)
        {
            // TODO: do an algorithm for the proper calculating of the damage.
            Random r = new Random();
            return r.Next(50);
        }

        public static int randInt(int min = 0, int max = 50)
        {
            Random r = new Random();
            return r.Next(min, max);
        }

        public static double randDouble(int min = 0, int max = 1)
        {
            Random r = new Random();
            return min + r.NextDouble() * max;
        }
    }
}
