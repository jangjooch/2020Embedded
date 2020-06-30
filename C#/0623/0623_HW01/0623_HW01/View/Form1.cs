using _0623_HW01.Model;
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

namespace _0623_HW01
{
    public partial class Form1 : Form
    {
        Users users;
        public Form1()
        {
            InitializeComponent();
            timerInterrupt.Enabled = true;
            users = Users.GetInstance();
            try
            {
                string[] data = File.ReadAllLines(@"./Users.txt");
                foreach(string s in data)
                {
                    string[] parsed = s.Split('|');
                    users.users.Add(parsed[1], new User(parsed[0], parsed[1], int.Parse(parsed[2])));                    
                }
                MessageBox.Show("Read Complete");
            }
            catch(Exception e)
            {
                MessageBox.Show("No Data");
            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            View.FormAdd formAdd = new View.FormAdd();
            formAdd.ShowDialog();
        }

        private void buttonSear_Click(object sender, EventArgs e)
        {
            View.FormSearch formSearch = new View.FormSearch();
            formSearch.ShowDialog();
        }

        private void buttonDel_Click(object sender, EventArgs e)
        {
            View.FormDel formDel = new View.FormDel();
            formDel.ShowDialog();
        }

        private void timerInterrupt_Tick(object sender, EventArgs e)
        {
            Users users = Users.GetInstance();
            using(StreamWriter sw = new StreamWriter("./Users.txt", false))
            {
                foreach(User user in users.users.Values)
                {
                    string data = user.Personal();
                    sw.WriteLine(data);
                }
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Users users = Users.GetInstance();
            using (StreamWriter sw = new StreamWriter("./Users.txt", false))
            {
                foreach (User user in users.users.Values)
                {
                    string data = user.Personal();
                    sw.WriteLine(data);
                }
            }
        }
    }
}
