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
    public partial class SearchForm : Form
    {
        public SearchForm()
        {
            InitializeComponent();
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            Users users = Users.GetInstance();
            int idx = 0;
            foreach(User u in users.users)
            {
                if (u.NAME.Equals(textBoxName.Text))
                {
                    textBoxPhone.Text = u.PHONE;
                    textBoxAge.Text = u.AGE.ToString();
                    MessageBox.Show("Found");
                    break;
                }
                idx++;
            }
            if(idx == users.users.Count)
            {
                MessageBox.Show("No Member with such name");
                textBoxAge.Text = "";
                textBoxName.Text = "";
                textBoxPhone.Text = "";
            }
        }
    }
}
