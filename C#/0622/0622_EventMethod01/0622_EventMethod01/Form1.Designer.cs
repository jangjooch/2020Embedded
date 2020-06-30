namespace _0622_EventMethod01
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
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.timerInterrupt = new System.Windows.Forms.Timer(this.components);
            this.labelTime = new System.Windows.Forms.Label();
            this.buttonThreadStart = new System.Windows.Forms.Button();
            this.labelThreadTest = new System.Windows.Forms.Label();
            this.buttonThreadEnd = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "TimerStart";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(93, 12);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "TimerStop";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.Button_Click);
            // 
            // timerInterrupt
            // 
            this.timerInterrupt.Interval = 1000;
            this.timerInterrupt.Tick += new System.EventHandler(this.timerInterrupt_Tick);
            // 
            // labelTime
            // 
            this.labelTime.AutoSize = true;
            this.labelTime.Location = new System.Drawing.Point(174, 17);
            this.labelTime.Name = "labelTime";
            this.labelTime.Size = new System.Drawing.Size(79, 12);
            this.labelTime.TabIndex = 2;
            this.labelTime.Text = "Current Time";
            // 
            // buttonThreadStart
            // 
            this.buttonThreadStart.Location = new System.Drawing.Point(12, 41);
            this.buttonThreadStart.Name = "buttonThreadStart";
            this.buttonThreadStart.Size = new System.Drawing.Size(75, 23);
            this.buttonThreadStart.TabIndex = 3;
            this.buttonThreadStart.Text = "ThreadStart";
            this.buttonThreadStart.UseVisualStyleBackColor = true;
            this.buttonThreadStart.Click += new System.EventHandler(this.buttonThreadStart_Click);
            // 
            // labelThreadTest
            // 
            this.labelThreadTest.AutoSize = true;
            this.labelThreadTest.Location = new System.Drawing.Point(174, 41);
            this.labelThreadTest.Name = "labelThreadTest";
            this.labelThreadTest.Size = new System.Drawing.Size(70, 12);
            this.labelThreadTest.TabIndex = 4;
            this.labelThreadTest.Text = "ThreadTest";
            // 
            // buttonThreadEnd
            // 
            this.buttonThreadEnd.Location = new System.Drawing.Point(93, 41);
            this.buttonThreadEnd.Name = "buttonThreadEnd";
            this.buttonThreadEnd.Size = new System.Drawing.Size(75, 23);
            this.buttonThreadEnd.TabIndex = 5;
            this.buttonThreadEnd.Text = "ThreadEnd";
            this.buttonThreadEnd.UseVisualStyleBackColor = true;
            this.buttonThreadEnd.Click += new System.EventHandler(this.buttonThreadEnd_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(438, 369);
            this.Controls.Add(this.buttonThreadEnd);
            this.Controls.Add(this.labelThreadTest);
            this.Controls.Add(this.buttonThreadStart);
            this.Controls.Add(this.labelTime);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Timer timerInterrupt;
        private System.Windows.Forms.Label labelTime;
        private System.Windows.Forms.Button buttonThreadStart;
        private System.Windows.Forms.Label labelThreadTest;
        private System.Windows.Forms.Button buttonThreadEnd;
    }
}

