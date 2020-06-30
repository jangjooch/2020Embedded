namespace _0629_Beginning03_Serial
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
            this.serialPortToAVR = new System.IO.Ports.SerialPort(this.components);
            this.comboBoxCOMPort = new System.Windows.Forms.ComboBox();
            this.textBoxBuadRate = new System.Windows.Forms.TextBox();
            this.buttonSerialOpen = new System.Windows.Forms.Button();
            this.buttonSerialClose = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.textBoxSendContent = new System.Windows.Forms.TextBox();
            this.richTextBoxReceived = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // comboBoxCOMPort
            // 
            this.comboBoxCOMPort.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxCOMPort.FormattingEnabled = true;
            this.comboBoxCOMPort.Location = new System.Drawing.Point(14, 24);
            this.comboBoxCOMPort.Name = "comboBoxCOMPort";
            this.comboBoxCOMPort.Size = new System.Drawing.Size(121, 20);
            this.comboBoxCOMPort.TabIndex = 0;
            // 
            // textBoxBuadRate
            // 
            this.textBoxBuadRate.Location = new System.Drawing.Point(141, 23);
            this.textBoxBuadRate.Name = "textBoxBuadRate";
            this.textBoxBuadRate.Size = new System.Drawing.Size(106, 21);
            this.textBoxBuadRate.TabIndex = 1;
            // 
            // buttonSerialOpen
            // 
            this.buttonSerialOpen.Location = new System.Drawing.Point(253, 21);
            this.buttonSerialOpen.Name = "buttonSerialOpen";
            this.buttonSerialOpen.Size = new System.Drawing.Size(75, 23);
            this.buttonSerialOpen.TabIndex = 2;
            this.buttonSerialOpen.Text = "OPEN";
            this.buttonSerialOpen.UseVisualStyleBackColor = true;
            // 
            // buttonSerialClose
            // 
            this.buttonSerialClose.Location = new System.Drawing.Point(334, 21);
            this.buttonSerialClose.Name = "buttonSerialClose";
            this.buttonSerialClose.Size = new System.Drawing.Size(75, 23);
            this.buttonSerialClose.TabIndex = 3;
            this.buttonSerialClose.Text = "CLOSE";
            this.buttonSerialClose.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "COM PORT";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(139, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(63, 12);
            this.label2.TabIndex = 5;
            this.label2.Text = "Buad Rate";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(14, 91);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(121, 23);
            this.button1.TabIndex = 6;
            this.button1.Text = "Send";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // textBoxSendContent
            // 
            this.textBoxSendContent.Location = new System.Drawing.Point(141, 93);
            this.textBoxSendContent.Name = "textBoxSendContent";
            this.textBoxSendContent.Size = new System.Drawing.Size(106, 21);
            this.textBoxSendContent.TabIndex = 7;
            // 
            // richTextBoxReceived
            // 
            this.richTextBoxReceived.Location = new System.Drawing.Point(14, 156);
            this.richTextBoxReceived.Name = "richTextBoxReceived";
            this.richTextBoxReceived.Size = new System.Drawing.Size(233, 143);
            this.richTextBoxReceived.TabIndex = 8;
            this.richTextBoxReceived.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(512, 311);
            this.Controls.Add(this.richTextBoxReceived);
            this.Controls.Add(this.textBoxSendContent);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonSerialClose);
            this.Controls.Add(this.buttonSerialOpen);
            this.Controls.Add(this.textBoxBuadRate);
            this.Controls.Add(this.comboBoxCOMPort);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPortToAVR;
        private System.Windows.Forms.ComboBox comboBoxCOMPort;
        private System.Windows.Forms.TextBox textBoxBuadRate;
        private System.Windows.Forms.Button buttonSerialOpen;
        private System.Windows.Forms.Button buttonSerialClose;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBoxSendContent;
        private System.Windows.Forms.RichTextBox richTextBoxReceived;
    }
}

