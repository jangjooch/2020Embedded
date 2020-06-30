using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0623_Winform_Interface01
{
    public partial class Form1 : Form
    {
        int pictureIdx;
        public Form1()
        {
            InitializeComponent();
            pictureIdx = 1;
            timerPictureChange.Enabled = true;
        }
        private void CheckBoxSelectionReceive(object sender, EventArgs e)
        {
            string data = "";
            if (checkBox1.Checked)
            {
                data += "1 ";
                //MessageBox.Show("checkBox 1 Checked");
            }
            if (checkBox2.Checked)
            {
                data += "2 ";
                //MessageBox.Show("checkBox 2 Checked");
            }
            if (checkBox3.Checked)
            {
                data += "3 ";
                //MessageBox.Show("checkBox 3 Checked");
            }
            MessageBox.Show("checkBox " + data + " Checked");
            foreach(var item in Controls)
            {
                if(item is GroupBox)
                {                    
                    foreach(var inside in ((GroupBox)item).Controls)
                    {
                        if (inside is CheckBox)
                        {
                            if (((CheckBox)inside).Checked)
                            {
                                MessageBox.Show(((CheckBox)inside).Text);
                            }
                        }
                    }
                }

            }
        }

        private void RadioBoxSelectionReceive(object sender, EventArgs e)
        {
            foreach(var i in Controls)
            {
                if(i is GroupBox)
                {
                    if (((GroupBox)i).Name.Equals("groupBoxRadioButton"))
                    {
                        foreach (var inside in ((GroupBox)i).Controls)
                        {
                            if (inside is RadioButton)
                            {
                                if (((RadioButton)inside).Checked)
                                {
                                    MessageBox.Show(((RadioButton)inside).Text);
                                }
                            }
                        }
                    }
                }
            }
        }

        private void RadioImageChange(object sender, EventArgs e)
        {            
            foreach(var item in Controls)
            {
                if(item is GroupBox)
                {
                    if (((GroupBox)item).Name.Equals("groupBoxRadioButton"))
                    {
                        foreach(var inside in (((GroupBox)item).Controls))
                        {
                            if(inside is RadioButton)
                            {
                                if (((RadioButton)inside).Checked)
                                {
                                    if (((RadioButton)inside).Name==("radioButton1"))
                                    {
                                        //pictureBoxChanging01.ImageLocation = "./cat01.jpg";
                                        pictureIdx = 1;
                                    }
                                    else if (((RadioButton)inside).Name==("radioButton2"))
                                    {
                                        //pictureBoxChanging01.ImageLocation = "./cat02.jpg";
                                        pictureIdx = 2;
                                    }
                                    else if (((RadioButton)inside).Name.Equals("radioButton3"))
                                    {
                                        //pictureBoxChanging01.ImageLocation = "./cat03.jpg";
                                        pictureIdx = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        private void TimerPicureChange(object sender, EventArgs e)
        {            
            pictureIdx++;
            if(pictureIdx > 3)
            {
                pictureIdx = 1;
            }
            string path = "./cat0" + pictureIdx.ToString() + ".jpg";
            pictureBoxChanging01.ImageLocation = path;
            /*
            if (pictureIdx == 1)
            {
                pictureBoxChanging01.ImageLocation = "./cat01.jpg";
            }
            else if (pictureIdx == 2)
            {
                pictureBoxChanging01.ImageLocation = "./cat02.jpg";
            }
            else if (pictureIdx == 3)
            {
                pictureBoxChanging01.ImageLocation = "./cat03.jpg";
            }
            */
        }
    }



}
