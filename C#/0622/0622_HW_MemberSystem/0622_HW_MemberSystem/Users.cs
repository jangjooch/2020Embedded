using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0622_HW_MemberSystem
{
    class Users
    {

        public List<User> users = new List<User>();

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
