using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_HW_MemberSystem.View
{
    public partial class FormAdd : Form
    {
        public FormAdd()
        {
            InitializeComponent();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            Users users = Users.GetInstance();
            string getname = textBoxName.Text;
            string getphone = textBoxPhone.Text;
            string getage = textBoxAge.Text;

            int idx = 0;
            foreach (User u in users.users)
            {
                if (u.PHONE.Equals(getphone))
                {
                    MessageBox.Show("Already Exist");
                    textBoxPhone.Text = "";
                    textBoxName.Text = "";
                    textBoxAge.Text = "";
                    break;
                }
                idx++;
            }

            if(idx == users.users.Count)
            {
                try
                {
                    int intage = int.Parse(getage);
                    users.users.Add(new User(getname, getphone, intage));
                    MessageBox.Show("ADD Complete");
                    textBoxAge.Text = "";
                    textBoxPhone.Text = "";
                    textBoxName.Text = "";
                }
                catch
                {
                    MessageBox.Show("Invaild Age Value");
                    textBoxAge.Text = "";
                }
            }
        }
    }
}
