using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab1_Gonchar_Maxim_KP51
{
    internal static class PasswordManager
    {
        /// <summary>
        /// <para>Admin access to get all passwords.</para>
        /// </summary>
        private static bool isAdmin = false;

        /// <summary>
        /// <para>Log as admin to the system.</para>
        /// </summary>
        /// <param name="pass">Correct admin password.</param>
        public static void logAdmin(string pass)
        {
            if (String.IsNullOrEmpty(pass))
                return;

            isAdmin = (pass == "12345") ? true : false;
        }

        /// <summary>
        /// <para>Return result if user is an admin.</para>
        /// </summary>
        /// <returns>If user is an admin.</returns>
        public static bool isLoggedAdmin()
        {
            return isAdmin;
        }
    }
}
