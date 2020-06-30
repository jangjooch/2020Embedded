namespace _0626_HW_MP3_01
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
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.buttonPlay = new System.Windows.Forms.Button();
            this.buttonNext = new System.Windows.Forms.Button();
            this.buttonPrevious = new System.Windows.Forms.Button();
            this.buttonPause = new System.Windows.Forms.Button();
            this.buttonVolUp = new System.Windows.Forms.Button();
            this.buttonVolDown = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonPlay
            // 
            this.buttonPlay.Location = new System.Drawing.Point(93, 52);
            this.buttonPlay.Name = "buttonPlay";
            this.buttonPlay.Size = new System.Drawing.Size(75, 23);
            this.buttonPlay.TabIndex = 0;
            this.buttonPlay.Text = "Play";
            this.buttonPlay.UseVisualStyleBackColor = true;
            this.buttonPlay.Click += new System.EventHandler(this.MP3_Controller);
            // 
            // buttonNext
            // 
            this.buttonNext.Location = new System.Drawing.Point(93, 12);
            this.buttonNext.Name = "buttonNext";
            this.buttonNext.Size = new System.Drawing.Size(75, 23);
            this.buttonNext.TabIndex = 1;
            this.buttonNext.Text = "Next";
            this.buttonNext.UseVisualStyleBackColor = true;
            this.buttonNext.Click += new System.EventHandler(this.MP3_Controller);
            // 
            // buttonPrevious
            // 
            this.buttonPrevious.Location = new System.Drawing.Point(12, 12);
            this.buttonPrevious.Name = "buttonPrevious";
            this.buttonPrevious.Size = new System.Drawing.Size(75, 23);
            this.buttonPrevious.TabIndex = 2;
            this.buttonPrevious.Text = "Previous";
            this.buttonPrevious.UseVisualStyleBackColor = true;
            this.buttonPrevious.Click += new System.EventHandler(this.MP3_Controller);
            // 
            // buttonPause
            // 
            this.buttonPause.Location = new System.Drawing.Point(12, 52);
            this.buttonPause.Name = "buttonPause";
            this.buttonPause.Size = new System.Drawing.Size(75, 23);
            this.buttonPause.TabIndex = 3;
            this.buttonPause.Text = "Pause";
            this.buttonPause.UseVisualStyleBackColor = true;
            this.buttonPause.Click += new System.EventHandler(this.MP3_Controller);
            // 
            // buttonVolUp
            // 
            this.buttonVolUp.Location = new System.Drawing.Point(12, 95);
            this.buttonVolUp.Name = "buttonVolUp";
            this.buttonVolUp.Size = new System.Drawing.Size(75, 23);
            this.buttonVolUp.TabIndex = 4;
            this.buttonVolUp.Text = "Vol_Up";
            this.buttonVolUp.UseVisualStyleBackColor = true;
            this.buttonVolUp.Click += new System.EventHandler(this.MP3_Controller);
            // 
            // buttonVolDown
            // 
            this.buttonVolDown.Location = new System.Drawing.Point(93, 95);
            this.buttonVolDown.Name = "buttonVolDown";
            this.buttonVolDown.Size = new System.Drawing.Size(75, 23);
            this.buttonVolDown.TabIndex = 5;
            this.buttonVolDown.Text = "Vol_down";
            this.buttonVolDown.UseVisualStyleBackColor = true;
            this.buttonVolDown.Click += new System.EventHandler(this.MP3_Controller);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(292, 173);
            this.Controls.Add(this.buttonVolDown);
            this.Controls.Add(this.buttonVolUp);
            this.Controls.Add(this.buttonPause);
            this.Controls.Add(this.buttonPrevious);
            this.Controls.Add(this.buttonNext);
            this.Controls.Add(this.buttonPlay);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Button buttonPlay;
        private System.Windows.Forms.Button buttonNext;
        private System.Windows.Forms.Button buttonPrevious;
        private System.Windows.Forms.Button buttonPause;
        private System.Windows.Forms.Button buttonVolUp;
        private System.Windows.Forms.Button buttonVolDown;
    }
}

