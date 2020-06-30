namespace _0623_HW01
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
            this.buttonOpen = new System.Windows.Forms.Button();
            this.buttonClose = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.pictureBoxLed01 = new System.Windows.Forms.PictureBox();
            this.pictureBoxLed02 = new System.Windows.Forms.PictureBox();
            this.pictureBoxLed03 = new System.Windows.Forms.PictureBox();
            this.pictureBoxLed04 = new System.Windows.Forms.PictureBox();
            this.pictureBoxLed05 = new System.Windows.Forms.PictureBox();
            this.pictureBoxLed06 = new System.Windows.Forms.PictureBox();
            this.pictureBoxLed07 = new System.Windows.Forms.PictureBox();
            this.pictureBoxLed08 = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.timerInterrupt = new System.Windows.Forms.Timer(this.components);
            this.textBoxDataReceive = new System.Windows.Forms.TextBox();
            this.textBoxDataSend = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed01)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed02)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed03)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed04)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed05)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed06)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed07)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed08)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonOpen
            // 
            this.buttonOpen.Location = new System.Drawing.Point(12, 12);
            this.buttonOpen.Name = "buttonOpen";
            this.buttonOpen.Size = new System.Drawing.Size(75, 23);
            this.buttonOpen.TabIndex = 0;
            this.buttonOpen.Text = "Open";
            this.buttonOpen.UseVisualStyleBackColor = true;
            this.buttonOpen.Click += new System.EventHandler(this.UART_Open);
            // 
            // buttonClose
            // 
            this.buttonClose.Location = new System.Drawing.Point(93, 12);
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(75, 23);
            this.buttonClose.TabIndex = 1;
            this.buttonClose.Text = "Close";
            this.buttonClose.UseVisualStyleBackColor = true;
            this.buttonClose.Click += new System.EventHandler(this.UART_Close);
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.UART_Receive);
            // 
            // pictureBoxLed01
            // 
            this.pictureBoxLed01.Location = new System.Drawing.Point(12, 142);
            this.pictureBoxLed01.Name = "pictureBoxLed01";
            this.pictureBoxLed01.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed01.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed01.TabIndex = 2;
            this.pictureBoxLed01.TabStop = false;
            // 
            // pictureBoxLed02
            // 
            this.pictureBoxLed02.Location = new System.Drawing.Point(93, 142);
            this.pictureBoxLed02.Name = "pictureBoxLed02";
            this.pictureBoxLed02.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed02.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed02.TabIndex = 3;
            this.pictureBoxLed02.TabStop = false;
            // 
            // pictureBoxLed03
            // 
            this.pictureBoxLed03.Location = new System.Drawing.Point(174, 142);
            this.pictureBoxLed03.Name = "pictureBoxLed03";
            this.pictureBoxLed03.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed03.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed03.TabIndex = 4;
            this.pictureBoxLed03.TabStop = false;
            // 
            // pictureBoxLed04
            // 
            this.pictureBoxLed04.Location = new System.Drawing.Point(255, 142);
            this.pictureBoxLed04.Name = "pictureBoxLed04";
            this.pictureBoxLed04.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed04.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed04.TabIndex = 5;
            this.pictureBoxLed04.TabStop = false;
            // 
            // pictureBoxLed05
            // 
            this.pictureBoxLed05.Location = new System.Drawing.Point(12, 298);
            this.pictureBoxLed05.Name = "pictureBoxLed05";
            this.pictureBoxLed05.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed05.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed05.TabIndex = 6;
            this.pictureBoxLed05.TabStop = false;
            // 
            // pictureBoxLed06
            // 
            this.pictureBoxLed06.Location = new System.Drawing.Point(93, 298);
            this.pictureBoxLed06.Name = "pictureBoxLed06";
            this.pictureBoxLed06.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed06.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed06.TabIndex = 7;
            this.pictureBoxLed06.TabStop = false;
            // 
            // pictureBoxLed07
            // 
            this.pictureBoxLed07.Location = new System.Drawing.Point(174, 298);
            this.pictureBoxLed07.Name = "pictureBoxLed07";
            this.pictureBoxLed07.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed07.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed07.TabIndex = 8;
            this.pictureBoxLed07.TabStop = false;
            // 
            // pictureBoxLed08
            // 
            this.pictureBoxLed08.Location = new System.Drawing.Point(255, 298);
            this.pictureBoxLed08.Name = "pictureBoxLed08";
            this.pictureBoxLed08.Size = new System.Drawing.Size(75, 73);
            this.pictureBoxLed08.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxLed08.TabIndex = 9;
            this.pictureBoxLed08.TabStop = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 113);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 10;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(93, 113);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 11;
            this.button2.Text = "button2";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.Button_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(174, 113);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 12;
            this.button3.Text = "button3";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.Button_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(255, 113);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 23);
            this.button4.TabIndex = 13;
            this.button4.Text = "button4";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.Button_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(12, 269);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 23);
            this.button5.TabIndex = 14;
            this.button5.Text = "button5";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.Button_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(93, 269);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(75, 23);
            this.button6.TabIndex = 15;
            this.button6.Text = "button6";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.Button_Click);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(174, 269);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(75, 23);
            this.button7.TabIndex = 16;
            this.button7.Text = "button7";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.Button_Click);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(255, 269);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(75, 23);
            this.button8.TabIndex = 17;
            this.button8.Text = "button8";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.Button_Click);
            // 
            // timerInterrupt
            // 
            this.timerInterrupt.Tick += new System.EventHandler(this.SettingPictures);
            // 
            // textBoxDataReceive
            // 
            this.textBoxDataReceive.Location = new System.Drawing.Point(12, 86);
            this.textBoxDataReceive.Name = "textBoxDataReceive";
            this.textBoxDataReceive.Size = new System.Drawing.Size(100, 21);
            this.textBoxDataReceive.TabIndex = 18;
            // 
            // textBoxDataSend
            // 
            this.textBoxDataSend.Location = new System.Drawing.Point(230, 86);
            this.textBoxDataSend.Name = "textBoxDataSend";
            this.textBoxDataSend.Size = new System.Drawing.Size(100, 21);
            this.textBoxDataSend.TabIndex = 19;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(588, 383);
            this.Controls.Add(this.textBoxDataSend);
            this.Controls.Add(this.textBoxDataReceive);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pictureBoxLed08);
            this.Controls.Add(this.pictureBoxLed07);
            this.Controls.Add(this.pictureBoxLed06);
            this.Controls.Add(this.pictureBoxLed05);
            this.Controls.Add(this.pictureBoxLed04);
            this.Controls.Add(this.pictureBoxLed03);
            this.Controls.Add(this.pictureBoxLed02);
            this.Controls.Add(this.pictureBoxLed01);
            this.Controls.Add(this.buttonClose);
            this.Controls.Add(this.buttonOpen);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed01)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed02)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed03)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed04)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed05)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed06)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed07)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxLed08)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonOpen;
        private System.Windows.Forms.Button buttonClose;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.PictureBox pictureBoxLed01;
        private System.Windows.Forms.PictureBox pictureBoxLed02;
        private System.Windows.Forms.PictureBox pictureBoxLed03;
        private System.Windows.Forms.PictureBox pictureBoxLed04;
        private System.Windows.Forms.PictureBox pictureBoxLed05;
        private System.Windows.Forms.PictureBox pictureBoxLed06;
        private System.Windows.Forms.PictureBox pictureBoxLed07;
        private System.Windows.Forms.PictureBox pictureBoxLed08;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Timer timerInterrupt;
        private System.Windows.Forms.TextBox textBoxDataReceive;
        private System.Windows.Forms.TextBox textBoxDataSend;
    }
}

