using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0623_HW01.Model
{
    class Users
    {

        public Dictionary<string, User> users = new Dictionary<string, User>();

        private static Users instance = null;
        public static Users GetInstance()
        {
            if (instance == null)
            {
                instance = new Users();
            }
            return instance;
        }
        private Users()
        {

        }

    }
}
