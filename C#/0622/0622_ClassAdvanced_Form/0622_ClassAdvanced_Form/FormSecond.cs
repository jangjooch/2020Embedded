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
    public partial class FormSecond : Form
    {
        private int count = 0;
        public FormSecond()
        {
            InitializeComponent();
            count++;
            labelShowCount.Text = count.ToString();
        }

        public void receiveText(string s)
        {
            labelReceive.Text = s;
        }
    }
}
