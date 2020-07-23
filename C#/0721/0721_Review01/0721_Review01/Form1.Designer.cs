namespace _0721_Review01
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxWingCount = new System.Windows.Forms.TextBox();
            this.comboBoxMotorSelect = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.checkBoxVertical = new System.Windows.Forms.CheckBox();
            this.checkBoxHorizental = new System.Windows.Forms.CheckBox();
            this.comboBoxPowerSelect = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.buttonSet = new System.Windows.Forms.Button();
            this.buttonShowSpec = new System.Windows.Forms.Button();
            this.buttonPower = new System.Windows.Forms.Button();
            this.buttonSetColor = new System.Windows.Forms.Button();
            this.buttonPUp = new System.Windows.Forms.Button();
            this.buttonPDown = new System.Windows.Forms.Button();
            this.buttonTest = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.textBoxTimerValue = new System.Windows.Forms.TextBox();
            this.buttonTimerSet = new System.Windows.Forms.Button();
            this.labelTimerCheck = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.comboBoxPowerV2 = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.checkBoxVertiV2 = new System.Windows.Forms.CheckBox();
            this.checkBoxHoriV2 = new System.Windows.Forms.CheckBox();
            this.comboBoxMotorV2 = new System.Windows.Forms.ComboBox();
            this.textBoxWingsV2 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(39, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "Wings";
            // 
            // textBoxWingCount
            // 
            this.textBoxWingCount.Location = new System.Drawing.Point(56, 6);
            this.textBoxWingCount.Name = "textBoxWingCount";
            this.textBoxWingCount.Size = new System.Drawing.Size(121, 21);
            this.textBoxWingCount.TabIndex = 1;
            // 
            // comboBoxMotorSelect
            // 
            this.comboBoxMotorSelect.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxMotorSelect.FormattingEnabled = true;
            this.comboBoxMotorSelect.Items.AddRange(new object[] {
            "AC",
            "DC"});
            this.comboBoxMotorSelect.Location = new System.Drawing.Point(56, 56);
            this.comboBoxMotorSelect.Name = "comboBoxMotorSelect";
            this.comboBoxMotorSelect.Size = new System.Drawing.Size(121, 20);
            this.comboBoxMotorSelect.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 59);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 12);
            this.label2.TabIndex = 0;
            this.label2.Text = "Motor";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.checkBoxVertical);
            this.groupBox1.Controls.Add(this.checkBoxHorizental);
            this.groupBox1.Location = new System.Drawing.Point(56, 95);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(147, 71);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "groupBox1";
            // 
            // checkBoxVertical
            // 
            this.checkBoxVertical.AutoSize = true;
            this.checkBoxVertical.Location = new System.Drawing.Point(6, 39);
            this.checkBoxVertical.Name = "checkBoxVertical";
            this.checkBoxVertical.Size = new System.Drawing.Size(66, 16);
            this.checkBoxVertical.TabIndex = 1;
            this.checkBoxVertical.Text = "Vertical";
            this.checkBoxVertical.UseVisualStyleBackColor = true;
            // 
            // checkBoxHorizental
            // 
            this.checkBoxHorizental.AutoSize = true;
            this.checkBoxHorizental.Location = new System.Drawing.Point(6, 17);
            this.checkBoxHorizental.Name = "checkBoxHorizental";
            this.checkBoxHorizental.Size = new System.Drawing.Size(80, 16);
            this.checkBoxHorizental.TabIndex = 0;
            this.checkBoxHorizental.Text = "Horizental";
            this.checkBoxHorizental.UseVisualStyleBackColor = true;
            // 
            // comboBoxPowerSelect
            // 
            this.comboBoxPowerSelect.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxPowerSelect.FormattingEnabled = true;
            this.comboBoxPowerSelect.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7"});
            this.comboBoxPowerSelect.Location = new System.Drawing.Point(56, 181);
            this.comboBoxPowerSelect.Name = "comboBoxPowerSelect";
            this.comboBoxPowerSelect.Size = new System.Drawing.Size(121, 20);
            this.comboBoxPowerSelect.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(11, 112);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 12);
            this.label3.TabIndex = 4;
            this.label3.Text = "Activate";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(11, 181);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 12);
            this.label4.TabIndex = 5;
            this.label4.Text = "Power";
            // 
            // buttonSet
            // 
            this.buttonSet.Location = new System.Drawing.Point(12, 207);
            this.buttonSet.Name = "buttonSet";
            this.buttonSet.Size = new System.Drawing.Size(75, 23);
            this.buttonSet.TabIndex = 6;
            this.buttonSet.Text = "Set";
            this.buttonSet.UseVisualStyleBackColor = true;
            this.buttonSet.Click += new System.EventHandler(this.SetFan);
            // 
            // buttonShowSpec
            // 
            this.buttonShowSpec.Location = new System.Drawing.Point(93, 207);
            this.buttonShowSpec.Name = "buttonShowSpec";
            this.buttonShowSpec.Size = new System.Drawing.Size(75, 23);
            this.buttonShowSpec.TabIndex = 2;
            this.buttonShowSpec.Text = "Infos";
            this.buttonShowSpec.UseVisualStyleBackColor = true;
            this.buttonShowSpec.Click += new System.EventHandler(this.CreateFan);
            // 
            // buttonPower
            // 
            this.buttonPower.Location = new System.Drawing.Point(13, 239);
            this.buttonPower.Name = "buttonPower";
            this.buttonPower.Size = new System.Drawing.Size(75, 23);
            this.buttonPower.TabIndex = 7;
            this.buttonPower.Text = "SetPower";
            this.buttonPower.UseVisualStyleBackColor = true;
            this.buttonPower.Click += new System.EventHandler(this.PowerSetFan);
            // 
            // buttonSetColor
            // 
            this.buttonSetColor.Location = new System.Drawing.Point(93, 239);
            this.buttonSetColor.Name = "buttonSetColor";
            this.buttonSetColor.Size = new System.Drawing.Size(75, 23);
            this.buttonSetColor.TabIndex = 8;
            this.buttonSetColor.Text = "SetColor";
            this.buttonSetColor.UseVisualStyleBackColor = true;
            this.buttonSetColor.Click += new System.EventHandler(this.ColorSetFan);
            // 
            // buttonPUp
            // 
            this.buttonPUp.Location = new System.Drawing.Point(12, 268);
            this.buttonPUp.Name = "buttonPUp";
            this.buttonPUp.Size = new System.Drawing.Size(75, 23);
            this.buttonPUp.TabIndex = 9;
            this.buttonPUp.Text = "PowerUp";
            this.buttonPUp.UseVisualStyleBackColor = true;
            this.buttonPUp.Click += new System.EventHandler(this.FanPowerUp);
            // 
            // buttonPDown
            // 
            this.buttonPDown.Location = new System.Drawing.Point(93, 268);
            this.buttonPDown.Name = "buttonPDown";
            this.buttonPDown.Size = new System.Drawing.Size(75, 23);
            this.buttonPDown.TabIndex = 9;
            this.buttonPDown.Text = "PowerDown";
            this.buttonPDown.UseVisualStyleBackColor = true;
            this.buttonPDown.Click += new System.EventHandler(this.FanPowerDown);
            // 
            // buttonTest
            // 
            this.buttonTest.Location = new System.Drawing.Point(174, 268);
            this.buttonTest.Name = "buttonTest";
            this.buttonTest.Size = new System.Drawing.Size(75, 23);
            this.buttonTest.TabIndex = 10;
            this.buttonTest.Text = "TestCheck";
            this.buttonTest.UseVisualStyleBackColor = true;
            this.buttonTest.Click += new System.EventHandler(this.FansTest);
            // 
            // timer1
            // 
            this.timer1.Interval = 500;
            this.timer1.Tick += new System.EventHandler(this.timerInterrupt01);
            // 
            // textBoxTimerValue
            // 
            this.textBoxTimerValue.Location = new System.Drawing.Point(222, 6);
            this.textBoxTimerValue.Name = "textBoxTimerValue";
            this.textBoxTimerValue.Size = new System.Drawing.Size(100, 21);
            this.textBoxTimerValue.TabIndex = 11;
            // 
            // buttonTimerSet
            // 
            this.buttonTimerSet.Location = new System.Drawing.Point(328, 6);
            this.buttonTimerSet.Name = "buttonTimerSet";
            this.buttonTimerSet.Size = new System.Drawing.Size(75, 23);
            this.buttonTimerSet.TabIndex = 12;
            this.buttonTimerSet.Text = "TimerSet";
            this.buttonTimerSet.UseVisualStyleBackColor = true;
            this.buttonTimerSet.Click += new System.EventHandler(this.timerStart);
            // 
            // labelTimerCheck
            // 
            this.labelTimerCheck.AutoSize = true;
            this.labelTimerCheck.Location = new System.Drawing.Point(470, 9);
            this.labelTimerCheck.Name = "labelTimerCheck";
            this.labelTimerCheck.Size = new System.Drawing.Size(28, 12);
            this.labelTimerCheck.TabIndex = 13;
            this.labelTimerCheck.Text = "Wait";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(388, 32);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(39, 12);
            this.label5.TabIndex = 0;
            this.label5.Text = "Wings";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(388, 82);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(37, 12);
            this.label6.TabIndex = 0;
            this.label6.Text = "Motor";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(387, 135);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(49, 12);
            this.label7.TabIndex = 4;
            this.label7.Text = "Activate";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(387, 204);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 12);
            this.label8.TabIndex = 5;
            this.label8.Text = "Power";
            // 
            // comboBoxPowerV2
            // 
            this.comboBoxPowerV2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxPowerV2.FormattingEnabled = true;
            this.comboBoxPowerV2.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7"});
            this.comboBoxPowerV2.Location = new System.Drawing.Point(442, 199);
            this.comboBoxPowerV2.Name = "comboBoxPowerV2";
            this.comboBoxPowerV2.Size = new System.Drawing.Size(121, 20);
            this.comboBoxPowerV2.TabIndex = 2;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.checkBoxVertiV2);
            this.groupBox2.Controls.Add(this.checkBoxHoriV2);
            this.groupBox2.Location = new System.Drawing.Point(442, 122);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(147, 71);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "groupBox1";
            // 
            // checkBoxVertiV2
            // 
            this.checkBoxVertiV2.AutoSize = true;
            this.checkBoxVertiV2.Location = new System.Drawing.Point(6, 39);
            this.checkBoxVertiV2.Name = "checkBoxVertiV2";
            this.checkBoxVertiV2.Size = new System.Drawing.Size(66, 16);
            this.checkBoxVertiV2.TabIndex = 1;
            this.checkBoxVertiV2.Text = "Vertical";
            this.checkBoxVertiV2.UseVisualStyleBackColor = true;
            // 
            // checkBoxHoriV2
            // 
            this.checkBoxHoriV2.AutoSize = true;
            this.checkBoxHoriV2.Location = new System.Drawing.Point(6, 17);
            this.checkBoxHoriV2.Name = "checkBoxHoriV2";
            this.checkBoxHoriV2.Size = new System.Drawing.Size(80, 16);
            this.checkBoxHoriV2.TabIndex = 0;
            this.checkBoxHoriV2.Text = "Horizental";
            this.checkBoxHoriV2.UseVisualStyleBackColor = true;
            // 
            // comboBoxMotorV2
            // 
            this.comboBoxMotorV2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxMotorV2.FormattingEnabled = true;
            this.comboBoxMotorV2.Items.AddRange(new object[] {
            "AC",
            "DC"});
            this.comboBoxMotorV2.Location = new System.Drawing.Point(442, 79);
            this.comboBoxMotorV2.Name = "comboBoxMotorV2";
            this.comboBoxMotorV2.Size = new System.Drawing.Size(121, 20);
            this.comboBoxMotorV2.TabIndex = 2;
            // 
            // textBoxWingsV2
            // 
            this.textBoxWingsV2.Location = new System.Drawing.Point(442, 33);
            this.textBoxWingsV2.Name = "textBoxWingsV2";
            this.textBoxWingsV2.Size = new System.Drawing.Size(121, 21);
            this.textBoxWingsV2.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(389, 239);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 6;
            this.button1.Text = "Set";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.SetFanV2);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(553, 239);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 10;
            this.button3.Text = "TestCheck";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.FansTest);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(472, 239);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 2;
            this.button2.Text = "Infos";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.showinfoV2);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(749, 303);
            this.Controls.Add(this.labelTimerCheck);
            this.Controls.Add(this.buttonTimerSet);
            this.Controls.Add(this.textBoxTimerValue);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.buttonTest);
            this.Controls.Add(this.buttonPDown);
            this.Controls.Add(this.buttonPUp);
            this.Controls.Add(this.buttonSetColor);
            this.Controls.Add(this.buttonPower);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.buttonShowSpec);
            this.Controls.Add(this.buttonSet);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.comboBoxPowerV2);
            this.Controls.Add(this.comboBoxPowerSelect);
            this.Controls.Add(this.comboBoxMotorV2);
            this.Controls.Add(this.comboBoxMotorSelect);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBoxWingsV2);
            this.Controls.Add(this.textBoxWingCount);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxWingCount;
        private System.Windows.Forms.ComboBox comboBoxMotorSelect;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox checkBoxVertical;
        private System.Windows.Forms.CheckBox checkBoxHorizental;
        private System.Windows.Forms.ComboBox comboBoxPowerSelect;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button buttonSet;
        private System.Windows.Forms.Button buttonShowSpec;
        private System.Windows.Forms.Button buttonPower;
        private System.Windows.Forms.Button buttonSetColor;
        private System.Windows.Forms.Button buttonPUp;
        private System.Windows.Forms.Button buttonPDown;
        private System.Windows.Forms.Button buttonTest;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TextBox textBoxTimerValue;
        private System.Windows.Forms.Button buttonTimerSet;
        private System.Windows.Forms.Label labelTimerCheck;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox comboBoxPowerV2;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox checkBoxVertiV2;
        private System.Windows.Forms.CheckBox checkBoxHoriV2;
        private System.Windows.Forms.ComboBox comboBoxMotorV2;
        private System.Windows.Forms.TextBox textBoxWingsV2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
    }
}

