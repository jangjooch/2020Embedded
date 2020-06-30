using _0623_HW01.Control;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0623_HW01.View
{
    public partial class FormDel : Form
    {
        public FormDel()
        {
            InitializeComponent();
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            string getname = textBoxName.Text;
            string getphone = textBoxPhone.Text;
            UsersEditing usersEditing = new UsersEditing();
            bool status = usersEditing.DelUser(getname, getphone);
            if (status)
            {
                MessageBox.Show("Delete Complete");
                textBoxName.Text = "";
                textBoxPhone.Text = "";
            }
            else
            {
                MessageBox.Show("Delete Fail");
                textBoxName.Text = "";
                textBoxPhone.Text = "";
            }
        }
    }
}
