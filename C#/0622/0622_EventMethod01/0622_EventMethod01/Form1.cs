using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0622_EventMethod01
{
    public partial class Form1 : Form
    {
        Thread threadTest;

        public Form1()
        {
            
            InitializeComponent();

            button1.Click += Timer_start;
            button2.Click += Timer_stop;
        }

        private void Button_Click(object sender, EventArgs e)
        {
            Button self = (Button)sender;

            MessageBox.Show("Costomize Click by " + self.Text);
            // self.Text -> 어떠한 것을 통해 Trigger가 발동되었는 지 확인할 수 있다.
        }

        private void Timer_start(object sender, EventArgs e)
        {
            timerInterrupt.Enabled = true;
        }

        private void Timer_stop(object sender, EventArgs e)
        {
            timerInterrupt.Enabled = false;
        }

        private void timerInterrupt_Tick(object sender, EventArgs e)
        {
            labelTime.Text = DateTime.Now.ToString("HH:mm:ss");
        }

        private void buttonThreadStart_Click(object sender, EventArgs e)
        {            
            threadTest = new Thread(new ThreadStart(ThreadMethod));
            threadTest.Start();
        }

        private void buttonThreadEnd_Click(object sender, EventArgs e)
        {
            threadTest.Abort();
        }

        public void ThreadMethod()
        {
            labelThreadTest.Text = "";
            for(int i = 0; ; i++)
            {
                labelThreadTest.Invoke(new MethodInvoker(delegate ()
                {
                    labelThreadTest.Text = i.ToString();
                }));
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            threadTest.Abort();
        }
    }
}
