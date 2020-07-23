using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0721_Review01
{
    public partial class Form1 : Form
    {
        Model.Fan_v1 fan_V1;

        List<Model.Fan_v1> fans;
        public Form1()
        {
            InitializeComponent();
            fans = new List<Model.Fan_v1>();
        }

        private void SetFan(object sender, EventArgs e)
        {
            fan_V1 = new Model.Fan_v1();

            fan_V1.wing = new Model.Wing();
            fan_V1.wing.count = Convert.ToUInt32(textBoxWingCount.Text);

            fan_V1.motor = new Model.Motor();
            fan_V1.motor.motorTypeByNum = comboBoxMotorSelect.SelectedIndex;

            fan_V1.roateFunction = new Model.RoateFunction();
            int rotateFuntionNum = 0;
            if (checkBoxHorizental.Checked)
            {
                rotateFuntionNum += (1 << 1);
            }
            if (checkBoxVertical.Checked)
            {
                rotateFuntionNum += (1 << 0);
            }
            fan_V1.roateFunction.rotation_Enable = rotateFuntionNum;

            fan_V1.windPower = new Model.WindPower();
            fan_V1.windPower.step = (ushort)(comboBoxPowerSelect.SelectedIndex + 1);

            fans.Add(fan_V1);
        }

        private void CreateFan(object sender, EventArgs e)
        {
            showInfo(fan_V1);
        }

        private void PowerSetFan(object sender, EventArgs e)
        {
            fan_V1.supplySelection = Model.PowerSupplySelection.AC230;
        }

        private void ColorSetFan(object sender, EventArgs e)
        {
            fan_V1.colorSelection = Model.DesignColorSelection.Red;
        }

        private void FanPowerUp(object sender, EventArgs e)
        {
            if (fan_V1.windPower.PowerUp())
            {
                MessageBox.Show("Current Wind Power : " + fan_V1.windPower.getCurrentState());
            }
            else
            {
                MessageBox.Show("Wind Power Up to Limited");
            }
            
        }

        private void FanPowerDown(object sender, EventArgs e)
        {
            if (fan_V1.windPower.PowerDown())
            {
                MessageBox.Show("Current Wind Power : " + fan_V1.windPower.getCurrentState());
            }
            else
            {
                MessageBox.Show("Wind Power Down to Limited");
            }
        }

        private void FanHorizentalOn(object sender, EventArgs e)
        {
            fan_V1.roateFunction.setHorizental(true);
        }
        private void FanHorizentalOff(object sender, EventArgs e)
        {
            fan_V1.roateFunction.setHorizental(false);
        }

        private void FanVerticalOn(object sender, EventArgs e)
        {
            fan_V1.roateFunction.setVertical(true);
        }
        private void FanVerticalOff(object sender, EventArgs e)
        {
            fan_V1.roateFunction.setVertical(false);
        }

        private void FansTest(object sender, EventArgs e)
        {
            for(int i = 0; i < fans.Count; i++)
            {
                showInfo(fans[i]);
                fans[i].supplySelection = Model.PowerSupplySelection.AC230;
                fans[i].colorSelection = Model.DesignColorSelection.Red;
                while (fans[i].windPower.PowerUp())
                {
                    MessageBox.Show("Current Wind Power : " + fans[i].windPower.getCurrentState());
                }
                while (fans[i].windPower.PowerDown())
                {
                    MessageBox.Show("Current Wind Power : " + fans[i].windPower.getCurrentState());
                }

                for (int j = 0; j <= 1; j++)
                {
                    if(( (1<<j) & fans[i].roateFunction.rotation_Enable) != 0)
                    {
                        if(j == 0)
                        {
                            MessageBox.Show("Vertical Enable");
                        }
                        else
                        {
                            MessageBox.Show("Horizental Enable");
                        }
                    }
                }
            }
        }


        Model.ActivateTimer timer;
        private void timerStart(object seneder, EventArgs e)
        {
            timer = new Model.ActivateTimer();

            timer.TimerUnit = 10;
            timer.setTimerRange(10, 100);
            timer.SetTimer(uint.Parse(textBoxTimerValue.Text));
            timer.timerOn();
            timer1.Enabled = true;
        }

        private void timerInterrupt01(object sender, EventArgs e)
        {
            if (timer1 == null)
            {
                timer1.Enabled = false;
                return;
            }

            uint timerValue = timer.GetTimer();
            labelTimerCheck.Text = timerValue.ToString();

            if(timerValue == 0)
            {
                timer.timerOff();
            }

        }

        Model.Fan_v2 fan_V2;

        private void SetFanV2(object sender, EventArgs e)
        {
            fan_V2 = new Model.Fan_v2();

            fan_V2.wing = new Model.Wing();
            fan_V2.wing.count = Convert.ToUInt32(textBoxWingsV2.Text);

            fan_V2.motor = new Model.Motor();
            fan_V2.motor.motorTypeByNum = comboBoxMotorV2.SelectedIndex;

            fan_V2.roateFunction = new Model.RoateFunction();
            int rotateFuntionNum = 0;
            if (checkBoxHoriV2.Checked)
            {
                rotateFuntionNum += (1 << 1);
            }
            if (checkBoxVertiV2.Checked)
            {
                rotateFuntionNum += (1 << 0);
            }
            fan_V2.roateFunction.rotation_Enable = rotateFuntionNum;

            fan_V2.windPower = new Model.WindPower();
            fan_V2.windPower.step = (ushort)(comboBoxPowerV2.SelectedIndex + 1);

            fan_V2.timer = new Model.ActivateTimer();
            fan_V2.timer.TimerUnit = 10;
            fan_V2.timer.setTimerRange(10, 100);

            fan_V2.supplySelection = Model.PowerSupplySelection.DC;
            fan_V2.colorSelection = Model.DesignColorSelection.BLACK;

        }

        private void showinfoV2(object sender, EventArgs e)
        {
            if (fan_V2 == null)
            {
                MessageBox.Show("Nothing to Make");
            }
            else
            {
                string spec = "";
                spec += "Wing Counts : " + fan_V2.wing.count.ToString() + "\n";
                spec += "Motor : " + fan_V2.motor.motorTypeByString + "\n";
                spec += "Activate : ";
                if ((fan_V2.roateFunction.rotation_Enable & 0x02) != 0)
                {
                    spec += " Horizental ";
                }
                if ((fan_V2.roateFunction.rotation_Enable & 0x01) != 0)
                {
                    spec += " Vertical ";
                }
                spec += "\n";

                spec += "Wind Power : " + fan_V2.windPower.step + "\n";
                spec += "Timer Unit : " + fan_V2.timer.TimerUnit + "\n";

                MessageBox.Show(spec);
            }
        }

        private void FanV2_Test(object o, EventArgs e)
        {
            while (fan_V2.windPower.PowerUp())
            {
                MessageBox.Show("Current Wind Power : " + fan_V2.windPower.getCurrentState());
            }
            while (fan_V2.windPower.PowerDown())
            {
                MessageBox.Show("Current Wind Power : " + fan_V2.windPower.getCurrentState());
            }
        }

        private void showInfo(Model.Fan_v1 target)
        {
            if (target == null)
            {
                MessageBox.Show("Nothing to Make");
            }
            else
            {
                string spec = "";
                spec += "Wing Counts : " + target.wing.count.ToString() + "\n";
                spec += "Motor : " + target.motor.motorTypeByString + "\n";
                spec += "Activate : ";
                if ((target.roateFunction.rotation_Enable & 0x02) != 0)
                {
                    spec += " Horizental ";
                }
                if ((target.roateFunction.rotation_Enable & 0x01) != 0)
                {
                    spec += " Vertical ";
                }
                spec += "\n";

                spec += "Wind Power : " + target.windPower.step + "\n";
                MessageBox.Show(spec);
            }
        }

        
        
    }
}
