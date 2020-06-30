using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0619_DicVer
{
    public partial class Form1 : Form
    {
        Dictionary<string, User> users;
        public Form1()
        {
            InitializeComponent();
            users = new Dictionary<string, User>();
            //string[] loaded = File.ReadAllLines(@"./User.txt");            
            try
            {
                string[] loaded = File.ReadAllLines(@"./User.txt");

                foreach (string s in loaded)
                {
                    string[] infos = s.Split('|');
                    users.Add(infos[1], new User(infos[0], infos[1], int.Parse(infos[2])));
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("No Data");
            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            string getName = textBoxAddName.Text;
            string getPhone = textBoxAddPhone.Text;
            string getAge = textBoxAddAge.Text;
            int intage;
            try
            {
                intage = int.Parse(getAge);
                if (!users.ContainsKey(getPhone))
                {
                    users.Add(getPhone, new User(getName, getPhone, intage));
                    MessageBox.Show("Add Complete");
                    textBoxAddAge.Text = "";
                    textBoxAddName.Text = "";
                    textBoxAddPhone.Text = "";
                }
                else
                {
                    MessageBox.Show("Already Exist");
                    textBoxAddPhone.Text = "";
                }
            }
            catch (Exception)
            {
                intage = 0;
                MessageBox.Show("Invaild Age Value");
                textBoxAddAge.Text = "";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string getPhone = textBoxSearchPhone.Text;
            int idx = 0;
            foreach(string s in users.Keys)
            {
                
                if (s.Equals(getPhone))
                {
                    MessageBox.Show(users[s].Personal());                    
                    break;
                }
                idx++;
            }
            if(idx == users.Count)
            {
                MessageBox.Show("No Data");
            }
            textBoxSearchPhone.Text = "";
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            using(StreamWriter sw = new StreamWriter("User.txt", false))
            {
                foreach(User u in users.Values)
                {
                    sw.WriteLine(u.Personal());
                }                
            }
        }
    }
}
