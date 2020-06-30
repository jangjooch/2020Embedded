namespace _0622_Form_Transmit
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
            this.buttonCallForm2 = new System.Windows.Forms.Button();
            this.textBoxChange = new System.Windows.Forms.TextBox();
            this.buttonSend = new System.Windows.Forms.Button();
            this.buttonCheck = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonCallForm2
            // 
            this.buttonCallForm2.Location = new System.Drawing.Point(12, 12);
            this.buttonCallForm2.Name = "buttonCallForm2";
            this.buttonCallForm2.Size = new System.Drawing.Size(75, 23);
            this.buttonCallForm2.TabIndex = 0;
            this.buttonCallForm2.Text = "CallForm2";
            this.buttonCallForm2.UseVisualStyleBackColor = true;
            this.buttonCallForm2.Click += new System.EventHandler(this.buttonCallForm2_Click);
            // 
            // textBoxChange
            // 
            this.textBoxChange.Location = new System.Drawing.Point(12, 41);
            this.textBoxChange.Name = "textBoxChange";
            this.textBoxChange.Size = new System.Drawing.Size(159, 21);
            this.textBoxChange.TabIndex = 1;
            // 
            // buttonSend
            // 
            this.buttonSend.Location = new System.Drawing.Point(12, 68);
            this.buttonSend.Name = "buttonSend";
            this.buttonSend.Size = new System.Drawing.Size(75, 23);
            this.buttonSend.TabIndex = 2;
            this.buttonSend.Text = "SendChange";
            this.buttonSend.UseVisualStyleBackColor = true;
            this.buttonSend.Click += new System.EventHandler(this.buttonSend_Click);
            // 
            // buttonCheck
            // 
            this.buttonCheck.Location = new System.Drawing.Point(12, 97);
            this.buttonCheck.Name = "buttonCheck";
            this.buttonCheck.Size = new System.Drawing.Size(75, 23);
            this.buttonCheck.TabIndex = 3;
            this.buttonCheck.Text = "Check";
            this.buttonCheck.UseVisualStyleBackColor = true;
            this.buttonCheck.Click += new System.EventHandler(this.buttonCheck_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(411, 228);
            this.Controls.Add(this.buttonCheck);
            this.Controls.Add(this.buttonSend);
            this.Controls.Add(this.textBoxChange);
            this.Controls.Add(this.buttonCallForm2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonCallForm2;
        private System.Windows.Forms.TextBox textBoxChange;
        private System.Windows.Forms.Button buttonSend;
        private System.Windows.Forms.Button buttonCheck;
    }
}

