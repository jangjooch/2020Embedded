using _0623_HW01.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0623_HW01.Control
{
    class UsersEditing
    {
        public bool AddUser(string name, string phone, int age)
        {
            Users users = Users.GetInstance();

            if (users.users.ContainsKey(phone))
            {
                return false;
            }
            else
            {
                users.users.Add(phone, new User(name, phone, age));
                return true;
            }
        }

        public bool DelUser(string name, string phone)
        {
            Users users = Users.GetInstance();

            Dictionary<string, User> copy = new Dictionary<string, User>();

            if (users.users.ContainsKey(phone))
            {
                foreach(var u in users.users)
                {
                    if(u.Value.NAME == name)
                    {
                        users.users.Remove(phone);
                        return true;
                    }
                }
            }
            else
            {
                return false;
            }
            return false;
        }

        public List<User> SearchUser(string content, int select)
        {
            List<User> keys = new List<User>();
            Users users = Users.GetInstance();
            if (select == 1)
            {                
                foreach (var u in users.users)
                {
                    if(u.Value.NAME == content)
                    {
                        keys.Add(u.Value);
                    }
                }
            }
            else if (select == 2)
            {
                foreach (var u in users.users)
                {
                    if (u.Value.PHONE == content)
                    {
                        keys.Add(u.Value);
                    }
                }
            }
            else if (select == 3)
            {
                foreach (var u in users.users)
                {
                    if (u.Value.AGE.ToString() == content)
                    {
                        keys.Add(u.Value);
                    }
                }
            }            
            return keys;
        }
    }
}
