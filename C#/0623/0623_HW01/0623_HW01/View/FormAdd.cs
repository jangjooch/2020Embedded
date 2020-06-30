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
    public partial class FormAdd : Form
    {
        public FormAdd()
        {
            InitializeComponent();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            string getName = textBoxName.Text;
            string getphone = textBoxPhone.Text;
            string getage = textBoxAge.Text;
            try
            {
                int intage = int.Parse(getage);
                UsersEditing usersEditing = new UsersEditing();
                bool status = usersEditing.AddUser(getName, getphone, intage);

                if (status)
                {
                    MessageBox.Show("Add Complete");
                    textBoxName.Text = "";
                    textBoxPhone.Text = "";
                    textBoxAge.Text = "";
                }
                else
                {
                    MessageBox.Show("Already Exist");                    
                    textBoxPhone.Text = "";                    
                }
                
            }
            catch (Exception ex)
            {
                MessageBox.Show("Invaild Age Value");                
                textBoxAge.Text = "";
            }
        }
    }
}
