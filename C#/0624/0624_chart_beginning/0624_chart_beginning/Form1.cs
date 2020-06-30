using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0624_chart_beginning
{
    public partial class Form1 : Form
    {

        int chartMaxPoint = 30;

        Random random;
        public Form1()
        {
            InitializeComponent();
            random = new Random();
        }

        private void VoltageHigh(object sender, EventArgs e)
        {
            ChartMove01();
            chartVoltage.Series[0].Points.AddXY(DateTime.Now.ToString(), 1);
            // 차트 입력. 
            // X의 값이 DateTime을 하는 이유는 순서대로 넣기 위해서 이다.
            // Y는 HIGH이기 때문에 1의 값을 주는 것이다.
            chartVoltage.ChartAreas[0].RecalculateAxesScale();
            // 순서대로 입력된 것들을 재배열하는 것이다.
        }

        private void VoltageLow(object sender, EventArgs e)
        {
            ChartMove01();
            chartVoltage.Series[0].Points.AddXY(DateTime.Now.ToString(), 0);
            // X의 값이 DateTime을 하는 이유는 순서대로 넣기 위해서 이다.
            // Y는 LOW이기 때문에 0의 값을 주는 것이다.
            chartVoltage.ChartAreas[0].RecalculateAxesScale();
            // 순서대로 입력된 것들을 재배열하는 것이다.
        }

        private void RandomStart(object sender, EventArgs e)
        {
            timerInterrupt.Enabled = true;
        }

        private void RandomStop(object sender, EventArgs e)
        {
            timerInterrupt.Enabled = false;
        }

        private void RandomChart(object sender, EventArgs e)
        {
            double value = random.NextDouble() * 9 + 1; // 1 ~ 10
            ChartMove01();
            chartVoltage.Series[0].Points.AddXY(DateTime.Now.ToString(), value);
            
            value = random.NextDouble() * 9 + 1;
            ChartMove02();
            chartVoltage.Series[1].Points.AddXY(DateTime.Now.ToString(), value);            


            chartVoltage.ChartAreas[0].RecalculateAxesScale();
        }

        private void ChartMove01()
        {
            if(chartVoltage.Series[0].Points.Count > chartMaxPoint)
            {
                chartVoltage.Series[0].Points.RemoveAt(0);
            }
        }
        private void ChartMove02()
        {
            if (chartVoltage.Series[1].Points.Count > chartMaxPoint)
            {
                chartVoltage.Series[1].Points.RemoveAt(0);
            }
        }
    }
}
