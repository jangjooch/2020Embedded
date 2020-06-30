using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_ClassAdvanced_Form
{
    public partial class FormMain : Form
    {
        
        
        public FormMain()
        {
            InitializeComponent();
            
            
        }

        private void buttonForm_Click(object sender, EventArgs e)
        {
            FormSecond formSecond;
            formSecond = new FormSecond();
            formSecond.receiveText("Sending");
            formSecond.Show();
        }

        private void buttonNewDialog_Click(object sender, EventArgs e)
        {
            FormDialog formDialog;
            formDialog = new FormDialog();
            formDialog.ShowDialog();
        }
    }
}
