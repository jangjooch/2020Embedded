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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonCallForm2_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            //TestClass testClass = new TestClass();
            TestClass testClass = TestClass.GetInstance();
            testClass.name = textBoxChange.Text;
        }

        private void buttonCheck_Click(object sender, EventArgs e)
        {
            TestClass testClass = TestClass.GetInstance();
            MessageBox.Show(testClass.name);
        }
    }
}
