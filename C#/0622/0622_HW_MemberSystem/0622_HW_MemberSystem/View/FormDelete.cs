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
    public partial class FormDelete : Form
    {
        public FormDelete()
        {
            InitializeComponent();
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            Users users = Users.GetInstance();
            int idx = 0;
            int oriCount = users.users.Count;
            foreach (User u in users.users)
            {
                if(u.NAME.Equals(textBoxName.Text) && u.PHONE.Equals(textBoxPhone.Text))
                {
                    users.users.RemoveAt(idx);
                    MessageBox.Show("Delete Complete");
                    textBoxName.Text = "";
                    textBoxPhone.Text = "";
                    break;
                }               
                idx++;
            }
            if(idx == oriCount)
            {
                MessageBox.Show("Nothing to Delete");
                textBoxName.Text = "";
                textBoxPhone.Text = "";
            }
        }
    }
}
