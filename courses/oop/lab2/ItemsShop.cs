using System.Collections.Generic;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    /// <summary>
    /// <para>Class to represent all the items, a Hero can handle in his backpack.</para>
    /// <para>All the items are public and static. They are also readonly and already implemented.</para>
    /// <para>User can create only one instance of this class, due to it architecture.</para>
    /// </summary>
    public class ItemsShop
    {
        /// <summary>
        /// This class forbids directly creating instance.
        /// </summary>
        private ItemsShop() { }

        /// <summary>
        /// <para>Instance of ItemsShop class.</para>
        /// <para>Only one instance of ItemsShop can be created.</para>
        /// </summary>
        private static ItemsShop instance;
        public static ItemsShop Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new ItemsShop();
                }
                return instance;
            }
        }

        /// <summary>
        /// <para>List of strings to contain all items in the shop</para>
        /// </summary>
        private List<GameItem> gameItems = GameUtils.defineBackPack();

        /// <summary>
        /// <para>User can access a list, only if a password is set.</para>
        /// </summary>
        public List<GameItem> Items
        {
            get
            {
                if (PasswordManager.isLoggedAdmin())
                {
                    return gameItems;
                }
                return null;
            }
        }
    }
}
