using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0618_HW01
{
    class Program
    {
        static void Main(string[] args)
        {
            List<User> users = new List<User>();

            int choice = 1;

            while (true)
            {
                bool state = false;
                Console.Write("Input Choice (1 : add, 2 : list, 3 : change Name, 4 : Change Phone, 5 : View, 6 : Finish) : ");
                try
                {
                    choice = Console.Read() - '0';
                    Console.WriteLine(choice);
                    Console.ReadLine();
                    state = false;
                }
                catch(Exception e)
                {
                    Console.WriteLine("Wrong Input");
                    state = true;
                }
                if (state)
                {
                    choice = 5;
                }
                else
                {
                    if(choice == 1)
                    {
                        string name;
                        string phone;
                        Console.Write("INPUT NAME : ");
                        name = Console.ReadLine();
                        Console.Write("INPUT PHONE : ");
                        phone = Console.ReadLine();
                        User man = new User(name, phone);
                        users.Add(man);
                    }
                    else if(choice == 2)
                    {
                        int idx = 0;
                        foreach(User u in users)
                        {                            
                            Console.Write(idx + " ");
                            u.Personal();
                            idx++;
                        }
                    }
                    else if(choice == 3)
                    {
                        int idx = 0;
                        string name;
                        Console.Write("INPUT IDX : ");
                        idx = Console.Read() - '0';
                        Console.ReadLine();

                        Console.Write("INPUT NAME : ");
                        name = Console.ReadLine();
                        users[idx].name = name;                        
                    }
                    else if(choice == 4)
                    {
                        int idx = 0;
                        string phone;
                        Console.Write("INPUT IDX : ");
                        idx = Console.Read() - '0';
                        Console.ReadLine();

                        Console.Write("INPUT PHONE : ");
                        phone = Console.ReadLine();
                        users[idx].phone = phone;
                    }
                    else if(choice == 5)
                    {
                        string name;
                        Console.Write("INPUT NAME : ");
                        name = Console.ReadLine();
                        foreach(User u in users)
                        {
                            if (u.name.Equals(name))
                            {
                                u.Personal();
                            }
                        }
                    }
                    else if(choice == 6)
                    {
                        int idx = 0;
                        foreach (User u in users)
                        {
                            Console.Write(idx + " ");
                            u.Personal();
                            idx++;
                        }
                        break;
                    }
                }
            }

        }
    }
}
