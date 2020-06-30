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

namespace _0622_HW_MemberSystem
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
                string[] data = File.ReadAllLines(@"./User.txt");                
                foreach(string s in data)
                {
                    string[] parse = s.Split('|');
                    users.users.Add(new User(parse[0], parse[1], int.Parse(parse[2])));
                }
            }
            catch
            {
                MessageBox.Show("No data");
            }
        }

        private void searchToolStripMenuItem_Click(object sender, EventArgs e)
        {
            View.SearchForm searchForm = new View.SearchForm();
            searchForm.ShowDialog();
        }

        private void addToolStripMenuItem_Click(object sender, EventArgs e)
        {
            View.FormAdd formAdd = new View.FormAdd();
            formAdd.ShowDialog();
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            View.FormDelete formDelete = new View.FormDelete();
            formDelete.ShowDialog();
        }

        private void timerInterrupt_Tick(object sender, EventArgs e)
        {
            using(StreamWriter sw = new StreamWriter("User.txt",false))
            {                
                foreach(User u in users.users)
                {
                    sw.WriteLine(u.UserInfo());
                }
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            timerInterrupt.Enabled = false;
            using (StreamWriter sw = new StreamWriter("User.txt",false))
            {
                foreach (User u in users.users)
                {
                    sw.WriteLine(u.UserInfo());
                }
            }
        }
    }
}
