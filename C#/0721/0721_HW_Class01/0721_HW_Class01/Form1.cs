using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0721_HW_Class01
{
    public partial class Form1 : Form
    {

        List<Model.Fan_v1> v1s;
        List<Model.Fan_v2> v2s;

        
        Dictionary<DateTime, Model.Fan_v1> v1start = new Dictionary<DateTime, Model.Fan_v1>();
        Dictionary<DateTime, Model.Fan_v1> v1end = new Dictionary<DateTime, Model.Fan_v1>();

        Dictionary<DateTime, Model.Fan_v2> v2start = new Dictionary<DateTime, Model.Fan_v2>();
        Dictionary<DateTime, Model.Fan_v2> v2end = new Dictionary<DateTime, Model.Fan_v2>();

        List<int> testDone = new List<int>();

        int v1num = 0;
        int v2num = 0;

        int producing = 0;

        int testing = 0;

        public Form1()
        {
            InitializeComponent();

            v1s = new List<Model.Fan_v1>();
            v2s = new List<Model.Fan_v2>();

            dataGridView1.ColumnCount = 6;
            dataGridView1.Columns[0].HeaderText = "ModelName";
            dataGridView1.Columns[1].HeaderText = "Wings";
            dataGridView1.Columns[2].HeaderText = "Power";
            dataGridView1.Columns[3].HeaderText = "Color";
            dataGridView1.Columns[4].HeaderText = "Remote";
            dataGridView1.Columns[5].HeaderText = "Time";

            dataGridView2.ColumnCount = 3;
            dataGridView2.Columns[0].HeaderText = "ModelName";
            dataGridView2.Columns[1].HeaderText = "Done";
            dataGridView2.Columns[2].HeaderText = "Time";
        }

        private void OrderConfirm(object sender, EventArgs e)
        {
            int v2R = int.Parse(textBox2R.Text);
            int v3W = int.Parse(textBox3W.Text);
            int v4B = int.Parse(textBox4B.Text);
            int v5R = int.Parse(textBox5R.Text);

            for(int i = 0; i < v2R; i++)
            {
                SetFanV1(label3002R.Text);
            }
            for (int i = 0; i < v3W; i++)
            {
                SetFanV1(label4003W.Text);
            }
            for (int i = 0; i < v4B; i++)
            {
                SetFanV2(label4004B0.Text);
            }
            for (int i = 0; i < v5R; i++)
            {
                SetFanV2(label4005R1.Text);
            }
            
            timerProduce.Enabled = true;
        }

        private void TimerProduceInterrupt(object sender, EventArgs e)
        {

            if (v1start.Count < v1s.Count)
            {
                v1start.Add(DateTime.Now, v1s[producing]);
                
                
                string[] row = new string[6];
                row[0] = v1s[producing].name;
                row[1] = v1s[producing].wing.count.ToString();
                row[2] = v1s[producing].windPower.step.ToString();
                row[3] = v1s[producing].colorSelection;
                row[4] = "LowerVersion";
                row[5] = DateTime.Now.ToString();
                dataGridView1.Rows.Add(row);

                if (producing == 0)
                {
                    testDone.Add(0);
                    timerTest.Enabled = true;
                }

                producing++;

                

                if (producing == v1s.Count)
                {
                    producing = 0;
                }
            }
            else
            {
                v2start.Add(DateTime.Now, v2s[producing]);

                string[] row = new string[6];
                row[0] = v2s[producing].name;
                row[1] = v2s[producing].wing.count.ToString();
                row[2] = v2s[producing].windPower.step.ToString();
                row[3] = v2s[producing].colorSelection;
                row[4] = v2s[producing].remote;
                row[5] = DateTime.Now.ToString();
                dataGridView1.Rows.Add(row);

                producing++;

                if(producing == v2s.Count)
                {
                    timerProduce.Enabled = false;
                }
            }
        }

        Model.ActivateTimer timer;
        private void TimerTestInterrupt(object sender, EventArgs e)
        {
            if (testing >= (v1s.Count + v2s.Count))
            {
                timerTest.Enabled = false;
                return;
            }
            if (testDone[testing] == 1)
            {// 테스트 진행 중
                int threading = timer.GetTimer();
                if(threading == 0)
                {
                    timer.timerOff();
                    dataGridView2.Rows[testing].Cells[1].Value = "TestDone";
                    dataGridView2.Rows[testing].Cells[2].Value = DateTime.Now.ToString();
                    testing++;
                    testDone.Add(0);
                }
            }
            else
            {// 테스트 시작
                if(testing < v1s.Count)
                {
                    timer = new Model.ActivateTimer();
                    timer.SetTimer(v1s[testing].windPower.step);
                    timer.timerOn();
                    // 쓰레드 시작

                    testDone[testing] = 1;

                    string[] row = new string[3];
                    row[0] = v1s[testing].name;
                    row[1] = "Testing";
                    row[2] = "";
                    dataGridView2.Rows.Add(row);
                }
                else
                {
                    timer = new Model.ActivateTimer();
                    timer.SetTimer(v2s[testing - v1s.Count].windPower.step);
                    timer.timerOn();
                    // 쓰레드 시작

                    testDone[testing] = 1;

                    string[] row = new string[3];
                    row[0] = v2s[testing - v1s.Count].name;
                    row[1] = "Testing";
                    row[2] = "";
                    dataGridView2.Rows.Add(row);
                }
            }
        }


        private void SetFanV1(string order)
        {
            Model.Fan_v1 fan_V1 = new Model.Fan_v1();

            fan_V1.name = order;

            char[] infos = order.ToCharArray();

            fan_V1.wing = new Model.Wing();
            fan_V1.wing.count = uint.Parse(infos[0].ToString());

            fan_V1.windPower = new Model.WindPower();
            fan_V1.windPower.step = int.Parse(infos[1].ToString());

            if (infos[2] == 'R')
            {
                fan_V1.colorSelection = Model.DesignColorSelection.Red;
            }
            else if (infos[2] == 'B')
            {
                fan_V1.colorSelection = Model.DesignColorSelection.BLACK;
            }
            else if (infos[2] == 'W')
            {
                fan_V1.colorSelection = Model.DesignColorSelection.White;
            }


            v1s.Add(fan_V1);
        }

        private void SetFanV2(string order)
        {
            
            Model.Fan_v2 fan = new Model.Fan_v2();

            fan.name = order;

            char[] infos = order.ToCharArray();

            fan.wing = new Model.Wing();
            fan.wing.count = uint.Parse(infos[0].ToString());

            fan.windPower = new Model.WindPower();
            int testingPeriod = int.Parse(infos[1].ToString()) + 5;
            fan.windPower.step = testingPeriod;

            if (infos[2] == 'R')
            {
                fan.colorSelection = Model.DesignColorSelection.Red;
            }
            else if (infos[2] == 'B')
            {
                fan.colorSelection = Model.DesignColorSelection.BLACK;
            }
            else if (infos[2] == 'W')
            {
                fan.colorSelection = Model.DesignColorSelection.White;
            }

            if(infos[3] == '0')
            {
                fan.remote = Model.Remote.Wifi;
            }
            else
            {
                fan.remote = Model.Remote.BlueTooth;
            }

            fan.connectTimer = new Model.ConnectTimer();

            v2s.Add(fan);
        }
    }
}
