using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_Form_Transmit
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void buttonShow_Click(object sender, EventArgs e)
        {
            TestClass testClass = TestClass.GetInstance();
            MessageBox.Show(testClass.name);
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            
            TestClass testClass = TestClass.GetInstance();
            testClass.name = textBoxSend.Text;
        }
    }
}
