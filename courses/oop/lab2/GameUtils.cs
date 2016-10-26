using System;
using System.Collections.Generic;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    /// <summary>
    /// <para>Class to represent useful game utilities.</para>
    /// <para>This class mostly used for generation different type of data.</para>
    /// </summary>
    public static class GameUtils
    {
        /// <summary>
        /// <para>Sole ItemsShop to get access to the ItemsShop list.</para>
        /// </summary>
        static GameUtils()
        {
            PasswordManager.logAdmin("12345");
        }

        /// <summary>
        /// <para>Random check if place (posX, posY) is free on the map.</para>
        /// </summary>
        /// <param name="posX">Position on OX axis.</param>
        /// <param name="posY">Position on OY axis.</param>
        /// <returns>Result of the check.</returns>
        public static bool checkIfPositionIsFree(double posX = -1, double posY = -1)
        {
            bool positionIsValid = (posX >= 100 && posY >= 100);
            bool positionValidX = (posX >= 100 && posY == -1);
            bool positionValidY = (posY >= 100 && posX == -1);
            bool positionIsFree = positionIsValid || positionValidX || positionValidY;
            if (positionIsFree)
            {
                return false;
            }
            return true;
        }

        public static List<GameItem> defineBackPack()
        {
            List<GameItem> backpack = new List<GameItem>();
            backpack.Add(new Sword("magic_sword", 100, 50));
            backpack.Add(new Sword("magic_sword", 200, 60));
            backpack.Add(new Sword("magic_sword", 300, 70));
            backpack.Add(new Shield("mega_shield", 50, 100));
            backpack.Add(new Shield("mega_shield", 60, 200));
            backpack.Add(new Shield("mega_shield", 70, 300));
            
            return backpack;
        }
        
        /// <summary>
        /// <para>Fill backpack (GameItem list) with random tools and return it.</para>
        /// <para>Used by initializing a field [backpack] by Heroes.</para>
        /// </summary>
        /// <param name="backpack">Backpack to fill</param>
        public static List<GameItem> createBackPack()
        {
            if (!PasswordManager.isLoggedAdmin())
                return (new List<GameItem>());

            ItemsShop itemsShopInst = ItemsShop.Instance;
            List<GameItem> backpack = new List<GameItem>(itemsShopInst.Items);
            return backpack;
        }

        /// <summary>
        /// <para>Return a sword (string) object with length of 10 characters.</para>
        /// </summary>
        /// <returns>Random generated sword</returns>
        public static string createSword()
        {
            return "NewSwordName";
        }

        /// <summary>
        /// <para>Calculate damage for the hero, depending on his backpack and current sword.</para>
        /// </summary>
        /// <param name="backpack">A backpack.</param>
        /// <param name="sword">A sword.</param>
        /// <returns></returns>
        public static int calculateDamageHero(List<GameItem> backpack, string sword)
        {
            // todo: implementation of the real damange from the backpack
            Random r = new Random();
            return r.Next(50);
        }

        /// <summary>
        /// <para>Calculate damage for the monster, depending on the goldDrop.</para>
        /// </summary>
        /// <param name="goldDrop">Gold dropped from the Monster.</param>
        /// <returns></returns>
        public static int calculateDamageMonster(int goldDrop)
        {
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
